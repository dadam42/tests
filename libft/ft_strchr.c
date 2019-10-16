#include "libft.h"

#include "test.h"
#define	STRSCOUNT 4
#define CHARCOUNT 4

int main()
{
	int tested = 0;
	int passed = 0;

	char *teststrs[STRSCOUNT] = {"0123*56*10", "*0*", "0*0", ""};
	int testchar[CHARCOUNT] = {'*', 0, 42,  -20};
	
	char	*ret_orig, *ret_test;
	int strdx,cdx;

	strdx = 0;
	while (strdx < STRSCOUNT)
	{
		cdx = 0;
		while (cdx < CHARCOUNT)
		{
			printf("Test %d, %d ", strdx, cdx);
			tested++;
			ret_orig = strchr(teststrs[strdx], testchar[cdx]);
			ret_test = ft_strchr(teststrs[strdx], testchar[cdx]);
			if (ret_orig == ret_test)
			{
				printf("passed.\n");
				passed++;
			}
			else
			{
				printf("failed. ft_strchr says %s while strchr says %s.\n", ret_test, ret_orig);
				printf("Test tried to find %c in %s\n-\n", testchar[cdx], teststrs[strdx]);
			}
			cdx++;
		}
		strdx++;
	}
	print_abstract(tested, passed);

}
