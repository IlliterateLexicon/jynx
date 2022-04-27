cc = g++

src = $(wildcard src/*.cpp)
obj = $(patsubst src/%.cpp, build/%.o, $(src))
err = "/tmp/makefile_error"

help = "usage\n\
\0     make clean -> remove build directory\n\
\0   make install -> install and compile jynx\n\
\0 make uninstall -> uninstall jynx and all bindings\n\
\0    make python -> install and compile python bindings\
"

fail = \x1b[91mFail\x1b[39m\n
success = \x1b[92mDone\x1b[39m\n

check = 2> $(err) && echo -en "$(success)" || true
check_fail = && echo -e "$(fail)\nERROR: " && cat $(err) && echo -en "\nENTER TO QUIT" && read && exit 1 

so = libjynx.so 
install_location = /usr/lib/

default:
	echo -e $(help)

get_sudo:
	echo -e "Getting Sudo Perms..."
	sudo echo -en

build_checks:
	echo -e  "Starting Build Checks..."
	echo -en "Checking for build dir: "
	[ -d ./build ] && echo -en "$(success)" || true
	[ ! -d ./build ] && echo -en "$(fail)" && echo -en "Makeing dir './build': " && mkdir ./build && echo -en "$(success)" || true

build/%.o: src/%.cpp inc/%.hpp
	echo -en "Compiling $@: "
	echo -en "$(success)"
	$(cc) -fpic -c $< -o $@ 

build/$(so): $(obj)
	echo -en "Compiling $(so): "
	$(CC) -shared $< -o $@ && echo -en "$(success)" || echo -en "$(fail)"

install_checks:
	echo -en "Starting Install Checks...\n"
	echo -en "Checking for '/usr/include/jynx': "
	[ -d /usr/include/jynx ] && echo -en "$(success)" || true
	[ ! -d /usr/include/jynx ] && echo -en "$(fail)" && echo -en "Makeing dir '/usr/include/jynx': " && sudo mkdir "/usr/include/jynx" && echo -en "$(success)" || true

install: get_sudo build_checks build/$(so) install_checks
	echo -en "Installing...\n"
	echo -en "Installing $(so): " && sudo cp build/$(so) /usr/lib/ && echo -en "$(success)" && true
	echo -en "Installing headers: " && sudo cp ./inc/* /usr/include/jynx/ && echo -en "$(success)" || echo -en "Fail"
	echo -en "Configuring linker: " && sudo ldconfig && echo -en "$(success)"
	echo -en "Install of jynx was a success!\n"

uninstall:
	echo -en	

clean: get_sudo
	echo -en "Cleaning...\n"
	echo -en "Removeing build dir: "
	[ -d ./build ] && rm -dr ./build || true
	[ ! -d ./build ] && echo -en "$(success)" || echo -en "$(fail)"
	echo -en "  Removeing header dir: "
	[ -d /usr/include/jynx ] && sudo rm -dr  /usr/include/jynx || true
	[ ! -d /usr/include/jynx ] && echo -en "$(success)" || echo -en "$(fail)"
	echo -en "  Removeing shared object: "
	[ -f /usr/lib/$(so) ] && sudo rm /usr/lib/$(so) || true
	[ ! -f /usr/lib/$(so) ] && echo -en "$(success)" || echo -en "$(fail)"

python:
	echo -en

.SILENT:
