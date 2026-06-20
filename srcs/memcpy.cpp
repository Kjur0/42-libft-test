/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:20:48 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 19:59:30 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(memcpy, basic)
{
	const char	str[] = "Hello, world!";
	int			n = 14;
	char		c[n];
	char		ft[n];

	memcpy(c, str, n);
	ft_memcpy(ft, str, n);

	EXPECT_EQ(memcmp(c, ft, n), 0);
}

TEST(memcpy, zero_length)
{
	const char	str[] = "Hello, world!";
	int			n = 0;
	char		c[n];
	char		ft[n];

	memcpy(c, str, n);
	ft_memcpy(ft, str, n);

	EXPECT_EQ(memcmp(c, ft, n), 0);
}

TEST(memcpy, null_char)
{
	const char	str[] = "Hello\0world!";
	int			n = 13;
	char		c[n];
	char		ft[n];

	memcpy(c, str, n);
	ft_memcpy(ft, str, n);

	EXPECT_EQ(memcmp(c, ft, n), 0);
}

TEST(memcpy, partial_length)
{
	const char	str[] = "Hello, world!";
	int			n = 5;
	char		c[n];
	char		ft[n];

	memcpy(c, str, n);
	ft_memcpy(ft, str, n);

	EXPECT_EQ(memcmp(c, ft, n), 0);
}

TEST(memcpy, nullptr_dst)
{
	const char	*str = "Hello, world!";
	char		*ft = nullptr;
	const int	n = 5;

	EXPECT_EQ(ft_memcpy(ft, str, n), nullptr);
}
