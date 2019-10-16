#include "libft.h"

#include "test.h"
#define SANDBOXSIZE 50
#define SRCCOUNT 4
#define DSTSIZECOUNT 6

int main()
{
	char *dst_test = malloc(SANDBOXSIZE * sizeof(char));
	char *dst_orig = malloc(SANDBOXSIZE * sizeof(char));
	size_t ret_orig, ret_test;
	int tested = 0;
	int passed = 0;

	char *src[SRCCOUNT] = {"0123456789012234567890123456789", "0123456789", "0", ""};
	size_t dstsize[DSTSIZECOUNT] = {48, 25, 5, 2, 1, 0};

	int sdx, ddx;
	sdx = 0;
	while (sdx < SRCCOUNT)
	{
		ddx = 0;
		while (ddx < DSTSIZECOUNT)
		{
			printf("Test %d, %d ", sdx, ddx);
			tested++;
			fill_buffer_with(dst_test, SANDBOXSIZE, '_');
			fill_buffer_with(dst_orig, SANDBOXSIZE, '_');
			
			ret_orig = strlcpy(dst_orig, src[sdx], dstsize[ddx]);
			ret_test = ft_strlcpy(dst_test, src[sdx], dstsize[ddx]);
			
			if (buffers_are_identical(dst_orig, dst_test, SANDBOXSIZE) && (ret_orig == ret_test))
			{
				printf("passed.\n-\n");
				passed++;
			}
			else
			{
				printf("failed while copying %s in %zu large buffer.\n", src[sdx], dstsize[ddx]);
				printf("strlcpy\t\tmakes\t");
				printbuf(dst_orig, dstsize[ddx]);
				printf("ft_strlcpy\tmakes\t");
				printbuf(dst_test, dstsize[ddx]);
				printf("strlcpy says %zu and ft_strlcpy says %zu.\n-\n", ret_orig, ret_test);
			}
			ddx++;
		}
		sdx++;
	}
	print_abstract(tested, passed);
}
