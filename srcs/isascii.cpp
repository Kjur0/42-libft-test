/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:02:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 14:50:27 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <ctype.h>

#include <gtest/gtest.h>

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
