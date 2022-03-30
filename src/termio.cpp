#include "../inc/termio.hpp"

#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>

termios NEOTERM_TERMIO_SAVE; 

namespace Jynx {
	bool Termio::attr::operator()() {
		struct termios term;
		tcgetattr(STDIN_FILENO, &term);
		
		switch(mode) {
			case 'i':
				if (term.c_iflag & attr) { return true; }
			case 'o':
				if (term.c_oflag & attr) { return true; }
			case 'c':
				if (term.c_cflag & attr) { return true; }
			case 'l':
				if (term.c_lflag & attr) { return true; }
		}

		return false;
	}

	void Termio::attr::operator=(bool flag) {
		termios term;
		tcgetattr(STDIN_FILENO, &term);

		if ( !flag ) {
			switch(mode) {
				case 'i': term.c_iflag = term.c_iflag & ~attr;
				case 'o': term.c_oflag = term.c_oflag & ~attr;
				case 'c': term.c_cflag = term.c_cflag & ~attr;
				case 'l': term.c_lflag = term.c_lflag & ~attr;
			}
		} else {
			switch(mode) {
				case 'i': term.c_iflag = term.c_iflag | attr;
				case 'o': term.c_oflag = term.c_oflag | attr;
				case 'c': term.c_cflag = term.c_cflag | attr;
				case 'l': term.c_lflag = term.c_lflag | attr;
			}
		}

		tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
	}

	char Termio::cc::operator()() {
		struct termios term;
		tcgetattr(STDIN_FILENO, &term);
		return term.c_cc[attr];
	}

	void Termio::cc::operator=(char new_char) {
		struct termios term;
		tcgetattr(STDIN_FILENO, &term);
		term.c_cc[attr] = new_char;
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
	}
}
