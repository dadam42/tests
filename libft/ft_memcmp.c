#include "libft.h"

#include "test.h"
#define	STRSCOUNT1 5
#define STRSCOUNT2 6
#define LENCOUNT 6

int main()
{
	int tested = 0;
	int passed = 0;

	char *teststrs1[STRSCOUNT1] = {"0123*56*10", "0123*56*101", "*0*", "0*0", ""};
	char *teststrs2[STRSCOUNT2] = {"0123*56*10", "0123*56*103","0123*56*1","*0*", "0*0", ""};
	size_t  testlen[LENCOUNT] = {0, 4, 8, 10, 11, 15};
	int	ret_orig, ret_test;
	int strdx1, strdx2, ldx;

	strdx1 = 0;
	while (strdx1 < STRSCOUNT1)
	{
		strdx2 = 0;
		while (strdx2 < STRSCOUNT2)
		{
			ldx = 0;
			while (ldx < LENCOUNT)
			{
				printf("Test %d, %d, %d ", strdx1, strdx2, ldx);
				tested++;
				ret_orig = memcmp(teststrs1[strdx1], teststrs2[strdx2], testlen[ldx]);
				ret_test = ft_memcmp(teststrs1[strdx1], teststrs2[strdx2], testlen[ldx]);
				if (ret_orig == ret_test)
				{
					printf("passed.\n");
					passed++;
				}
				else
				{
					printf("failed. ft_strchr says %d while strchr says %d.\n", ret_test, ret_orig);
					printf("Test tried to compare %s and %s over the first %zu chars\n-\n", teststrs1[strdx1], teststrs2[strdx2], testlen[ldx]);
				}
				ldx++;
			}
			strdx2++;
		}
		strdx1++;
	}
	print_abstract(tested, passed);

}
