/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:20:48 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/21 15:23:03 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(memcpy, basic)
{
	EXPECT_EXIT({
		const char	str[] = "Hello, world!";
		int			n = 14;
		char		c[n];
		char		ft[n];

		memcpy(c, str, n);
		ft_memcpy(ft, str, n);

		exit(memcmp(c, ft, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memcpy, zero_length)
{
	EXPECT_EXIT({
		const char	str[] = "Hello, world!";
		int			n = 0;
		char		c[n];
		char		ft[n];

		memcpy(c, str, n);
		ft_memcpy(ft, str, n);

		exit(memcmp(c, ft, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memcpy, null_char)
{
	EXPECT_EXIT({
		const char	str[] = "Hello\0world!";
		int			n = 13;
		char		c[n];
		char		ft[n];

		memcpy(c, str, n);
		ft_memcpy(ft, str, n);

		exit(memcmp(c, ft, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memcpy, partial_length)
{
	EXPECT_EXIT({
		const char	str[] = "Hello, world!";
		int			n = 5;
		char		c[n];
		char		ft[n];

		memcpy(c, str, n);
		ft_memcpy(ft, str, n);

		exit(memcmp(c, ft, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memcpy, nullptr_dst)
{
	EXPECT_EXIT({
		const char	*str = "Hello, world!";
		char		*ft = nullptr;
		const int	n = 5;

		ft_memcpy(ft, str, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
