#include "libft.h"
#include "test.h"

#define TESTCOUNT 8

int main()
{
	char *str_test[TESTCOUNT] = {"","","0123456789", "0123456789", "0123456789", "0123456789", "0123456789", "0123456789"};
	int start_test[TESTCOUNT] = {0, 0,  0, 0, 1, 1, 1, 1 };
	size_t len_test[TESTCOUNT] = {0, 1, 0, 2, 3, 7, 9, 10};
	char *expected[TESTCOUNT] = {"", "", "", "01", "123", "1234567", "123456789", "123456789"};
	int tdx = 0;
	int tested = 0;
	int passed = 0;

	while (tdx < TESTCOUNT)
	{
		printf("Test %d ", tdx);
		tested++;
		char *ret = ft_substr(str_test[tdx], start_test[tdx], len_test[tdx]);
		printf ("\n");
		if (!ft_memcmp(expected[tdx], ret, ft_strlen(expected[tdx])))
		{
			printf(" passed.\n");
			passed++;
		}
		else
		{
			printf("failed trying to substring-ing from \"%s\" starting at %c(%u) with size %zu.\n", str_test[tdx], *(str_test[tdx] + start_test[tdx]), start_test[tdx], len_test[tdx]);
			printf("Expected \"%s\" but ft_substr says \"%s\"\n", expected[tdx], ret);
		}
		tdx++;
	}
	print_abstract(tested, passed);
}
