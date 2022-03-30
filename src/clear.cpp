#include <string>
#include <iostream>

#include "../inc/clear.hpp"

namespace Jynx {
	std::string Clear::operator()(bool to_end, bool to_beg, bool move, bool print) {
		std::string esc;
		if ( to_end ) { esc += "\033[0J"; }
		if ( to_beg ) { esc += "\033[1J"; }
		if ( move ) { esc += "\033[1;1H"; }

		if (print) { std::cout << esc; }
		return esc;
	}

	std::string Clear::line(bool to_end, bool to_beg, bool move, bool print) {
		std::string esc;
		if ( to_end ) { esc += "\033[0K"; }
		if ( to_beg ) { esc += "\033[1K"; }
		if ( move ) { esc += "\033[1000D"; }

		if (print) { std::cout << esc; }
		return esc;
	}
}
