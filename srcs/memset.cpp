/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:35:54 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/24 16:28:25 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(memset, basic)
{
	EXPECT_EXIT({
		char	ft[] = "Hello, World!";
		char	c[] = "Hello, World!";
		int		n = 5;

		memset(c, 'x', n);
		ft_memset(ft, 'x', n);

		exit(memcmp(ft, c, 14));
}, ::testing::ExitedWithCode(0), "");
}

TEST(memset, full_length)
{
	EXPECT_EXIT({
		char	ft[] = "Hello, World!";
		char	c[] = "Hello, World!";
		int		n = 14;

		memset(c, 'x', n);
		ft_memset(ft, 'x', n);

		exit(memcmp(ft, c, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memset, non_printable)
{
	EXPECT_EXIT({
		char	ft[] = "Hello, World!";
		char	c[] = "Hello, World!";
		int		n = 5;

		memset(c, '\0', n);
		ft_memset(ft, '\0', n);

		exit(memcmp(ft, c, 14));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memset, zero_length)
{
	EXPECT_EXIT({
		char	ft[] = "Hello, World!";
		char	c[] = "Hello, World!";
		int		n = 0;

		memset(c, 'x', n);
		ft_memset(ft, 'x', n);

		exit(memcmp(ft, c, 14));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memset, cast)
{
	EXPECT_EXIT({
		char	ft[20];
		char	c[20];
		int		n = 20;

		memset(ft, 256, n);
		ft_memset(c, 256, n);

		exit(memcmp(ft, c, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memsetDeathTest, nullptr)
{
	EXPECT_EXIT({
		char	*ft = nullptr;
		int		n = 5;

		ft_memset(ft, 'x', n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
