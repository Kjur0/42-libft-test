/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:24:53 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/23 22:21:07 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <strings.h>
#include <string.h>

TEST(bzero, basic)
{
	EXPECT_EXIT({
		char			c_str[] = "Hello, world!";
		char			ft_str[] = "Hello, world!";
		const size_t	n = 5;

		bzero(c_str, n);
		ft_bzero(ft_str, n);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(bzero, zero_length)
{
	EXPECT_EXIT({
		char			c_str[] = "Hello, world!";
		char			ft_str[] = "Hello, world!";
		const size_t	n = 0;

		bzero(c_str, n);
		ft_bzero(ft_str, n);


		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(bzero, full_length)
{
	EXPECT_EXIT({
		char			c_str[] = "Hello, world!";
		char			ft_str[] = "Hello, world!";
		const size_t	n = 14;

		bzero(c_str, n);
		ft_bzero(ft_str, n);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(bzero, partial_length)
{
	EXPECT_EXIT({
		char			c_str[] = "Hello, world!";
		char			ft_str[] = "Hello, world!";
		const size_t	n = 7;

		bzero(c_str, n);
		ft_bzero(ft_str, n);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(bzero, non_ascii)
{
	EXPECT_EXIT({
		char			c_str[] = "Héllo, wörld!";
		char			ft_str[] = "Héllo, wörld!";
		const size_t	n = 5;

		bzero(c_str, n);
		ft_bzero(ft_str, n);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(bzeroDeathTest, nullptr)
{
	EXPECT_EXIT({
		char			*ptr = nullptr;
		const size_t	n = 5;

		ft_bzero(ptr, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
