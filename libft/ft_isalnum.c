#include "libft.h"
#include "test.h"

int main()
{
	int testchar = 0;
	int tested = 0;
	int passed = 0;

	while (testchar < 500)
	{
		tested++;
		if (ft_isalnum(testchar) == isalnum(testchar))
		{
			passed++;
		}
		else
		{
			printf("Test failed with int value %d\n", testchar);
		}
		testchar++;
	}
	print_abstract(tested, passed);
}
