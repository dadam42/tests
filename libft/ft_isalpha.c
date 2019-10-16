#include "../headers/libft.h"
#include "test.h"

int main()
{
	int testchar = -199;
	int tested = 0;
	int passed = 0;

	while (testchar < 300)
	{
		tested++;
		if (ft_isalpha(testchar) == isalpha(testchar))
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
