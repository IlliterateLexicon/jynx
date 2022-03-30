#include <string>
#include <iostream>

#include "../inc/cursor.hpp"

std::string esc::operator()(bool print) {
	if ( print ) std::cout << esc;
	return esc;
}

namespace Jynx {
	std::string Cursor::operator()(bool state, bool print) {
		if ( state ) return Cursor::show(print);
		else return Cursor::hide(print);
	}

	std::string Cursor::move(int x, int y, bool print) {
		std::string esc = "\033[" + std::to_string(y) + ";" + std::to_string(x) + "H";
		
		if (print) std::cout << esc;
		return esc;
	}

	std::string Cursor::nudge(int x, int y, bool print) {
		std::string esc;
	
		if ( y >= 1 )  esc += "\033[" + std::to_string(y) + "A";
		if ( y <= -1 ) esc += "\033[" + std::to_string(y*-1) + "B";
		if ( x >= 1 )  esc += "\033[" + std::to_string(x) + "C";
		if ( x <= -1 ) esc += "\033[" + std::to_string(x*-1) + "D";
	
		if ( print ) std::cout << esc;
		return esc;
	}; 
}
