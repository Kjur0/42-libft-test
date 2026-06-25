/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:29:36 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:47:24 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(memmove, move_backwards)
{
	ASSERT_EXIT({
		char		c_str[] = "hello world";
		char		ft_str[] = "hello world";
		const char	*c_s = c_str + 2;
		char		*c = c_str;
		const char	*ft_s = ft_str + 2;
		char		*ft = ft_str;
		const int	n = 12;

		memmove(c, c_s, n - 2);
		ft_memmove(ft, ft_s, n - 2);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memmove, move_forwards)
{
	ASSERT_EXIT({
		char		c_str[] = "hello world";
		char		ft_str[] = "hello world";
		const char	*c_s = c_str;
		char		*c = c_str + 2;
		const char	*ft_s = ft_str;
		char		*ft = ft_str + 2;
		const int	n = 12;

		memmove(c, c_s, n - 2);
		ft_memmove(ft, ft_s, n - 2);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memmove, zero_length)
{
	ASSERT_EXIT({
		char		c_str[] = "hello world";
		char		ft_str[] = "hello world";
		const char	*c_s = c_str;
		char		*c = c_str + 2;
		const char	*ft_s = ft_str;
		char		*ft = ft_str + 2;
		const int	n = 0;

		memmove(c, c_s, n);
		ft_memmove(ft, ft_s, n);

		exit(memcmp(c_str, ft_str, 12));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memmove, null_char)
{
	ASSERT_EXIT({
		char		c_str[] = "hello\0world";
		char		ft_str[] = "hello\0world";
		const char	*c_s = c_str;
		char		*c = c_str + 2;
		const char	*ft_s = ft_str;
		char		*ft = ft_str + 2;
		const int	n = 12;

		memmove(c, c_s, n - 2);
		ft_memmove(ft, ft_s, n - 2);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memmove, in_place)
{
	ASSERT_EXIT({
		char		c_str[] = "hello world";
		char		ft_str[] = "hello world";
		const char	*c_s = c_str;
		char		*c = c_str;
		const char	*ft_s = ft_str;
		char		*ft = ft_str;
		const int	n = 12;

		memmove(c, c_s, n - 2);
		ft_memmove(ft, ft_s, n - 2);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memmoveDeathTest, nullptr_dst)
{
	ASSERT_EXIT({
		const char	*str = "Hello, world!";
		char		*ft = nullptr;
		const int	n = 5;

		ft_memmove(ft, str, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memmoveDeathTest, nullptr_src)
{
	ASSERT_EXIT({
		const char	*str = nullptr;
		char		ft[13];
		const int	n = 5;

		ft_memmove(ft, str, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
