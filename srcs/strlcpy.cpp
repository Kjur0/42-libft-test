/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:41:21 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/23 22:44:42 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <bsd/string.h>

TEST(strlcpy, basic)
{
	char		c[20];
	char		ft[20];
	const char	*src = "Hello, World!";
	int			n = 20;

	size_t		c_result = strlcpy(c, src, n);
	size_t		ft_result = ft_strlcpy(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcpy, zero_size)
{
	char		c[20] = "t";
	char		ft[20] = "t";
	const char	*src = "Hello, World!";
	int			n = 0;

	size_t		c_result = strlcpy(c, src, n);
	size_t		ft_result = ft_strlcpy(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcpy, smaller_size)
{
	char		c[20];
	char		ft[20];
	const char	*src = "Hello, World!";
	int			n = 5;

	size_t		c_result = strlcpy(c, src, n);
	size_t		ft_result = ft_strlcpy(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcpy, empty_string)
{
	char		c[20];
	char		ft[20];
	const char	*src = "";
	int			n = 20;

	size_t		c_result = strlcpy(c, src, n);
	size_t		ft_result = ft_strlcpy(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcpy, exact_size)
{
	char		c[20];
	char		ft[20];
	const char	*src = "Hello, World!";
	int			n = 14;

	size_t		c_result = strlcpy(c, src, n);
	size_t		ft_result = ft_strlcpy(ft, src, n);

	EXPECT_EQ(c_result, ft_result);
	EXPECT_STREQ(c, ft);
}

TEST(strlcpyDeathTest, nullptr_dst)
{
	EXPECT_EXIT({
		const char	*src = "Hello, World!";
		char		*dst = nullptr;
		const int	n = 20;

		ft_strlcpy(dst, src, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(strlcpyDeathTest, nullptr_src)
{
	EXPECT_EXIT({
		const char	*src = nullptr;
		char		dst[20];
		const int	n = 20;

		ft_strlcpy(dst, src, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
