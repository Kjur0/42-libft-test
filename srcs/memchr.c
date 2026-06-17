/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:24:53 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/17 16:03:45 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

#include "test.h"

SETUP_TEST(const char *test_str, int ch, int size)
{
	const char	*c = memchr(test_str, ch, size);
	const char	*ft = ft_memchr(test_str, ch, size);

	TEST(c == ft)
	TEST_FINAL(c == ft)
}

int	main(void)
{
	INIT_TESTS("memchr")

	TEST_CASE("aaaaa", 'a', 5);
	TEST_CASE("aaaaa", 'a', 0);
	TEST_CASE("aaaaa", 'b', 5);
	TEST_CASE("abc", 'c', 5);
	TEST_CASE("abcsadfasfda", 'f', 7);
	TEST_CASE("abcsadfasfda", 'f', 4);
	TEST_CASE("abcsadfasfda", 'f', 13);
	TESTS_RESULT
}
