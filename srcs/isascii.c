/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:02:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/17 15:58:53 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ctype.h>

#include "test.h"

SETUP_TEST(int a)
{
	const int	c = isascii(a);
	const int	ft = ft_isascii(a);

	TEST((c && ft) || (!c && !ft))
	TEST_FINAL((c && ft) || (!c && !ft))
}

int	main(void)
{
	INIT_TESTS("isascii")

	TEST_CASE(' ');
	TEST_CASE('1');
	TEST_CASE('a');
	TEST_CASE('A');
	TEST_CASE('-');
	TEST_CASE(0);
	TEST_CASE('\r');
	TEST_CASE(255);
	TESTS_RESULT
}
