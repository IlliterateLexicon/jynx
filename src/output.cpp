#include <iostream>
#include <sys/ioctl.h>

#include "../inc/output.hpp"
#include "../inc/cursor.hpp"
	
	
std::string text_attr::operator()(bool value, bool print) {
	if ( print ) {
		if (value) std::cout << "\033[" + std::to_string(on) + "m"; else std::cout << "\033[" + std::to_string(off) + "m";
	}
	if (value) return "\033[" + std::to_string(on) + "m"; else return "\033[" + std::to_string(off) + "m";
}

namespace Jynx {
		void Output::print(std::string text, int x, int y) {
			Jynx::Cursor::move(x, y);
			std::cout << text;
		}

		//size
		int * Output::size() {
			struct winsize w; ioctl(0, TIOCGWINSZ, &w);
			
			static int size[2] = { w.ws_col, w.ws_row };
			return size;
		}

		int Output::width() {
			struct winsize w; ioctl(0, TIOCGWINSZ, &w);
			return w.ws_col;
		}

		int Output::height() {
			struct winsize w; ioctl(0, TIOCGWINSZ, &w);
			return w.ws_row;
		}

		//center	
		int * Output::center() {
			struct winsize w; ioctl(0, TIOCGWINSZ, &w);
			
			static int size[2] = { w.ws_col / 2, w.ws_row / 2 };
			return size;
		}

		int Output::centerWidth() {
			struct winsize w; ioctl(0, TIOCGWINSZ, &w);
			return w.ws_col / 2;
		}

		int Output::centerHeight() {
			struct winsize w; ioctl(0, TIOCGWINSZ, &w);
			return w.ws_row / 2;
		}

		//Text Attributes
		std::string Output::reset(bool print) {
			if (print) std::cout << "\033[0m\033[39m\033[49m";
			return "\033[0m\033[39m\033[49m";
		}
		
		// Colors
		std::string Output::color(int r, int g, int b, bool print) {
			std::string c24bit = "\033[38;2;"\
				+ std::to_string(r) + ";"\
				+ std::to_string(g) + ";"\
				+ std::to_string(b) + "m";

			if (print) std::cout << c24bit;
			return c24bit;
		}

		std::string Output::color(int hex, bool print) {
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

		std::string Output::clear(bool to_end, bool to_beg, bool move, bool print) {
			std::string esc;
			if ( to_end ) { esc += "\033[0J"; }
			if ( to_beg ) { esc += "\033[1J"; }                                     
			if ( move ) { esc += "\033[1;1H"; }
				
			if (print) { std::cout << esc; }
			return esc;	
		}

		std::string Output::clearLine(bool to_end, bool to_beg, bool move, bool print) {
			std::string esc;
			if ( to_end ) { esc += "\033[0K"; }
			if ( to_beg ) { esc += "\033[1K"; }
			if ( move ) { esc += "\033[1000D"; }
				 
			if (print) { std::cout << esc; }
			return esc;
		}
}

