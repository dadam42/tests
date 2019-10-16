#include "libft.h"
#include "test.h"

int main()
{
	int testchar = 0;
	int tested = 0;
	int passed = 0;

	while (testchar < 256)
	{
		tested++;
		if (ft_isdigit(testchar) == isdigit(testchar))
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
