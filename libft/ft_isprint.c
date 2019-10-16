#include "libft.h"
#include "test.h"

int main()
{
	int testchar = 0;
	int tested = 0;
	int passed = 0;
	int ret_origin;
	int ret_test;

	while (testchar < 500)
	{
		tested++;
		ret_test = ft_isprint(testchar);
		ret_origin = isprint(testchar);
		if (ret_test == ret_origin)
		{
			passed++;
		}
		else
		{
			printf("Test failed with int value %d - isprint says %d but ft_isprint says %d \n", testchar, ret_origin, ret_test);
		}
		testchar++;
	}
	print_abstract(tested, passed);
}
