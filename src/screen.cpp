#include "../inc/screen.hpp"

#include <math.h>
#include <array>
#include <unistd.h>
#include <sys/ioctl.h>

namespace Jynx {
	int * Screen::Size::operator()() {
		static int size[2];

		struct winsize w;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

		size[0] = w.ws_col;
		size[1] = w.ws_row;

		return size;
	}

	int Screen::Size::width(){
		struct winsize w;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

		return w.ws_col;
	}

	int Screen::Size::height(){
		struct winsize w;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

		return w.ws_row;
	}
}
