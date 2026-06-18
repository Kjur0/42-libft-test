/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:24:53 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 16:45:09 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <string.h>

#include <gtest/gtest.h>

TEST(memcmp, equal) {
	const char	str1[] = "Hello, world!";
	const char	str2[] = "Hello, world!";
	size_t		n = 14;

	int	c_cmp = memcmp(str1, str2, n);
	int	ft_cmp = ft_memcmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(memcmp, different) {
	const char	str1[] = "Hello, world!";
	const char	str2[] = "Hello. World!";
	size_t		n = 14;

	int	c_cmp = memcmp(str1, str2, n);
	int	ft_cmp = ft_memcmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(memcmp, zero_length) {
	const char	str1[] = "Hello, world!";
	const char	str2[] = "Hello, World!";
	size_t		n = 0;

	int	c_cmp = memcmp(str1, str2, n);
	int	ft_cmp = ft_memcmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(memcmp, null_char) {
	const char	str1[] = "Hello\0world!";
	const char	str2[] = "Hello\0World!";
	size_t		n = 13;

	int	c_cmp = memcmp(str1, str2, n);
	int	ft_cmp = ft_memcmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(memcmp, partial_length) {
	const char	str1[] = "Hello, world!";
	const char	str2[] = "Hello, World.";
	size_t		n = 5;

	int	c_cmp = memcmp(str1, str2, n);
	int	ft_cmp = ft_memcmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(memcmp, non_ascii) {
	const char	str1[] = "Héllo, world!";
	const char	str2[] = "Héllo, wörld!";
	size_t		n = 14;

	int	c_cmp = memcmp(str1, str2, n);
	int	ft_cmp = ft_memcmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}
