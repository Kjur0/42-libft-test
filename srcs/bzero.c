/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:24:53 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/17 16:07:06 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <libft.h>
#include <strings.h>
#include <string.h>

#include "test.h"

SETUP_TEST(char *test_str, int test_n)
{
	char	*ft;
	int		count;
	int		i;

	ft = strdup(test_str);
	ft_bzero(ft, test_n);
	count = 0;
	i = 0;
	while (i < test_n)
		count += ft[i++];
	TEST(count == 0)
	TEST_FINAL(count == 0)
}

int	main(void)
{
	INIT_TESTS("bzero")

	TEST_CASE("1", 1);
	TEST_CASE("12", 2);
	TEST_CASE("123", 3);
	TEST_CASE("1234", 4);
	TEST_CASE("12345", 5);
	TESTS_RESULT
}
