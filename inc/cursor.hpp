#pragma once

#include <string>

struct esc {
	std::string esc;
	std::string operator()(bool print = true);
};

namespace Jynx {
	struct Cursor {
			esc show = {"\033[?25h"};
			esc hide = {"\033[?25l"};
			
			esc save = {"\033s"};
			esc load = {"\033u"};

			std::string move(int x, int y, bool print = true);
			std::string nudge(int x, int y, bool print = true);

			std::string operator()(bool state = true, bool print = true);
	};
}
