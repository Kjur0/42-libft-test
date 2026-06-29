/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:55:07 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/29 23:48:58 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <bsd/string.h>

TEST(strnstr, found)
{
	const char		*str = "Hello, world!";
	const char		*to_find = "world";
	const size_t	n = 13;

	const char		*c_res = strnstr(str, to_find, n);
	const char		*ft_res = ft_strnstr(str, to_find, n);

	ASSERT_EQ(c_res, ft_res);
}

TEST(strnstr, not_found)
{
	const char		*str = "Hello, world!";
	const char		*to_find = "42";
	const size_t	n = 13;

	const char		*c_res = strnstr(str, to_find, n);
	const char		*ft_res = ft_strnstr(str, to_find, n);

	ASSERT_EQ(c_res, ft_res);
}

TEST(strnstr, empty_str)
{
	const char		*str = "";
	const char		*to_find = "world";
	const size_t	n = 13;

	const char		*c_res = strnstr(str, to_find, n);
	const char		*ft_res = ft_strnstr(str, to_find, n);

	ASSERT_EQ(c_res, ft_res);
}

TEST(strnstr, empty_to_find)
{
	const char		*str = "Hello, world!";
	const char		*to_find = "";
	const size_t	n = 13;

	const char		*c_res = strnstr(str, to_find, n);
	const char		*ft_res = ft_strnstr(str, to_find, n);

	ASSERT_EQ(c_res, ft_res);
}

TEST(strnstr, both_empty)
{
	const char		*str = "";
	const char		*to_find = "";
	const size_t	n = 13;

	const char		*c_res = strnstr(str, to_find, n);
	const char		*ft_res = ft_strnstr(str, to_find, n);

	ASSERT_EQ(c_res, ft_res);
}

TEST(strnstr, length_limit)
{
	const char		*str = "Hello, world!";
	const char		*to_find = "world";
	const size_t	n = 5;

	const char		*c_res = strnstr(str, to_find, n);
	const char		*ft_res = ft_strnstr(str, to_find, n);

	ASSERT_EQ(c_res, ft_res);
}

TEST(strnstr, null_char)
{
	const char		*str = "Hello\0world!";
	const char		*to_find = "world";
	const size_t	n = 13;

	const char		*c_res = strnstr(str, to_find, n);
	const char		*ft_res = ft_strnstr(str, to_find, n);

	ASSERT_EQ(c_res, ft_res);
}

TEST(strnstr, to_find_longer_than_str)
{
	const char		*str = "Hello";
	const char		*to_find = "Hello, world!";
	const size_t	n = 13;

	const char		*c_res = strnstr(str, to_find, n);
	const char		*ft_res = ft_strnstr(str, to_find, n);

	ASSERT_EQ(c_res, ft_res);
}

TEST(strnstr, suffix_overflow)
{
	const char		*str = "Hello, world!";
	const char		*to_find = "ld!";
	const size_t	n = 5;

	const char		*c_res = strnstr(str, to_find, n);
	const char		*ft_res = ft_strnstr(str, to_find, n);

	ASSERT_EQ(c_res, ft_res);
}

TEST(strnstrDeathTest, nullptr_big)
{
	ASSERT_EXIT({
		const char		*str = nullptr;
		const char		*to_find = "world";
		const size_t	n = 13;

		ft_strnstr(str, to_find, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(strnstrDeathTest, nullptr_little)
{
	ASSERT_EXIT({
		const char		*str = "Hello, world!";
		const char		*to_find = nullptr;
		const size_t	n = 13;

		ft_strnstr(str, to_find, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
