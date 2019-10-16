#include "libft.h"
#include "test.h"

#define SANDBOXSIZE 50
#define TESTCOUNT 3
#define TESTCOUNTSIZE 4


int main()
{
	char *sandboxtest = (char *) malloc(SANDBOXSIZE * sizeof(char));
	char *sandboxorig = (char *) malloc(SANDBOXSIZE * sizeof(char));
	char *sandboxtestcpy = (char *) malloc(SANDBOXSIZE * sizeof(char));
	char *sandboxorigcpy = (char *) malloc(SANDBOXSIZE * sizeof(char));


	size_t testsrc[TESTCOUNT][2] = {{0,20},{15,20},{25,20}};
	size_t testdst[TESTCOUNT][2] = {{25,10},{10,10},{0,10}};
	size_t testsize[TESTCOUNTSIZE] = {8,12,4,0};
	void *orig_ret, *test_ret;

	int ddx, sdx, sidx;
	int overlapping;

	int tested;
	int passed;
	tested = 0;
	passed = 0;
	ddx = 0;
	while (ddx < TESTCOUNT)
	{
		sdx = 0;
		while (sdx < TESTCOUNT)
		{
			sidx = 0;
			while (sidx < TESTCOUNTSIZE)
			{
				overlapping = 0;
				fill_buffer_with(sandboxtest, SANDBOXSIZE, '*');
				inc_fill_buffer_from(sandboxtest+testdst[ddx][0],'0',testdst[ddx][1]);
				inc_fill_buffer_from(sandboxtest+testsrc[sdx][0],'0',testsrc[sdx][1]);
				memcpy(sandboxtestcpy, sandboxtest, SANDBOXSIZE);
				fill_buffer_with(sandboxorig, SANDBOXSIZE, '*');
				inc_fill_buffer_from(sandboxorig+testdst[ddx][0],'0',testdst[ddx][1]);
				inc_fill_buffer_from(sandboxorig+testsrc[sdx][0],'0',testsrc[sdx][1]);
				memcpy(sandboxorigcpy, sandboxorigcpy, SANDBOXSIZE);

				orig_ret = memcpy(sandboxorig+testdst[ddx][0],sandboxorig+testsrc[sdx][0],testsize[sidx]);
				test_ret = ft_memcpy(sandboxtest+testdst[ddx][0], sandboxtest+testsrc[sdx][0],testsize[sidx]);
				tested++;
				printf("Test %d, %d, %d : ",ddx, sdx, sidx);
				if (testsrc[sdx][0] >= testdst[ddx][0] && testsrc[sdx][0] <= testdst[ddx][0] + testsize[sidx])
				{
					printf("left-overlapping, ");
					overlapping++;
				}
				else
					printf("not left-overlapping, ");
				if (testsrc[sdx][0] + testsize[sidx] >= testdst[ddx][0] && testsrc[sdx][0] <= testdst[ddx][0])
				{
					printf("right-overlapping.\n");
					overlapping++;
				}
				else
					printf("not right-overlapping.\n");

				if (overlapping || (buffers_are_identical(sandboxorig, sandboxtest, SANDBOXSIZE) && (orig_ret - test_ret == sandboxorig - sandboxtest)))
				{
					printf("passed\n");
					passed++;
				}
				else
				{
					printf("failed with size %zu :\nft_memcpy :\n", testsize[sidx]);
					printbuf(sandboxtestcpy, SANDBOXSIZE);
					printbuf(sandboxtest, SANDBOXSIZE);
					printf("memcopy :\n");
					printbuf(sandboxorigcpy, SANDBOXSIZE);
					printbuf(sandboxorig, SANDBOXSIZE);
					printf("delta ret : %ld, delta addr : %ld\n", orig_ret - test_ret, sandboxorig - sandboxtest);

				}

				sidx++;
			}
			sdx++;
		}
		ddx++;
	}
	printf("ABSTRACT\ntried : %d\npassed : %d\n\n", tested, passed);
}

