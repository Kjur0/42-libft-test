/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:51:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/17 16:20:00 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

#include "test.h"

SETUP_TEST(size_t a, size_t b)
{
	const char	*c = calloc(a, b);
	const char	*ft = ft_calloc(a, b);

	TEST((c == 0 && ft == 0) || (c != 0 && ft != 0 && *c == *ft))
	if (c != 0)
		free((int *)c);
	if (ft != 0)
		free((int *)ft);
	TEST_FINAL((c == 0 && ft == 0) || (c != 0 && ft != 0))
}

int	main(void)
{
	INIT_TESTS("calloc")

	TEST_CASE(1, 1);
	TEST_CASE(0, 0);
	TEST_CASE(0, 3);
	TEST_CASE(4, 0);
	TEST_CASE(__SIZE_MAX__, 2);
	TESTS_RESULT
}
