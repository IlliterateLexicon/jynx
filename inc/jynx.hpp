#pragma once

#include <string>

#include "cursor.hpp"
#include "clear.hpp"
#include "termio.hpp"
#include "input.hpp"
#include "output.hpp"

namespace Jynx {
	struct jynx {
		Cursor cursor;
		Clear clear;
		Termio termio;
		Input input;
		Keys keys;
		Output output;
	};
}

static Jynx::jynx jynx;
