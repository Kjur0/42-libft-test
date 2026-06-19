/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:35:54 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 19:30:58 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <string.h>

TEST(memset, basic) {
	char	ft[] = "Hello, World!";
	char	c[] = "Hello, World!";
	int		n = 5;

	ft_memset(ft, 'x', n);
	memset(c, 'x', n);

	EXPECT_EQ(memcmp(ft, c, 14), 0);
}

TEST(memset, full_length) {
	char	ft[] = "Hello, World!";
	char	c[] = "Hello, World!";
	int		n = 14;

	ft_memset(ft, 'x', n);
	memset(c, 'x', n);

	EXPECT_EQ(memcmp(ft, c, n), 0);
}

TEST(memset, non_printable) {
	char	ft[] = "Hello, World!";
	char	c[] = "Hello, World!";
	int		n = 5;

	ft_memset(ft, '\0', n);
	memset(c, '\0', n);

	EXPECT_EQ(memcmp(ft, c, 14), 0);
}
