/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:02:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 19:30:17 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <ctype.h>

TEST(isprint, space) {
	char	c = ' ';

	EXPECT_EQ(!isprint(c), !ft_isprint(c));
}

TEST(isprint, digit) {
	char	c = '1';

	EXPECT_EQ(!isprint(c), !ft_isprint(c));
}

TEST(isprint, lowercase) {
	char	c = 'a';

	EXPECT_EQ(!isprint(c), !ft_isprint(c));
}

TEST(isprint, uppercase) {
	char	c = 'A';

	EXPECT_EQ(!isprint(c), !ft_isprint(c));
}

TEST(isprint, punctuation) {
	char	c = '-';

	EXPECT_EQ(!isprint(c), !ft_isprint(c));
}

TEST(isprint, null_char) {
	char	c = 0;

	EXPECT_EQ(!isprint(c), !ft_isprint(c));
}

TEST(isprint, control_char) {
	char	c = '\r';

	EXPECT_EQ(!isprint(c), !ft_isprint(c));
}

TEST(isprint, non_ascii) {
	char	c = 255;

	EXPECT_EQ(!isprint(c), !ft_isprint(c));
}

TEST(isprint, undefined_behavior) {
	int	c = 256 + 'a';
	int	d = 256 + 'A';
	int	e = 256 + '-';
	int	f = 256 + ' ';
	int	g = 256 + '\r';
	int	h = -1;

	EXPECT_EQ(!isprint(c), !ft_isprint(c));
	EXPECT_EQ(!isprint(d), !ft_isprint(d));
	EXPECT_EQ(!isprint(e), !ft_isprint(e));
	EXPECT_EQ(!isprint(f), !ft_isprint(f));
	EXPECT_EQ(!isprint(g), !ft_isprint(g));
	EXPECT_EQ(!isprint(h), !ft_isprint(h));
}
