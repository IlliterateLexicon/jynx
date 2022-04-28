#include <jynx/jynx.hpp>

int main() {
	jynx.output.clear();
	
	jynx.output.color(255, 100, 0);
	jynx.output.print("Hello red");
	jynx.output.reset();
	
	jynx.input.waitfor(jynx.keys.ENTER);
}
