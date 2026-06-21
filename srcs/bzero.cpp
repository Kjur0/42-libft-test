/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:24:53 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/21 14:26:11 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <strings.h>
#include <string.h>

TEST(bzero, basic)
{
	EXPECT_EXIT({
		char	c_str[] = "Hello, world!";
		char	ft_str[] = "Hello, world!";
		size_t	n = 5;

		bzero(c_str, n);
		ft_bzero(ft_str, n);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(bzero, zero_length)
{
	EXPECT_EXIT({
		char	c_str[] = "Hello, world!";
		char	ft_str[] = "Hello, world!";
		size_t	n = 0;

		bzero(c_str, n);
		ft_bzero(ft_str, n);


		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(bzero, full_length)
{
	EXPECT_EXIT({
		char	c_str[] = "Hello, world!";
		char	ft_str[] = "Hello, world!";
		size_t	n = sizeof(c_str);

		bzero(c_str, n);
		ft_bzero(ft_str, n);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(bzero, partial_length)
{
	EXPECT_EXIT({
		char	c_str[] = "Hello, world!";
		char	ft_str[] = "Hello, world!";
		size_t	n = 7;

		bzero(c_str, n);
		ft_bzero(ft_str, n);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(bzero, non_ascii)
{
	EXPECT_EXIT({
		char	c_str[] = "Héllo, wörld!";
		char	ft_str[] = "Héllo, wörld!";
		size_t	n = 5;

		bzero(c_str, n);
		ft_bzero(ft_str, n);

		exit(memcmp(c_str, ft_str, n));
	}, ::testing::ExitedWithCode(0), "");
}
