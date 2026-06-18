/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:29:36 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 21:51:29 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <string.h>

#include <gtest/gtest.h>

TEST(memmove, move_backwards) {
	char	c_str[] = "hello world";
	char	ft_str[] = "hello world";
	int		n = 12;
	char	*c_s = c_str + 2;
	char	*c = c_str;
	char	*ft_s = ft_str + 2;
	char	*ft = ft_str;

	memmove(c, c_s, n - 2);
	ft_memmove(ft, ft_s, n - 2);

	EXPECT_EQ(memcmp(c_str, ft_str, n), 0);
}

TEST(memmove, move_forwards) {
	char	c_str[] = "hello world";
	char	ft_str[] = "hello world";
	int		n = 12;
	char	*c_s = c_str;
	char	*c = c_str + 2;
	char	*ft_s = ft_str;
	char	*ft = ft_str + 2;

	memmove(c, c_s, n - 2);
	ft_memmove(ft, ft_s, n - 2);

	EXPECT_EQ(memcmp(c_str, ft_str, n), 0);
}

TEST(memmove, zero_length) {
	char	c_str[] = "hello world";
	char	ft_str[] = "hello world";
	int		n = 0;
	char	*c_s = c_str;
	char	*c = c_str + 2;
	char	*ft_s = ft_str;
	char	*ft = ft_str + 2;

	memmove(c, c_s, n);
	ft_memmove(ft, ft_s, n);

	EXPECT_EQ(memcmp(c_str, ft_str, 12), 0);
}

TEST(memmove, null_char) {
	char	c_str[] = "hello\0world";
	char	ft_str[] = "hello\0world";
	int		n = 12;
	char	*c_s = c_str;
	char	*c = c_str + 2;
	char	*ft_s = ft_str;
	char	*ft = ft_str + 2;

	memmove(c, c_s, n - 2);
	ft_memmove(ft, ft_s, n - 2);

	EXPECT_EQ(memcmp(c_str, ft_str, n), 0);
}

TEST(memmove, in_place) {
	char	c_str[] = "hello world";
	char	ft_str[] = "hello world";
	int		n = 12;
	char	*c_s = c_str;
	char	*c = c_str;
	char	*ft_s = ft_str;
	char	*ft = ft_str;

	memmove(c, c_s, n - 2);
	ft_memmove(ft, ft_s, n - 2);

	EXPECT_EQ(memcmp(c_str, ft_str, n), 0);
}
