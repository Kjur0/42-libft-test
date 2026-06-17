/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:02:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/17 16:01:48 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ctype.h>

#include "test.h"

SETUP_TEST(int a)
{
	const int	c = isprint(a);
	const int	ft = ft_isprint(a);

	TEST((c && ft) || (!c && !ft))
	TEST_FINAL((c && ft) || (!c && !ft))
}

int	main(void)
{
	INIT_TESTS("isprint")

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
