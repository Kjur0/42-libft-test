/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:35:54 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/23 21:53:44 by kjurkows         ###   ########.fr       */
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

		ft_memset(ft, 'x', n);
		memset(c, 'x', n);

		exit(memcmp(ft, c, 14));
}, ::testing::ExitedWithCode(0), "");
}

TEST(memset, full_length)
{
	EXPECT_EXIT({
		char	ft[] = "Hello, World!";
		char	c[] = "Hello, World!";
		int		n = 14;

		ft_memset(ft, 'x', n);
		memset(c, 'x', n);

		exit(memcmp(ft, c, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memset, non_printable)
{
	EXPECT_EXIT({
	char	ft[] = "Hello, World!";
	char	c[] = "Hello, World!";
	int		n = 5;

	ft_memset(ft, '\0', n);
	memset(c, '\0', n);

		exit(memcmp(ft, c, 14));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memset, zero_length)
{
	EXPECT_EXIT({
		char	ft[] = "Hello, World!";
		char	c[] = "Hello, World!";
		int		n = 0;

		ft_memset(ft, 'x', n);
		memset(c, 'x', n);

		exit(memcmp(ft, c, 14));
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
