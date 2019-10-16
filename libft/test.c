/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:58:36 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/10 17:46:53 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_abstract(unsigned int tested, unsigned int passed)
{
	printf("ABSTRACT : \nTested : %d\nPassed : %d\n\n", tested, passed);
}

void fill_buffer_with(char *buf, int len, char val)
{
	while (len-- > 0)
	{
		*buf = val;
		buf++;
	}
}

void printbuf(char *buf, size_t len)
{
	size_t idx =0;
	while(idx < len)
	{
		printf("%c", *(buf + idx));
		idx++;
	}
	printf("\n");
}

void inc_fill_buffer_from(char *buf, char firstval, size_t len)
{
	while (len-- > 0)
	{
		*buf = firstval;
		buf++;
		firstval++;
	}
}

int buffers_are_identical(char *a, char* b, size_t size)
{
	size_t idx;

	idx = 0;
	while (idx < size)
	{
		if (*(a + idx) != *(b + idx))
			return 0;
		idx++;
	}
	return 1;
}

void reset_buffers(char *a, char *b, size_t size)
{
	size_t idx = 0;

	while (idx < size - 1)
	{
		*(a + idx) = '0';
		*(b + idx) = '0';
		idx++;
	}
	*(a + idx) = 0;
	*(b + idx) = 0;
}
