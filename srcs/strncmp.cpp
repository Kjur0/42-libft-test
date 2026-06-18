/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:55:22 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 17:00:46 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <string.h>

#include <gtest/gtest.h>

TEST(strncmp, equal) {
	const char	str1[] = "Hello, world!";
	const char	str2[] = "Hello, world!";
	size_t		n = 14;

	int	c_cmp = strncmp(str1, str2, n);
	int	ft_cmp = ft_strncmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(strncmp, different) {
	const char	str1[] = "Hello, world!";
	const char	str2[] = "Hello. World!";
	size_t		n = 14;

	int	c_cmp = strncmp(str1, str2, n);
	int	ft_cmp = ft_strncmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(strncmp, zero_length) {
	const char	str1[] = "Hello, world!";
	const char	str2[] = "Hello, World!";
	size_t		n = 0;

	int	c_cmp = strncmp(str1, str2, n);
	int	ft_cmp = ft_strncmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(strncmp, null_char) {
	const char	str1[] = "Hello\0world!";
	const char	str2[] = "Hello\0World!";
	size_t		n = 13;

	int	c_cmp = strncmp(str1, str2, n);
	int	ft_cmp = ft_strncmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(strncmp, n_less_than_length) {
	const char	str1[] = "Hello, world!";
	const char	str2[] = "Hello. World!";
	size_t		n = 5;

	int	c_cmp = strncmp(str1, str2, n);
	int	ft_cmp = ft_strncmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(strncmp, n_greater_than_length) {
	const char	str1[] = "Hello, world!";
	const char	str2[] = "Hello. World!";
	size_t		n = 20;

	int	c_cmp = strncmp(str1, str2, n);
	int	ft_cmp = ft_strncmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(strncmp, non_ascii) {
	const char	str1[] = "Héllo, wörld!";
	const char	str2[] = "Héllo, wörld!";
	size_t		n = 14;

	int	c_cmp = strncmp(str1, str2, n);
	int	ft_cmp = ft_strncmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}

TEST(strncmp, non_ascii_different) {
	const char	str1[] = "Héllo, wörld!";
	const char	str2[] = "Héllo, world?";
	size_t		n = 14;

	int	c_cmp = strncmp(str1, str2, n);
	int	ft_cmp = ft_strncmp(str1, str2, n);

	EXPECT_EQ(c_cmp, ft_cmp);
}
