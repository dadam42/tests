#include "libft.h"

#include "test.h"

#define STRCOUNT 4


int main()
{
	char *str[STRCOUNT] = {"", "q", "qw", "qwertyuioiufdsasdcfghjkiuytfdcfvbn"};
	
	char *ret_orig, *ret_test;
	int sdx;
	int tested = 0;
	int passed = 0;
	
	sdx = 0;
	while (sdx < STRCOUNT)
	{
		printf("Test %d ", sdx);
		tested++;
		ret_orig = strdup(str[sdx]);
		ret_test = strdup(str[sdx]);
		
		if (buffers_are_identical(ret_orig, ret_test, ft_strlen(str[sdx])))
		{
			printf("passed\n");
			passed++;
		}
		else
		{
			printf("failed while dup %s\n", str[sdx]);
		}
		sdx++;
	}
	print_abstract(tested, passed);
}
