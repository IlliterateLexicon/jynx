#include <iostream>

#include "../inc/output.hpp"
#include "../inc/cursor.hpp"
	
Jynx::Cursor cursor; //sets termio attributes
	
std::string text_attr::operator()(bool value, bool print) {
	if ( print ) {
		if (value) std::cout << "\033[" + std::to_string(on) + "m"; else std::cout << "\033[" + std::to_string(off) + "m";
	}
	if (value) return "\033[" + std::to_string(on) + "m"; else return "\033[" + std::to_string(off) + "m";
}

namespace Jynx {
	void Output::print(std::string text, int x, int y) {
		cursor.move(x, y);
		std::cout << text;
	}

	//Text Attributes
	std::string Output::reset(bool print) {
		if (print) std::cout << "\033[0m\033[39m\033[49m";
		return "\033[0m\033[39m\033[49m";
	}
	
	// Colors
	std::string Output::color(int r, int g, int b, int asni, bool print) {
		std::string c24bit = "\033[38;2;"\
			+ std::to_string(r) + ";"\
			+ std::to_string(g) + ";"\
			+ std::to_string(b) + "m";

		if (print) std::cout << c24bit;
		return c24bit;
	}

	std::string Output::color(int hex, int ansi, bool print) {
		int r, g, b;
		r = (hex >> (8*2)) & 0xff; 
		g = (hex >> (8*1)) & 0xff; 
		b = (hex >> (8*0)) & 0xff; 

		std::string c24bit = "\033[38;2;"\
			+ std::to_string(r) + ";"\
			+ std::to_string(g) + ";"\
			+ std::to_string(b) + "m";
		
		return c24bit; 
	}
}

