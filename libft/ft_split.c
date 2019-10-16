#include "libft.h"
#include "test.h"

#define TESTCOUNT 7
#define MAX_WORDS 6

int main()
{
	char **ret;
	char **fwd_ret;
	char* tested_str[TESTCOUNT] = {"", ":" , ":1", "0:", ":1:", "0::2","0:1:2:3:4"};
	char* expected_splits[TESTCOUNT][MAX_WORDS] = {{NULL}, {NULL}, {"1",NULL}, {"0",NULL}, {"1","",NULL}, {"0","2", NULL}, {"0","1","2","3","4", NULL}};
	char** fwd_expected_splits;
	int tdx;
	int test_ok;
	tdx = 0;
	int tested = 0;
	int passed = 0;
	while(tdx < TESTCOUNT)
	{
		printf("Test %d, splitting \"%s\" ", tdx, tested_str[tdx]);
		ret = ft_split(tested_str[tdx], ':');
		tested++;
		test_ok = 1;
		fwd_expected_splits = expected_splits[tdx];
		fwd_ret = ret;
		printf("\n");
		while(test_ok && *fwd_expected_splits)
		{
			//printf("* comparing to \"%s\"\n", *fwd_expected_splits);
			if (ft_memcmp(*fwd_ret,*fwd_expected_splits,ft_strlen(*fwd_expected_splits)))
				test_ok = 0;
			fwd_ret++;
			fwd_expected_splits++;
		}
		if (!fwd_ret)
			test_ok = 0;
		if (test_ok)
		{
			printf("passed.\n");
			passed++;
		}
		else
		{
			printf("failed while splitting \"%s\".\n", tested_str[tdx]);
			int dwdx = 0;
			int nullreached = 0;
			while (dwdx < MAX_WORDS)
			{
				char* test_display;
				char* expected_display;

				if (!ret)
				{
					nullreached++;
					test_display = 0;
				}
				else
					test_display = *ret;
				if (!expected_splits[tdx][dwdx])
				{
					nullreached++;
					expected_display = 0;
				}
				else
					expected_display = expected_splits[tdx][dwdx];
				printf("[%d] expected \"%s\" obtained \"%s\"\n", dwdx, expected_display, test_display);
				if (nullreached >= 2)
					break;
				dwdx++;
				ret++;
			}
		}
		tdx++;
	}
	print_abstract(tested, passed);
}
