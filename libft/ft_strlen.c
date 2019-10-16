#include "libft.h"
#include "test.h"

#define BUFSIZE 50
#define CHARCOUNT 3
#define SIZECOUNT 3
#define POSCOUNT 3


int main()
{
	char src[BUFSIZE];

	int testsize[SIZECOUNT] = {1, 0, 10};
	size_t	ret_orig, ret_test;

	int sdx;
	int passed, tested;
	tested = 0;
	passed = 0;


		sdx = 0;
		while (sdx < SIZECOUNT)
		{
				printf("Test %d ", sdx);
				tested++;
				fill_buffer_with(src, BUFSIZE, '*');
				inc_fill_buffer_from(src, 'A', testsize[sdx]);
				src[testsize[sdx]] = 0;
				ret_orig = strlen(src);
				ret_test = ft_strlen(src);
				if (ret_orig == ret_test )
				{
					printf("passed\n");
					passed++;
				}
				else
				{
					printf("failed with values : size %d\n", testsize[sdx]);
					printf("src : \n");
					printbuf(src, BUFSIZE);
					printf("memccpy returned %zu \t ft_memccpy returned %zu \n\n", ret_orig, ret_test);
				}
			sdx++;
		}
	print_abstract(tested, passed);

}
