/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:02:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 11:48:35 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <ctype.h>

TEST(isascii, space) {
	char	c = ' ';

	EXPECT_EQ(!isascii(c), !ft_isascii(c));
}

TEST(isascii, digit) {
	char	c = '1';

	EXPECT_EQ(!isascii(c), !ft_isascii(c));
}

TEST(isascii, lowercase) {
	char	c = 'a';

	EXPECT_EQ(!isascii(c), !ft_isascii(c));
}

TEST(isascii, uppercase) {
	char	c = 'A';

	EXPECT_EQ(!isascii(c), !ft_isascii(c));
}

TEST(isascii, punctuation) {
	char	c = '-';

	EXPECT_EQ(!isascii(c), !ft_isascii(c));
}

TEST(isascii, null_char) {
	char	c = 0;

	EXPECT_EQ(!isascii(c), !ft_isascii(c));
}

TEST(isascii, control_char) {
	char	c = '\r';

	EXPECT_EQ(!isascii(c), !ft_isascii(c));
}

TEST(isascii, non_ascii) {
	char	c = 255;

	EXPECT_EQ(!isascii(c), !ft_isascii(c));
}

TEST(isascii, undefined_behavior) {
	int	c = 256 + 'a';
	int	d = 256 + 'A';
	int	e = 256 + '-';
	int	f = 256 + ' ';
	int	g = 256 + '\r';
	int	h = -1;

	EXPECT_EQ(!isascii(c), !ft_isascii(c));
	EXPECT_EQ(!isascii(d), !ft_isascii(d));
	EXPECT_EQ(!isascii(e), !ft_isascii(e));
	EXPECT_EQ(!isascii(f), !ft_isascii(f));
	EXPECT_EQ(!isascii(g), !ft_isascii(g));
	EXPECT_EQ(!isascii(h), !ft_isascii(h));
}
