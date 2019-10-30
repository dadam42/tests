#include <stdlib.h>
#include "get_next_line.h"
int main(int ac, char** av)
{
	char *line;

	(void) ac;
	(void) av;
	if (ac < 1)
		return (0);
	return (get_next_line(atoi(av[1]), &line));
}
