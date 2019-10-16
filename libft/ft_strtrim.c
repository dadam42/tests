#include "test.h"
#include "libft.h"

#define TESTCOUNT 6 

int main()
{
	char * str_test[TESTCOUNT] = {"", "012345Who's th3 Best?1235498", "012345Who's th3 Best?1235498", "lorem \n ipsum \t dolor \n sit \t amet","012314564876512654", "0123654789c6549871123"};
	char * set_test[TESTCOUNT] = {"", "", "0123456789", "\t\n ", "0123456789", "0123456789"};
	char * expected[TESTCOUNT] = {"",  "012345Who's th3 Best?1235498", "Who's th3 Best?", "lorem \n ipsum \t dolor \n sit \t amet", "", "c"};
	int tested = 0;
	int passed = 0;
	int tdx = 0;

	while (tdx < TESTCOUNT)
	{
		char *ret = ft_strtrim(str_test[tdx], set_test[tdx]);
		printf("Test %d ", tdx);
		tested++;
		if (!ft_memcmp(expected[tdx],ret, ft_strlen(expected[tdx]) + 1))
		{
			printf("passed.\n");
			passed++;
		}
		else
		{
			printf("failed trimming %s in %s.\n", set_test[tdx], str_test[tdx]);
			printf("Expected \"%s\" but ft_strtrim says \"%s\"\n", expected[tdx], ret);
		}
		tdx++;
	}
	print_abstract(tested, passed);
}
