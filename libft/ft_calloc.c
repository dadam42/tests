#include "libft.h"

#include "test.h"

#define COUNTCOUNT 6
#define SIZECOUNT 7

int main()
{
	size_t size[SIZECOUNT] = {0,1,2,3,4,5,10};
	size_t count[COUNTCOUNT] = {0,10,12,20,50,1000};
	
	int sdx, cdx;
	int tested = 0;
	int passed = 0;
	
	char *ret_orig;
	char *ret_test;
	sdx = 0;
	while (sdx < SIZECOUNT)
	{
		cdx = 0;
		while (cdx < COUNTCOUNT)
		{
			printf("Test %d, %d ", sdx, cdx);
			tested++;
			ret_orig = calloc(count[cdx], size[sdx]);
			ret_test = ft_calloc(count[cdx], size[sdx]);

			if (buffers_are_identical(ret_orig, ret_test, size[sdx]*count[cdx]))
			{
				printf("passed.\n");
				passed++;
			}
			else
			{
				printf("failed with count = %zu and size = %zu", count[cdx], size[sdx]);
			}
			cdx++;
		}
		sdx++;
	}
	print_abstract(tested, passed);
}
