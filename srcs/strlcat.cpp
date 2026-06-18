/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:44:54 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 16:43:46 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <bsd/string.h>

#include <gtest/gtest.h>

TEST(strlcat, basic) {
	char		c[20] = "Hello, ";
	char		ft[20] = "Hello, ";
	const char*	src = "World!";
	int			n = 20;

	size_t	c_result = strlcat(c, src, n);
	size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, zero_size) {
	char		c[20] = "Hello, ";
	char		ft[20] = "Hello, ";
	const char*	src = "World!";
	int			n = 0;

	size_t	c_result = strlcat(c, src, n);
	size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_smaller_than_dst) {
	char		c[20] = "Hello, ";
	char		ft[20] = "Hello, ";
	const char*	src = "World!";
	int			n = 5;

	size_t	c_result = strlcat(c, src, n);
	size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_smaller_than_src) {
	char		c[20] = "Hello, ";
	char		ft[20] = "Hello, ";
	const char*	src = "World!";
	int			n = 10;

	size_t	c_result = strlcat(c, src, n);
	size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, empty_src) {
	char		c[20] = "Hello, ";
	char		ft[20] = "Hello, ";
	const char*	src = "";
	int			n = 20;

	size_t	c_result = strlcat(c, src, n);
	size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, empty_dst) {
	char		c[20] = "";
	char		ft[20] = "";
	const char*	src = "Hello, World!";
	int			n = 20;

	size_t	c_result = strlcat(c, src, n);
	size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_equal_to_dst) {
	char		c[20] = "Hello, ";
	char		ft[20] = "Hello, ";
	const char*	src = "World!";
	int			n = 7;

	size_t	c_result = strlcat(c, src, n);
	size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_equal_to_dst_plus_one) {
	char		c[20] = "Hello, ";
	char		ft[20] = "Hello, ";
	const char*	src = "World!";
	int			n = 8;

	size_t	c_result = strlcat(c, src, n);
	size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_equal_to_src) {
	char		c[20] = "Hello, ";
	char		ft[20] = "Hello, ";
	const char*	src = "World!";
	int			n = 6;

	size_t	c_result = strlcat(c, src, n);
	size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_equal_to_src_plus_one) {
	char		c[20] = "Hello, ";
	char		ft[20] = "Hello, ";
	const char*	src = "World!";
	int			n = 7;

	size_t	c_result = strlcat(c, src, n);
	size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_one) {
	char		c[20] = "Hello, ";
	char		ft[20] = "Hello, ";
	const char*	src = "World!";
	int			n = 1;

	size_t	c_result = strlcat(c, src, n);
	size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, exact_size) {
	char		c[20] = "Hello, ";
	char		ft[20] = "Hello, ";
	const char*	src = "World!";
	int			n = 14;

	size_t	c_result = strlcat(c, src, n);
	size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}
