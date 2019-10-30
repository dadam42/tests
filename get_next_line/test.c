#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define TESTCOUNT 5
#define MAXLINES 99

inline int next_fdx(int fdx, int maxfdx)
{
	return ((fdx+ 1) % maxfdx + 1); 
}

void exec(int dest_fd, int src_fd, int *error, char *filename)
{
	int gnl_ret;
	char *line;
	while ((gnl_ret = get_next_line(src_fd, &line)))
	{
		if (gnl_ret < 0)
		{dprintf(2, "An error occured while reading the file %s\n", filename);
			*error = 1;
			break;
		}
		dprintf(dest_fd, "%s\n", line);
		free(line);
	}
	if (!*error)
	{
		dprintf(dest_fd,"%s", line);
		free(line);
	}
}


int main(int argc, char** argv)
{
	int dest_fd;
	int src_fd;
	int error;
	char *error_msg[4] = {	"An error occured while gnl-ing the file %s.\n",
		"Could not open file %s for reading.\n",
		"Could not open file %s for writing. \n",
		"argc NOT OK !\n"}; 
	char *error_param[4];
	error_param[0] = argv[2];
	error_param[1] = argv[2];
	error_param[2] = argv[1];
	error_param[3] = NULL;
	error = 0;

	if (argc > 0)
	{
		if (argc <= 2)
			src_fd = STDIN_FILENO;
		else
		{			
			if ((src_fd = open(argv[2], O_RDONLY)) > 0)
			{
				dprintf(2,"exe> could open the src file %s\n", argv[2]);
			}
			else
			{
				error = 2;
			}
		}
		if (argc <= 1)
			dest_fd = STDOUT_FILENO;
		else
		{		
			if ((dest_fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC)) > 0)
			{
				dprintf(2,"exe> could open the dest file %s\n", argv[1]);
				fchmod(dest_fd,0600);
			}
			else
			{
				error = 3;
			}
		}
		if (!error)
		{
			dprintf(2,"BUFFER_SIZE = %d\n", BUFFER_SIZE);
			exec(dest_fd, src_fd, &error, argv[2]);
			close(dest_fd);
			close(src_fd);
		}
	}
	else
		error = 4;
	if (error)
		dprintf(2, error_msg[error - 1], error_param[error - 1]);
	return (error);
}
__attribute__((destructor)) void out()
{
	pid_t my_pid;
	char cmd[50];

	my_pid = getpid();
	dprintf(2, "___out of main___ [job %d] \n", my_pid);
	sprintf(cmd, "leaks %d", my_pid);
	system(cmd);
	getchar();
}
