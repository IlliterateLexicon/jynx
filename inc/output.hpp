#pragma once

#include <string>
#include "input.hpp"
			
struct text_attr {
	int on, off;
	std::string operator()(bool value=true, bool print=true);
};

namespace Jynx {
	struct Output {
		static void print(std::string text, int x = 0,  int y = 0);

		static int * size();
		static int width();
		static int height();
		
		static int * center();
		static int centerWidth();
		static int centerHeight();

		std::string color(int r, int g, int b, bool print = true);
		std::string color(int hex, bool print = true);

		text_attr bold = {1, 22};
		text_attr faint = {1, 22};
		text_attr italic = {1, 22};
		text_attr underline = {1, 22};
		text_attr blink = {1, 22};
		text_attr reverse = {1, 22};
		text_attr strike = {1, 22};
		std::string reset(bool print = true);

		std::string clear(bool to_end = true, bool to_beg = true, bool move = true, bool print = true);
		std::string clearLine(bool to_end = true, bool to_beg = true, bool move = true, bool print = true);
	};
}
