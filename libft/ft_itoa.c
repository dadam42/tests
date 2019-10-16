#include "libft.h"
#include "test.h"
#include <limits.h>

#define TESTCOUNT 8

int main()
{
	char *ret;
	int tested_i[TESTCOUNT] = {0, 1, 3, 12, 25, -38, INT_MIN, INT_MAX};
	char* expected_return[TESTCOUNT] = {"0", "1", "3", "12", "25", "-38","-2147483648", "2147483647"};
	int tdx;
	tdx = 0;
	int tested = 0;
	int passed = 0;
	while(tdx < TESTCOUNT)
	{
		printf("Test %d, ft_itoa-ing %d \n", tdx, tested_i[tdx]);
		ret = ft_itoa(tested_i[tdx]);
		tested++;
		if (!ft_memcmp(ret, expected_return[tdx],ft_strlen(expected_return[tdx]) + 1))
		{
			printf("passed.\n");
			passed++;
		}
		else
		{
			printf("failed.\n");
			printf("ft_itoa says \"%s\" but \"%s\" expected.\n", ret, expected_return[tdx]);
		}
		tdx++;
	}
	print_abstract(tested, passed);
}
