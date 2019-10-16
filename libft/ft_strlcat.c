#include "libft.h"

#include "test.h"
#define SANDBOXSIZE 50
#define SRCCOUNT 4
#define BUFSIZECOUNT 6
#define DSTSIZECOUNT 6

int main()
{
	char *dst_test = malloc(SANDBOXSIZE * sizeof(char));
	char *dst_orig = malloc(SANDBOXSIZE * sizeof(char));
	size_t ret_orig, ret_test;
	int tested = 0;
	int passed = 0;

	char *src[SRCCOUNT] = {"0123456789012234567890123456789", "0123456789", "0", ""};
	size_t bufsize[BUFSIZECOUNT] = {48, 25, 5, 2, 1, 0};
	size_t dstsize[DSTSIZECOUNT] = {0,1,2,15,30,49};

	int sdx, bsdx,ddx;
	sdx = 0;
	while (sdx < SRCCOUNT)
	{
		bsdx = 0;
		while (bsdx < BUFSIZECOUNT)
		{
			ddx = 0;
			while (ddx < DSTSIZECOUNT)
			{
				printf("Test %d, %d, %d ", sdx, bsdx, ddx);
				tested++;
				fill_buffer_with(dst_test, SANDBOXSIZE, '_');
				fill_buffer_with(dst_orig, SANDBOXSIZE, '_');
				if (dstsize[ddx] > 0)
				{
					dst_test[ddx - 1] = '^';
					dst_orig[ddx - 1] = '^';
				}
				dst_test[ddx] = 0;
				dst_orig[ddx] = 0;


				ret_orig = strlcat(dst_orig, src[sdx], bufsize[bsdx]);

				ret_test = ft_strlcat(dst_test, src[sdx], bufsize[bsdx]);
				int idbuf = buffers_are_identical(dst_orig, dst_test, SANDBOXSIZE);
				if (idbuf && (ret_orig == ret_test))
				{
					printf("passed.\n-\n");
					passed++;
				}
				else
				{
					printf("failed while copying %s in %zu large buffer already filled by a %zu long string.\n", src[sdx], bufsize[bsdx], dstsize[ddx]);
					if (idbuf)
					{ 
						printf("Buffers are the same\n");
					}
					else
					{
						printf("strlcat\t\tmakes\t");
						printbuf(dst_orig, bufsize[bsdx]);
						printf("ft_strlcat\tmakes\t");
						printbuf(dst_test, bufsize[bsdx]);
					}
					if (ret_orig == ret_test)
					{
						printf("Returned values are ok.");
					}
					else
					{
						printf("strlcat says %zu and ft_strlcat says %zu.\n-\n", ret_orig, ret_test);
					}
				}
				ddx++;
			}
			bsdx++;
		}
		sdx++;
	}
	print_abstract(tested, passed);
}
