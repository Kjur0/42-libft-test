/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:20:48 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/17 16:27:26 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <stdlib.h>

#include "test.h"

SETUP_TEST(char *str, int size) {
	char	*c;
	char	*ft;
	int		result;

	c = malloc(size);
	ft = malloc(size);
	memcpy(c, str, size);
	ft_memcpy(ft, str, size);
	result = memcmp(c, ft, size);
	TEST(!result)
	free(c);
	free(ft);
	TEST_FINAL(!result)
}

int	main(void)
{
	INIT_TESTS("memcpy")

	TEST_CASE("aaa", 4);
	TEST_CASE("aaaaaa", 2);
	TEST_CASE("aaaaaa", 5);
	TEST_CASE("aaabaa", 2);
	TEST_CASE("aaaaaa", 0);
	TESTS_RESULT
}
