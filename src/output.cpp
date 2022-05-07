#include "string"
#include "iostream"
#include "../inc/jynx.hpp"

namespace Jynx::Output {
	std::string clear(bool to_end, bool to_beg, bool move, bool print) {
		std::string esc;

		if ( to_end ) { esc += "\x1b[0J"; };
		if ( to_beg ) { esc += "\x1b[1J"; };
		if ( move ) { esc += "\x1b[1;1H"; };
		if ( print )  { std::cout << esc << std::flush; };

		return esc;
	}
	
	std::string clearLine(bool to_end, bool to_beg, bool move, bool print) {
		std::string esc;

		if ( to_end ) { esc += "\x1b[0K"; };
		if ( to_beg ) { esc += "\x1b[1K"; };
		if ( move ) { esc += "\x1b[1000D"; }; 
		if ( print )  { std::cout << esc << std::flush; };

		return esc;
	}
}
