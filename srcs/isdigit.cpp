/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:02:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 19:30:09 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <ctype.h>

TEST(isdigit, space) {
	char	c = ' ';

	EXPECT_EQ(!isdigit(c), !ft_isdigit(c));
}

TEST(isdigit, digit) {
	char	c = '1';

	EXPECT_EQ(!isdigit(c), !ft_isdigit(c));
}

TEST(isdigit, lowercase) {
	char	c = 'a';

	EXPECT_EQ(!isdigit(c), !ft_isdigit(c));
}

TEST(isdigit, uppercase) {
	char	c = 'A';

	EXPECT_EQ(!isdigit(c), !ft_isdigit(c));
}

TEST(isdigit, punctuation) {
	char	c = '-';

	EXPECT_EQ(!isdigit(c), !ft_isdigit(c));
}

TEST(isdigit, null_char) {
	char	c = 0;

	EXPECT_EQ(!isdigit(c), !ft_isdigit(c));
}

TEST(isdigit, control_char) {
	char	c = '\r';

	EXPECT_EQ(!isdigit(c), !ft_isdigit(c));
}

TEST(isdigit, non_ascii) {
	char	c = 255;

	EXPECT_EQ(!isdigit(c), !ft_isdigit(c));
}

TEST(isdigit, undefined_behavior) {
	int	c = 256 + 'a';
	int	d = 256 + 'A';
	int	e = 256 + '-';
	int	f = 256 + ' ';
	int	g = 256 + '\r';
	int	h = -1;

	EXPECT_EQ(!isdigit(c), !ft_isdigit(c));
	EXPECT_EQ(!isdigit(d), !ft_isdigit(d));
	EXPECT_EQ(!isdigit(e), !ft_isdigit(e));
	EXPECT_EQ(!isdigit(f), !ft_isdigit(f));
	EXPECT_EQ(!isdigit(g), !ft_isdigit(g));
	EXPECT_EQ(!isdigit(h), !ft_isdigit(h));
}
