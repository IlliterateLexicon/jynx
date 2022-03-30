# THE MAKE FILE FOR JYNX

CC = g++

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, bin/%.o, $(SRC))

OLD = .dev/old
TEST = .dev/testing

INSTALL = /usr/lib/libjynx.so

bin/libjynx.so: $(OBJ) 
	echo 'Compiling "bin/*.o" -> "bin/libjynx.so"'
	$(CC) -shared $^ -o $@
	
bin/%.o: src/%.cpp inc/%.hpp
	echo 'Compiling "$^" -> "$@"'
	$(CC) -fpic -c $< -o $@

install: bin/libjynx.so
	[ -d bin ] && true || mkdir bin
	[ -d .dev ] && true || mkdir .dev
	[ -d .dev/old/ ] && true || mkdir .dev/old
	[ -d /usr/include/jynx ] && true || sudo mkdir  /usr/include/jynx
	[ -d /usr/include/jynx ] && true || sudo mkdir /usr/include/jynx/*.hpp
	echo "Installing Shared Library"
	[ -f $(INSTALL) ] && sudo mv $(INSTALL) $(OLD)/old.libjynx.so || true
	[ -f $(OLD)/old.libjynx.so ] && rm -f $(OLD)/old.libjynx.so || true
	sudo cp bin/libjynx.so $(INSTALL)
	sudo cp bin/libjynx.so $(OLD)/old.libjynx.so
	echo "Installing Headers"
	[ -d $(OLD)/inc ] && true || mkdir "$(OLD)/inc"
	sudo rm -f $(OLD)/inc/*.hpp
	sudo mv /usr/include/jynx/*.hpp $(OLD)/inc || true
	sudo cp inc/*.hpp /usr/include/jynx
	sudo ldconfig

$(TEST)/test: bin/libjynx.so $(TEST)/main.cpp
	echo 'Compiling "test"'
	$(CC) $(TEST)/main.cpp -o $(TEST)/test -L bin/ -ljynx

test: $(TEST)/test
	echo -e '\033[7m TEST START \033[0m'
	$(TEST)/./test
	echo -e '\033[7m  TEST END  \033[0m'

clean:
	rm -f bin/*.o bin/*.so $(TEST)/test

.SILENT: 
