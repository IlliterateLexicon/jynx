#pragma once

#include <string>

namespace Jynx::Output {
	std::string clear(bool to_end = true, bool to_beg = true, bool move = true, bool print = true);
	std::string clearLine(bool to_end = true, bool to_beg = true, bool move = true, bool print = true);

	std::string setColor(int color);
}
