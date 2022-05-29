cc = g++

src = $(wildcard src/*.cpp)
obj = $(patsubst src/%.cpp, build/%.o, $(src))
headers = $(wildcard inc/*.hpp)

o_args = -fpic -c
so_args = -shared
test_args = -ljynx -Lbuild

bin = "/usr/local/bin"
lib = "/usr/local/lib"
inc = "/usr/local/include"

so = libjynx.so
