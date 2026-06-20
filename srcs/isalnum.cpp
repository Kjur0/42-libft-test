/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:56:42 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 11:48:35 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <ctype.h>

TEST(isalnum, space) {
	char	c = ' ';

	EXPECT_EQ(!isalnum(c), !ft_isalnum(c));
}

TEST(isalnum, digit) {
	char	c = '5';

	EXPECT_EQ(!isalnum(c), !ft_isalnum(c));
}

TEST(isalnum, lowercase) {
	char	c = 'a';

	EXPECT_EQ(!isalnum(c), !ft_isalnum(c));
}

TEST(isalnum, uppercase) {
	char	c = 'A';

	EXPECT_EQ(!isalnum(c), !ft_isalnum(c));
}

TEST(isalnum, punctuation) {
	char	c = '-';

	EXPECT_EQ(!isalnum(c), !ft_isalnum(c));
}

TEST(isalnum, null_char) {
	char	c = 0;

	EXPECT_EQ(!isalnum(c), !ft_isalnum(c));
}

TEST(isalnum, control_char) {
	char	c = '\r';

	EXPECT_EQ(!isalnum(c), !ft_isalnum(c));
}

TEST(isalnum, non_ascii) {
	char	c = 255;

	EXPECT_EQ(!isalnum(c), !ft_isalnum(c));
}

TEST(isalnum, undefined_behavior) {
	int	c = 256 + 'a';
	int	d = 256 + '0';
	int	e = 256 + '-';
	int	f = 256 + ' ';
	int	g = 256 + '\r';
	int	h = -1;

	EXPECT_EQ(!isalnum(c), !ft_isalnum(c));
	EXPECT_EQ(!isalnum(d), !ft_isalnum(d));
	EXPECT_EQ(!isalnum(e), !ft_isalnum(e));
	EXPECT_EQ(!isalnum(f), !ft_isalnum(f));
	EXPECT_EQ(!isalnum(g), !ft_isalnum(g));
	EXPECT_EQ(!isalnum(h), !ft_isalnum(h));
}
