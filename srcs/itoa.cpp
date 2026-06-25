/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 22:04:11 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:48:43 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

TEST(itoa, 0)
{
	const int	n = 0;

	char		*out = ft_itoa(n);

	ASSERT_NE(out, nullptr);
	ASSERT_STREQ(out, "0");

	free(out);
}

TEST(itoa, 42)
{
	const int	n = 42;

	char		*out = ft_itoa(n);

	ASSERT_NE(out, nullptr);
	ASSERT_STREQ(out, "42");

	free(out);
}

TEST(itoa, 123)
{
	const int	n = 123;

	char		*out = ft_itoa(n);

	ASSERT_NE(out, nullptr);
	ASSERT_STREQ(out, "123");

	free(out);
}

TEST(itoa, neg42)
{
	const int	n = -42;

	char		*out = ft_itoa(n);

	ASSERT_NE(out, nullptr);
	ASSERT_STREQ(out, "-42");

	free(out);
}

TEST(itoa, int_min)
{
	const int	n = -2147483648;

	char		*out = ft_itoa(n);

	ASSERT_NE(out, nullptr);
	ASSERT_STREQ(out, "-2147483648");

	free(out);
}

TEST(itoa, int_max)
{
	const int	n = 2147483647;

	char		*out = ft_itoa(n);

	ASSERT_NE(out, nullptr);
	ASSERT_STREQ(out, "2147483647");

	free(out);
}
