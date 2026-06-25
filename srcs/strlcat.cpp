/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:44:54 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:51:59 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <bsd/string.h>

TEST(strlcat, basic)
{
	char			c[20] = "Hello, ";
	char			ft[20] = "Hello, ";
	const char		*src = "World!";
	const size_t	n = 20;

	const size_t	c_result = strlcat(c, src, n);
	const size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, zero_size)
{
	char			c[20] = "Hello, ";
	char			ft[20] = "Hello, ";
	const char		*src = "World!";
	const size_t	n = 0;

	const size_t	c_result = strlcat(c, src, n);
	const size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_smaller_than_dst)
{
	char			c[20] = "Hello, ";
	char			ft[20] = "Hello, ";
	const char		*src = "World!";
	const size_t	n = 5;

	const size_t	c_result = strlcat(c, src, n);
	const size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_smaller_than_src)
{
	char			c[20] = "Hello, ";
	char			ft[20] = "Hello, ";
	const char		*src = "World!";
	const size_t	n = 10;

	const size_t	c_result = strlcat(c, src, n);
	const size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, empty_src)
{
	char			c[20] = "Hello, ";
	char			ft[20] = "Hello, ";
	const char		*src = "";
	const size_t	n = 20;

	const size_t	c_result = strlcat(c, src, n);
	const size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, empty_dst)
{
	char			c[20] = "";
	char			ft[20] = "";
	const char		*src = "Hello, World!";
	const size_t	n = 20;

	const size_t	c_result = strlcat(c, src, n);
	const size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_equal_to_dst)
{
	char			c[20] = "Hello, ";
	char			ft[20] = "Hello, ";
	const char		*src = "World!";
	const size_t	n = 7;

	const size_t	c_result = strlcat(c, src, n);
	const size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_equal_to_dst_plus_one)
{
	char			c[20] = "Hello, ";
	char			ft[20] = "Hello, ";
	const char		*src = "World!";
	const size_t	n = 8;

	const size_t	c_result = strlcat(c, src, n);
	const size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_equal_to_src)
{
	char			c[20] = "Hello, ";
	char			ft[20] = "Hello, ";
	const char		*src = "World!";
	const size_t	n = 6;

	const size_t	c_result = strlcat(c, src, n);
	const size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_equal_to_src_plus_one)
{
	char			c[20] = "Hello, ";
	char			ft[20] = "Hello, ";
	const char		*src = "World!";
	const size_t	n = 7;

	const size_t	c_result = strlcat(c, src, n);
	const size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, size_one)
{
	char			c[20] = "Hello, ";
	char			ft[20] = "Hello, ";
	const char		*src = "World!";
	const size_t	n = 1;

	const size_t	c_result = strlcat(c, src, n);
	const size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, exact_size)
{
	char			c[20] = "Hello, ";
	char			ft[20] = "Hello, ";
	const char		*src = "World!";
	const size_t	n = 14;

	const size_t		c_result = strlcat(c, src, n);
	const size_t		ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcat, dst_not_nul_terminated)
{
	char			c[37] = "Hello,012345678901234567890123456798";
	char			ft[37] = "Hello,012345678901234567890123456798";
	const char		*src = "World!";
	const size_t	n = 20;

	c[36] = 'X';
	ft[36] = 'X';

	const size_t	c_result = strlcat(c, src, n);
	const size_t	ft_result = ft_strlcat(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_EQ(memcmp(c, ft, 37), 0);
}

TEST(strlcatDeathTest, nullptr_dst)
{
	EXPECT_EXIT({
		char			*dst = nullptr;
		const char		*src = "Hello World!";
		const size_t	n = 20;

		ft_strlcat(dst, src, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}


TEST(strlcatDeathTest, nullptr_src)
{
	EXPECT_EXIT({
		char			dst[] = "Hello World!";
		const char		*src = nullptr;
		const size_t	n = 20;

		ft_strlcat(dst, src, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
