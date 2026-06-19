/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:55:07 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 19:32:44 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <bsd/string.h>

TEST(strnstr, found) {
	const char	str[] = "Hello, world!";
	const char	to_find[] = "world";
	size_t		n = 13;

	char*		c_res = strnstr(str, to_find, n);
	char*		ft_res = ft_strnstr(str, to_find, n);

	EXPECT_EQ(c_res, ft_res);
}

TEST(strnstr, not_found) {
	const char	str[] = "Hello, world!";
	const char	to_find[] = "42";
	size_t		n = 13;

	char*		c_res = strnstr(str, to_find, n);
	char*		ft_res = ft_strnstr(str, to_find, n);

	EXPECT_EQ(c_res, ft_res);
}

TEST(strnstr, empty_to_find) {
	const char	str[] = "Hello, world!";
	const char	to_find[] = "";
	size_t		n = 13;

	char*		c_res = strnstr(str, to_find, n);
	char*		ft_res = ft_strnstr(str, to_find, n);

	EXPECT_EQ(c_res, ft_res);
}

TEST(strnstr, length_limit) {
	const char	str[] = "Hello, world!";
	const char	to_find[] = "world";
	size_t		n = 5;

	char*		c_res = strnstr(str, to_find, n);
	char*		ft_res = ft_strnstr(str, to_find, n);

	EXPECT_EQ(c_res, ft_res);
}

TEST(strnstr, null_char) {
	const char	str[] = "Hello\0world!";
	const char	to_find[] = "world";
	size_t		n = 13;

	char*		c_res = strnstr(str, to_find, n);
	char*		ft_res = ft_strnstr(str, to_find, n);

	EXPECT_EQ(c_res, ft_res);
}

TEST(strnstr, to_find_longer_than_str) {
	const char	str[] = "Hello";
	const char	to_find[] = "Hello, world!";
	size_t		n = 13;

	char*		c_res = strnstr(str, to_find, n);
	char*		ft_res = ft_strnstr(str, to_find, n);

	EXPECT_EQ(c_res, ft_res);
}
