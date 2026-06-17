/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:24:53 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/17 16:05:00 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

#include "test.h"

SETUP_TEST(const char *a, const char *b, int size)
{
	const int	c = memcmp(a, b, size);
	const int	ft = ft_memcmp(a, b, size);

	TEST(c == ft)
	TEST_FINAL(c == ft)
}

int	main(void)
{
	INIT_TESTS("memcmp")

	TEST_CASE("a", "a", 2);
	TEST_CASE("ab", "a", 2);
	TEST_CASE("a", "ab", 2);
	TEST_CASE("aaa", "aab", 2);
	TEST_CASE("aaa", "aab", 4);
	TEST_CASE("aa", "a", 2);
	TEST_CASE("ab", "aa", 2);
	TEST_CASE("aa", "ab", 2);
	TEST_CASE("a", "a", 0);
	TESTS_RESULT
}
