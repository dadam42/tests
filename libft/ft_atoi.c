#include "libft.h"

#include "test.h"

#define ARRAYCOUNT 13

int main()
{
	char *array[ARRAYCOUNT] = {"", "toto", "\t \r\n123", "\f\t \n-123", "0", "+0", "-0", "+-", "-+", "2147483647", "2147483648", "-2147183647", "-2147483648" };
	int tested = 0;
	int passed = 0;
	int adx;

	int ret_orig, ret_test;

	adx = 0;
	while (adx < ARRAYCOUNT)
	{
		tested++;
		printf ("Test %d ", adx);
		ret_orig = atoi(array[adx]);
		ret_test = ft_atoi(array[adx]);

		if (ret_orig == ret_test)
		{
			passed++;
			printf("passed.\n");
		}
		else
		{
			printf ("Failed processing %s\n", array[adx]);
			printf ("atoi returned %d\n", ret_orig);
			printf ("ft_atoi returned %d\n", ret_test);
		}
		adx++;
	}
	print_abstract(tested, passed);
}
