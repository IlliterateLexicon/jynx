#include <string>
#include <iostream>
#include <termios.h>

#include "../inc/input.hpp"
#include "../inc/termio.hpp"
	
Jynx::Termio termio; //sets termio attributes
Jynx::Keys keys; //definitions of special keys

namespace Jynx {
	int Input::getkey(bool echo) {
		bool old_echo = termio.echo();

		termio.echo = echo;
		termio.isig = false;
		termio.icanon = false;

		std::string full_key = "";
		
		char c = getchar();
		full_key += c;

		if (c == keys.ESCAPE) {
			termio.vmin = 0;
		
			while (true) {
				c = getchar();
				if (c == -1) break;
				full_key += c;
			}
			
			termio.vmin = 1;

			ungetc('\0', stdin);
			getc(stdin);
		}

		termio.echo = old_echo;
		termio.isig = true;
		termio.icanon = true;

		int key = full_key[0];
		for (int i=1; i < full_key.length(); i++) {
			key = (key * 256 + full_key[i]);
		}

		return key;
	}

	int Input::waitfor(int key, bool echo) {
		while (Input::getkey() != key);
		return key;
	}
}
