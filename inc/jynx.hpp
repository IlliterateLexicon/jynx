#pragma once

#include "input.hpp"
#include "output.hpp"
#include "cursor.hpp"
#include "termio.hpp"
#include "keys.hpp"
#include "config.hpp"

namespace Jynx {
	struct jynx {
		void echo();
	};
}

static Jynx::jynx jynx;
