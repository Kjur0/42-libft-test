/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:29:36 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/21 15:24:49 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(memmove, move_backwards)
{
	EXPECT_EXIT({
		char	c_str[] = "hello world";
		char	ft_str[] = "hello world";
		int		n = 12;
		char	*c_s = c_str + 2;
		char	*c = c_str;
		char	*ft_s = ft_str + 2;
		char	*ft = ft_str;

		memmove(c, c_s, n - 2);
		ft_memmove(ft, ft_s, n - 2);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memmove, move_forwards)
{
	EXPECT_EXIT({
		char	c_str[] = "hello world";
		char	ft_str[] = "hello world";
		int		n = 12;
		char	*c_s = c_str;
		char	*c = c_str + 2;
		char	*ft_s = ft_str;
		char	*ft = ft_str + 2;

		memmove(c, c_s, n - 2);
		ft_memmove(ft, ft_s, n - 2);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memmove, zero_length)
{
	EXPECT_EXIT({
		char	c_str[] = "hello world";
		char	ft_str[] = "hello world";
		int		n = 0;
		char	*c_s = c_str;
		char	*c = c_str + 2;
		char	*ft_s = ft_str;
		char	*ft = ft_str + 2;

		memmove(c, c_s, n);
		ft_memmove(ft, ft_s, n);

		exit(memcmp(c_str, ft_str, 12));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memmove, null_char)
{
	EXPECT_EXIT({
		char	c_str[] = "hello\0world";
		char	ft_str[] = "hello\0world";
		int		n = 12;
		char	*c_s = c_str;
		char	*c = c_str + 2;
		char	*ft_s = ft_str;
		char	*ft = ft_str + 2;

		memmove(c, c_s, n - 2);
		ft_memmove(ft, ft_s, n - 2);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memmove, in_place)
{
	EXPECT_EXIT({
		char	c_str[] = "hello world";
		char	ft_str[] = "hello world";
		int		n = 12;
		char	*c_s = c_str;
		char	*c = c_str;
		char	*ft_s = ft_str;
		char	*ft = ft_str;

		memmove(c, c_s, n - 2);
		ft_memmove(ft, ft_s, n - 2);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memmove, null_pointer)
{
	EXPECT_EXIT({
		const char	*str = nullptr;
		char		*ft = nullptr;
		const int	n = 5;

		ft_memmove(ft, str, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
