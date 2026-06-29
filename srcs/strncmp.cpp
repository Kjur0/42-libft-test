/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:55:22 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/29 23:46:10 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(strncmp, equal)
{
	const char		*str1 = "Hello, world!";
	const char		*str2 = "Hello, world!";
	const size_t	n = 14;

	const int		c_cmp = strncmp(str1, str2, n);
	const int		ft_cmp = ft_strncmp(str1, str2, n);

	ASSERT_EQ(c_cmp, ft_cmp);
}

TEST(strncmp, different)
{
	const char		*str1 = "Hello, world!";
	const char		*str2 = "Hello. World!";
	const size_t	n = 14;

	const int		c_cmp = strncmp(str1, str2, n);
	const int		ft_cmp = ft_strncmp(str1, str2, n);

	ASSERT_EQ(c_cmp, ft_cmp);
}

TEST(strncmp, zero_length)
{
	const char		*str1 = "hello, world!";
	const char		*str2 = "Hello, World!";
	const size_t	n = 0;

	const int		c_cmp = strncmp(str1, str2, n);
	const int		ft_cmp = ft_strncmp(str1, str2, n);

	ASSERT_EQ(c_cmp, ft_cmp);
}

TEST(strncmp, null_char)
{
	const char		*str1 = "Hello\0world!";
	const char		*str2 = "Hello\0World!";
	const size_t	n = 13;

	const int		c_cmp = strncmp(str1, str2, n);
	const int		ft_cmp = ft_strncmp(str1, str2, n);

	ASSERT_EQ(c_cmp, ft_cmp);
}

TEST(strncmp, n_less_than_length)
{
	const char		*str1 = "Hello, world!";
	const char		*str2 = "Hello. World!";
	const size_t	n = 5;

	const int		c_cmp = strncmp(str1, str2, n);
	const int		ft_cmp = ft_strncmp(str1, str2, n);

	ASSERT_EQ(c_cmp, ft_cmp);
}

TEST(strncmp, n_greater_than_length)
{
	const char		*str1 = "Hello, world!";
	const char		*str2 = "Hello. World!";
	const size_t	n = 20;

	const int		c_cmp = strncmp(str1, str2, n);
	const int		ft_cmp = ft_strncmp(str1, str2, n);

	ASSERT_EQ(c_cmp, ft_cmp);
}

TEST(strncmp, non_ascii)
{
	const char		*str1 = "Héllo, w\255rld!";
	const char		*str2 = "Héllo, w\255rld!";
	const size_t	n = 14;

	const int		c_cmp1 = strncmp(str1, str2, n);
	const int		ft_cmp1 = ft_strncmp(str1, str2, n);
	const int		c_cmp2 = strncmp(str2, str1, n);
	const int		ft_cmp2 = ft_strncmp(str2, str1, n);

	EXPECT_EQ(c_cmp1, ft_cmp1);
	EXPECT_EQ(c_cmp2, ft_cmp2);
}

TEST(strncmp, non_ascii_different)
{
	const char		*str1 = "Héllo, w\255rld!";
	const char		*str2 = "Héllo, world?";
	const size_t	n = 14;

	const int		c_cmp1 = strncmp(str1, str2, n);
	const int		ft_cmp1 = ft_strncmp(str1, str2, n);
	const int		c_cmp2 = strncmp(str2, str1, n);
	const int		ft_cmp2 = ft_strncmp(str2, str1, n);

	EXPECT_EQ(c_cmp1, ft_cmp1);
	EXPECT_EQ(c_cmp2, ft_cmp2);
}

TEST(strncmp, shorter)
{
	const char		*str1 = "Hello";
	const char		*str2 = "Hello, world!";
	const size_t	n = 20;

	const int		c_cmp1 = strncmp(str1, str2, n);
	const int		ft_cmp1 = ft_strncmp(str1, str2, n);
	const int		c_cmp2 = strncmp(str2, str1, n);
	const int		ft_cmp2 = ft_strncmp(str2, str1, n);

	EXPECT_EQ(c_cmp1, ft_cmp1);
	EXPECT_EQ(c_cmp2, ft_cmp2);
}

TEST(strncmpDeathTest, nullptr1)
{
	ASSERT_EXIT({
		const char		*str1 = nullptr;
		const char		*str2 = "Hi";
		const size_t	n = 2;

		ft_strncmp(str1, str2, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(strncmpDeathTest, nullptr2)
{
	ASSERT_EXIT({
		const char		*str1 = "Hi";
		const char		*str2 = nullptr;
		const size_t	n = 2;

		ft_strncmp(str1, str2, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
