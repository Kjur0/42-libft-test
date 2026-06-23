/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:24:53 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/23 23:17:38 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(memcmp, equal)
{
	const char		*str1 = "Hello, world!";
	const char		*str2 = "Hello, world!";
	const size_t	n = 14;

	const int		c_cmp = memcmp(str1, str2, n);
	const int		ft_cmp = ft_memcmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(memcmp, different)
{
	const char		*str1 = "Hello, world!";
	const char		*str2 = "Hello. World!";
	const size_t	n = 14;

	const int		c_cmp = memcmp(str1, str2, n);
	const int		ft_cmp = ft_memcmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(memcmp, zero_length)
{
	const char		*str1 = "Hello, world!";
	const char		*str2 = "Hello, World!";
	const size_t	n = 0;

	const int		c_cmp = memcmp(str1, str2, n);
	const int		ft_cmp = ft_memcmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(memcmp, null_char)
{
	const char		*str1 = "Hello\0world!";
	const char		*str2 = "Hello\0World!";
	const size_t	n = 13;

	const int		c_cmp = memcmp(str1, str2, n);
	const int		ft_cmp = ft_memcmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(memcmp, partial_length)
{
	const char		*str1 = "Hello, world!";
	const char		*str2 = "Hello, World.";
	const size_t	n = 5;

	const int		c_cmp = memcmp(str1, str2, n);
	const int		ft_cmp = ft_memcmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(memcmp, non_ascii)
{
	const char		*str1 = "Hello, \255world!";
	const char		*str2 = "Hello, world!";
	const size_t	n = 14;

	const int		c_cmp = memcmp(str1, str2, n);
	const int		ft_cmp = ft_memcmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(memcmpDeathTest, nullptr1)
{
	EXPECT_EXIT({
		const char		*str1 = nullptr;
		const char		*str2 = "Hi";
		const size_t	n = 2;

		ft_memcmp(str1, str2, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memcmpDeathTest, nullptr2)
{
	EXPECT_EXIT({
		const char		*str1 = "Hi";
		const char		*str2 = nullptr;
		const size_t	n = 2;

		ft_memcmp(str1, str2, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
