/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:02:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 14:50:10 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <ctype.h>

#include <gtest/gtest.h>

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
