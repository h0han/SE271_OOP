#include <stdio.h>
#include "coordinate.h"

int main(void) {
	struct coordinate coord;

	coord.x = 5;
	coord.y = 3;

	print_coordinate(&coord);

	return 0;
}
