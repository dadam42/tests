/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:43:19 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/09 15:26:31 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DA42_TEST_H
# define DA42_TEST_H

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int	buffers_are_identical(char *a, char *b, size_t size);
void	reset_buffers(char *a, char *b, size_t size);
void	fill_buffer_with(char *buf, int len, char val);
void	printbuf(char *buf, size_t len);
void inc_fill_buffer_from(char *buf, char firstval, size_t len);
void	print_abstract(unsigned int tested, unsigned int passed);
#endif
