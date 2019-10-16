#include "libft.h"
#include "test.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define TESTCOUNT 3

int main()
{
	char *fname[TESTCOUNT] = {"ft_putnbr_fd_a", "ft_putnbr_fd_b", "ft_putnbr_fd_c"};
	int put[TESTCOUNT] = {0, -2147483648, 2147483647};
	int tested = 0;
	int passed = 0;
	int tdx;

	tdx = 0;
	while (tdx < TESTCOUNT)
	{
		char *test_name = ft_strjoin(fname[tdx], ".test");
		char *test_orig = ft_strjoin(fname[tdx], ".orig");
		int skip_eof_test = 0;
		tested++;
		printf("Test %d \n", tdx);

		int test_fd = open(test_name, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
		int orig_fd = open(test_orig, O_RDONLY);
		ft_putnbr_fd(put[tdx], test_fd);
		close(test_fd);
		test_fd = open(test_name,O_RDONLY);
		
		char test_read;
		char orig_read;

		while (read(test_fd, &test_read, 1))
		{
			read(orig_fd, &orig_read, 1);
			printf("test > %c , orig > %c\n", test_read, orig_read);
			if (orig_read != test_read)
			{
				skip_eof_test = 1;
				break ;
			}
		}
		if (!skip_eof_test && !read(orig_fd, &orig_read, 1))
		{
			printf("passed.\n");
			passed++;
		}
		else
		{
			printf("orig > %c", orig_read);
			printf("failed. \n");
		}
		tdx++;
	}
	print_abstract(tested, passed);
}
