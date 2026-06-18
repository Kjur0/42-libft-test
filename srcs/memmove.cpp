/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:29:36 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 14:55:30 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <string.h>

#include <gtest/gtest.h>

TEST(memmove, move_backwards) {
	char	str[] = "hello world";
	int		n = 12;
	char	*s = str + 2;
	char	*c = str;
	char	*ft = str;

	memmove(c, s, n - 2);
	ft_memmove(ft, str, n - 2);
	EXPECT_EQ(memcmp(c, ft, n), 0);
}

TEST(memmove, move_forwards) {
	char	str[] = "hello world";
	int		n = 12;
	char	*s = str;
	char	*c = str + 2;
	char	*ft = str + 2;

	memmove(c, s, n - 2);
	ft_memmove(ft, s, n - 2);
	EXPECT_EQ(memcmp(c, ft, n), 0);
}

TEST(memmove, zero_length) {
	char	str[] = "hello world";
	int		n = 0;
	char	*s = str;
	char	*c = str + 2;
	char	*ft = str + 2;

	memmove(c, s, n);
	ft_memmove(ft, s, n);
	EXPECT_EQ(memcmp(c, ft, 12), 0);
}

TEST(memmove, null_char) {
	char	str[] = "hello\0world";
	int		n = 12;
	char	*s = str;
	char	*c = str + 2;
	char	*ft = str + 2;

	memmove(c, s, n - 2);
	ft_memmove(ft, s, n - 2);
	EXPECT_EQ(memcmp(c, ft, n), 0);
}

TEST(memmove, in_place) {
	char	str[] = "hello world";
	int		n = 12;
	char	*s = str;
	char	*c = str;
	char	*ft = str;

	memmove(c, s, n - 2);
	ft_memmove(ft, s, n - 2);
	EXPECT_EQ(memcmp(c, ft, n), 0);
}
