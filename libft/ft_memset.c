/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:02:03 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/12 10:56:49 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "libft.h"
#define BUFFSIZE 17
#define TVALCOUNT 3
#define TLENCOUNT 4 

typedef struct test_values
{
	char *orig;
	char *buff;
	int val;
	size_t len;
} t_container;

int main()
{
	char test_buffer[BUFFSIZE];
	char orig_buffer[BUFFSIZE];

	int valtest[TVALCOUNT] = { 'b', 0, -1 };
	size_t lentest[TLENCOUNT] = { 0, 1, BUFFSIZE - 2, BUFFSIZE -1};

	int vdx;
	int ldx;
	int tried;
	int passed;

	vdx = -1;
	ldx = -1;
	tried = 0;
	passed = 0;
	while (++vdx < TVALCOUNT)
	{
		while (++ldx < TLENCOUNT)
		{
			reset_buffers(orig_buffer, test_buffer, BUFFSIZE);
			printf("before\n");
			printf("orig buffer : %s\ntest buffer : %s\n", orig_buffer, test_buffer);
			printf("testing with : val = %d \t len = %zu \n", valtest[vdx], lentest[ldx]);
			memset(orig_buffer, valtest[vdx], lentest[ldx]);
			ft_memset(test_buffer, valtest[vdx], lentest[ldx]);
			printf("after\n");
			printf("orig buffer : %s\ntest buffer : %s\n", orig_buffer, test_buffer);

			tried++;
			if (buffers_are_identical(test_buffer, orig_buffer, BUFFSIZE))
			{
				printf("Ok !\n");
				passed++;
			}
			else
				printf("Not Ok !\n");
		}
		ldx = -1;
	}
	print_abstract(tried, passed);
}
