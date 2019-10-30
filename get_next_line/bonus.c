#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#define MAXFD 6
int main(int ac, char **av)
{
	int fd[MAXFD + 1];
	int fddx;
	int fddest;
	int file_count;
	char *line;
	int more_to_read;
	int last_gnl_ret[MAXFD];

	if (ac < 4 || ac > MAXFD + 2)
		return (-1);
	fddx = 0;
	fddest = open(av[1], O_WRONLY | O_CREAT);
	if (fddest > 0)
	{
		printf("dest file opened.\n");
	}
	else
		printf("dest file could not be opened. \n");
	while (fddx <= MAXFD)
		fd[fddx++] = -1;
	fddx = 0;
	while (fddx < MAXFD)
		last_gnl_ret[fddx++] = 1;
	file_count = ac - 2;
	fddx = 0;
	while (fddx < file_count)
	{
		fd[fddx] = open(av[fddx + 2], O_RDONLY);
		fddx++;
	}
	more_to_read = 1;
	while (more_to_read)
	{
		more_to_read = 0;

		fddx = 0;
		while (fddx < file_count)
		{
			if ((last_gnl_ret[fddx] && (last_gnl_ret[fddx] =get_next_line(fd[fddx], &line))))
				{
					dprintf(fddest, "%s\n", line);
					more_to_read = 1;
				}
				fddx++;
		}
	}
	close(fddest);
	fddx = 0;
	while (fddx < MAXFD)
		close(fd[fddx++]);
	return (1);
}
