/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:57:21 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/17 15:46:46 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <libft.h>
#include <stdlib.h>

#include "test.h"

SETUP_TEST(char *test_str) {
	const int	c = atoi(test_str);
	const int	ft = ft_atoi(test_str);

	TEST_PRINT(c == ft, "\tlibc: %d\n\tlibft: %d\n\n", c, ft)
	TEST_FINAL(c == ft)
}

int	main(void)
{
	INIT_TESTS("atoi")

	TEST_CASE("0");
	TEST_CASE("1");
	TEST_CASE("2147483647");
	TEST_CASE("2147483648");
	TEST_CASE("21474836470");
	TEST_CASE("-1");
	TEST_CASE("-2147483648");
	TEST_CASE("-2147483649");
	TEST_CASE("-21474836480");
	TESTS_RESULT
}
