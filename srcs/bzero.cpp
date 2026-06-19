/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:24:53 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 19:29:14 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <strings.h>
#include <string.h>

TEST(bzero, basic) {
	char	c_str[] = "Hello, world!";
	char	ft_str[] = "Hello, world!";
	size_t	n = 5;

	bzero(c_str, n);
	ft_bzero(ft_str, n);

	EXPECT_EQ(memcmp(c_str, ft_str, n), 0);
}

TEST(bzero, zero_length) {
	char	c_str[] = "Hello, world!";
	char	ft_str[] = "Hello, world!";
	size_t	n = 0;

	bzero(c_str, n);
	ft_bzero(ft_str, n);

	EXPECT_EQ(memcmp(c_str, ft_str, sizeof(c_str)), 0);
}

TEST(bzero, full_length) {
	char	c_str[] = "Hello, world!";
	char	ft_str[] = "Hello, world!";
	size_t	n = sizeof(c_str);

	bzero(c_str, n);
	ft_bzero(ft_str, n);

	EXPECT_EQ(memcmp(c_str, ft_str, n), 0);
}

TEST(bzero, partial_length) {
	char	c_str[] = "Hello, world!";
	char	ft_str[] = "Hello, world!";
	size_t	n = 7;

	bzero(c_str, n);
	ft_bzero(ft_str, n);

	EXPECT_EQ(memcmp(c_str, ft_str, n), 0);
}

TEST(bzero, non_ascii) {
	char	c_str[] = "Héllo, wörld!";
	char	ft_str[] = "Héllo, wörld!";
	size_t	n = 5;

	bzero(c_str, n);
	ft_bzero(ft_str, n);

	EXPECT_EQ(memcmp(c_str, ft_str, n), 0);
}
