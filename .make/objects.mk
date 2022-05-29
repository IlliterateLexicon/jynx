build/%.o: src/%.cpp inc/%.hpp
	echo "Compiling '$<' -> '$@'"
	$(cc) $(o_args) $< -o $@

objects: build_dir $(obj) 
