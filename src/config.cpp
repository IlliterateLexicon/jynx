#include "../inc/jynx.hpp"
#include <stdio.h> 
#include <filesystem> 

FILE *config;

void Jynx::Config::load() {
	config = fopen("$USER/jynx.conf", "w");	
	fclose(config);
}

__attribute__((constructor)) void init(void) { 
	Jynx::Config::load();
}
