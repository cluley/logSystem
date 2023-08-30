#include <iostream>

#include "logCommand.h"
#include "observe.h"

int main() {
	Subject observed;
	observed.addObserver(new fatalObserver);
	observed.addObserver(new errObserver);
	observed.addObserver(new warnObserver);

	observed.warning("Warning!");
	observed.error("Error!");
	observed.fatalError("Fatal Error!");

	return 0;
}