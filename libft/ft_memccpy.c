#include "libft.h"
#include "test.h"

#define BUFSIZE 50
#define CHARCOUNT 3
#define SIZECOUNT 3
#define POSCOUNT 3


int main()
{
	char dst_orig[BUFSIZE];
	char dst_test[BUFSIZE];
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
				fill_buffer_with(dst_orig, BUFSIZE, '*');
				fill_buffer_with(dst_test, BUFSIZE, '*');
				fill_buffer_with(src, BUFSIZE, '*');
				inc_fill_buffer_from(src, 'A', testsize[sdx]);
				src[testsize[sdx]] = 0;
				src[testposition[pdx]] = testchar[cdx];
				ret_orig = memccpy(dst_orig, src, testchar[cdx], testsize[sdx]);
				ret_test = ft_memccpy(dst_test, src, testchar[cdx], testsize[sdx]);
				if (buffers_are_identical(dst_orig, dst_test, BUFSIZE) && ((!ret_orig && !ret_test) || (ret_orig - dst_orig == ret_test - dst_test)))
				{
					printf("passed\n");
					passed++;
				}
				else
				{
					printf("failed with values : limit char %d at pos %d , limit size %d\n", testchar[cdx],testposition[pdx], testsize[sdx]);
					printf("src : \n");
					printbuf(src, BUFSIZE);
					printf("memccpy : \n");
					printbuf(dst_orig, BUFSIZE);
					printf("ft_memccpy : \n");
					printbuf(dst_test, BUFSIZE);
					printf("memccpy returned pos %ld \t ft_memccpy returned pos %ld \n\n", ret_orig - dst_orig, ret_test - dst_test);
				}
				pdx++;
			}
			sdx++;
		}
		cdx++;
	}
	print_abstract(tested, passed);

}
