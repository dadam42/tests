#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char *line;
	int ret;

	int fdlog = open("test_stdin.log", O_WRONLY | O_CREAT);
	while((ret = get_next_line(0,&line)) > 0)
	{
		dprintf(fdlog, "%s\n", line);		
	}
	if (ret != 0)
	{
		dprintf(fdlog,"ERROR\n");
	}
	close(fdlog);
	/*char buffer[32];
	int rc = read(0, buffer, 31);
	buffer[31]=0;
	dprintf(fdlog, "[%d]%s", rc, buffer);
	close(fdlog);*/
	return (0);
}
