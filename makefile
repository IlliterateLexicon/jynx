# THE MAKE FILE FOR JYNX

CC = g++

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, bin/%.o, $(SRC))

OLD = .dev/old
TEST = .dev/testing

INSTALL = /usr/lib/libjynx.so

bin/libjynx.so: $(OBJ) 
	[ -d bin ] || mkdir bin
	echo 'Compiling "bin/*.o" -> "bin/libjynx.so"'
	$(CC) -shared $^ -o $@
	
bin/%.o: src/%.cpp inc/%.hpp
	[ -d bin ] || mkdir bin
	echo 'Compiling "$^" -> "$@"'
	$(CC) -fpic -c $< -o $@

install: bin/libjynx.so
	[ -d .dev ] || mkdir .dev
	[ -d .dev/old/ ] || mkdir .dev/old
	[ -d /usr/include/jynx ] || sudo mkdir  /usr/include/jynx
	[ -d /usr/include/jynx ] || sudo mkdir /usr/include/jynx/*.hpp
	echo "Installing Shared Library"
	[ -f $(INSTALL) ] && sudo mv $(INSTALL) $(OLD)/old.libjynx.so
	[ -f $(OLD)/old.libjynx.so ] && rm -f $(OLD)/old.libjynx.so
	sudo cp bin/libjynx.so $(INSTALL)
	sudo cp bin/libjynx.so $(OLD)/old.libjynx.so
	echo "Installing Headers"
	[ -d $(OLD)/inc ] && true || mkdir "$(OLD)/inc"
	sudo rm -f $(OLD)/inc/*.hpp
	sudo mv /usr/include/jynx/*.hpp $(OLD)/inc || true
	sudo cp inc/*.hpp /usr/include/jynx
	sudo ldconfig

$(TEST)/main.cpp:
	[ -f $(TEST)/main.cpp ] || touch $(TEST)/main.cpp && echo -en "int main() {\n\treturn 0;\n}" > $(TEST)/main.cpp

$(TEST)/test: $(TEST)/main.cpp bin/libjynx.so
	echo 'Compiling "test"'
	[ -d $(TEST) ] || mkdir $(TEST)
	$(CC) $(TEST)/main.cpp -o $(TEST)/test -L bin/ -ljynx

test: $(TEST)/test
	echo -e '\033[7m TEST START \033[0m'
	$(TEST)/./test
	echo -e '\033[7m  TEST END  \033[0m'

clean:
	rm -f bin/*.o bin/*.so $(TEST)/test

.SILENT: 
