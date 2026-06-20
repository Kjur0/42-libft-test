/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:02:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 11:48:35 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <ctype.h>

TEST(isalpha, space) {
	char	c = ' ';

	EXPECT_EQ(!isalpha(c), !ft_isalpha(c));
}

TEST(isalpha, digit) {
	char	c = '1';

	EXPECT_EQ(!isalpha(c), !ft_isalpha(c));
}

TEST(isalpha, lowercase) {
	char	c = 'a';

	EXPECT_EQ(!isalpha(c), !ft_isalpha(c));
}

TEST(isalpha, uppercase) {
	char	c = 'A';

	EXPECT_EQ(!isalpha(c), !ft_isalpha(c));
}

TEST(isalpha, punctuation) {
	char	c = '-';

	EXPECT_EQ(!isalpha(c), !ft_isalpha(c));
}

TEST(isalpha, null_char) {
	char	c = 0;

	EXPECT_EQ(!isalpha(c), !ft_isalpha(c));
}

TEST(isalpha, control_char) {
	char	c = '\r';

	EXPECT_EQ(!isalpha(c), !ft_isalpha(c));
}

TEST(isalpha, non_ascii) {
	char	c = 255;

	EXPECT_EQ(!isalpha(c), !ft_isalpha(c));
}

TEST(isalpha, undefined_behavior) {
	int	c = 256 + 'a';
	int	d = 256 + 'A';
	int	e = 256 + '-';
	int	f = 256 + ' ';
	int	g = 256 + '\r';
	int	h = -1;

	EXPECT_EQ(!isalpha(c), !ft_isalpha(c));
	EXPECT_EQ(!isalpha(d), !ft_isalpha(d));
	EXPECT_EQ(!isalpha(e), !ft_isalpha(e));
	EXPECT_EQ(!isalpha(f), !ft_isalpha(f));
	EXPECT_EQ(!isalpha(g), !ft_isalpha(g));
	EXPECT_EQ(!isalpha(h), !ft_isalpha(h));
}
