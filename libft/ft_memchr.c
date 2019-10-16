#include "libft.h"
#include "test.h"

#define BUFSIZE 50
#define CHARCOUNT 3
#define SIZECOUNT 3
#define POSCOUNT 3


int main()
{
	char src[BUFSIZE];

	char testchar[CHARCOUNT] = {46, 41, -2};
	int testposition[POSCOUNT] = {3, 8, 15};
	int testsize[SIZECOUNT] = {1, 4, 10};
	char	*ret_orig, *ret_test;

	int cdx, pdx, sdx;
	int passed, tested;
	tested = 0;
	passed = 0;


	cdx = 0;
	while(cdx < CHARCOUNT)
	{
		sdx = 0;
		while (sdx < SIZECOUNT)
		{
			pdx = 0;
			while (pdx < POSCOUNT)
			{
				printf("Test %d, %d, %d ", cdx,sdx,pdx);
				tested++;
				fill_buffer_with(src, BUFSIZE, '*');
				inc_fill_buffer_from(src, 'A', testsize[sdx]);
				src[testsize[sdx]] = 0;
				src[testposition[pdx]] = testchar[cdx];
				ret_orig = memchr(src, testchar[cdx], testsize[sdx]);
				ret_test = ft_memchr(src, testchar[cdx], testsize[sdx]);
				if (((!ret_orig && !ret_test) || (ret_orig == ret_test )))
				{
					printf("passed\n");
					passed++;
				}
				else
				{
					printf("failed with values : limit char %d at pos %d , limit size %d\n", testchar[cdx],testposition[pdx], testsize[sdx]);
					printf("src : \n");
					printbuf(src, BUFSIZE);
					printf("memchr returned %s \t ft_memchr returned %s \n\n", ret_orig, ret_test);
				}
				pdx++;
			}
			sdx++;
		}
		cdx++;
	}
	print_abstract(tested, passed);

}
