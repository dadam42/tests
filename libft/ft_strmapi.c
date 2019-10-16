#include "test.h"
#include "libft.h"
#define TESTCOUNT 3

char  FuNnY(unsigned int i, char c)
{
	if (i % 2 == 0 && ft_isalpha(c))
		return (ft_toupper(c));
	if (i % 2 == 1 && ft_isalpha(c))
		return (ft_tolower(c));
	return (c);
}

int main()
{
	char *str_test[TESTCOUNT] = {"", "funny", "0123456789funny"};
	char *expected[TESTCOUNT] = {"",  "FuNnY", "0123456789FuNnY"};

	int tested = 0;
	int passed = 0;
	int tdx = 0;

	while (tdx < TESTCOUNT)
	{
		char *ret = ft_strmapi(str_test[tdx], FuNnY);
		printf("Test %d ", tdx);
		tested++;
		if (ft_memcmp(expected[tdx],ret, ft_strlen(expected[tdx])) + 1)
		{
			printf("passed.\n");
			passed++;
		}
		else
		{
			printf("failed mapping FuNnY on %s.\n", str_test[tdx]);
			printf("Expected \"%s\" but ft_strtrim says \"%s\"\n", expected[tdx], ret);
		}
		tdx++;
	}
	print_abstract(tested, passed);
}
