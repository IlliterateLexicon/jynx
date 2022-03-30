#pragma once

#include <string>

namespace Jynx {
	struct Clear {
		std::string operator()(bool to_end = true, bool to_beg = true, bool move = true, bool print = true);
		std::string line(bool to_end = true, bool to_beg = true, bool move = true, bool print = true);
	};
}
