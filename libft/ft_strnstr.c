#include "libft.h"

#include "test.h"

#define HAYSTACKCOUNT 2
#define NEEDLECOUNT 9
#define LENCOUNT 24

int main()
{
	char *haystack[HAYSTACKCOUNT] = {"", "012345678987654321"};
	char *needle[NEEDLECOUNT] = {"", "0", "1", "01", "321", "456", "012345678987654321", "43211", "#"};
	size_t len[LENCOUNT] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
	int hdx, ndx, ldx;
	char *ret_orig, *ret_test;
	int tested, passed;

	tested = 0;
	passed = 0;
	hdx = 0;
	while (hdx < HAYSTACKCOUNT)
	{
		ndx = 0;
		while (ndx < NEEDLECOUNT)
		{
			ldx = 0;
			while (ldx < LENCOUNT)
			{
				printf("Test %d, %d, %d ", hdx, ndx, ldx);
				ret_orig = strnstr(haystack[hdx], needle[ndx], len[ldx]);
				ret_test = ft_strnstr(haystack[hdx], needle[ndx], len[ldx]);
				tested++;

				if (ret_orig == ret_test)
				{
					printf("passed.\n");
					passed++;
				}
				else
				{
					printf("failed while haystack : %s needle : %s len : %zu.\n", haystack[hdx], needle[ndx], len[ldx]);
					printf("strnstr says %s\n",ret_orig);
					printf("ft_strnstr says %s\n", ret_test);
				}

				ldx++;
			}
			ndx++;
		}
		hdx++;
	}
	print_abstract(tested, passed);
}
