/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:41:05 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/12 10:16:39 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "libft.h"
#define TEST_COUNT 4
#define BUFSIZE 20

int main()
{
	char testbuf[BUFSIZE + 1];
	char origbuf[BUFSIZE + 1];
	testbuf[BUFSIZE] = 0;
	origbuf[BUFSIZE] = 0;

	int tdx = 0;
	int passed = TEST_COUNT;

	size_t testval[TEST_COUNT] = {8, 1, 0, BUFSIZE};

	while (tdx < TEST_COUNT)
	{
		fill_buffer_with(testbuf, BUFSIZE, 'x');
		fill_buffer_with(origbuf, BUFSIZE, 'x');
		bzero(origbuf, testval[tdx]);
		ft_bzero(testbuf, testval[tdx]);
		if (!buffers_are_identical(origbuf, testbuf, BUFSIZE))
		{
			printf("test %d failed with value %zu\n", tdx, testval[tdx]);
			printbuf(origbuf,BUFSIZE);
			printf("\n");
			printbuf(testbuf, BUFSIZE);
			printf("\n");
			passed--;
		}
		else
		{
			printf("test %d passed with value %zu\n", tdx, testval[tdx]);
		}
		tdx++;
	}
	printf("ABSTRACT : \n");
	printf("tried : %d\npassed : %d\n", TEST_COUNT, passed);
}
