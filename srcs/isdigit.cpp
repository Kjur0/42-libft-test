/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:02:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 14:50:45 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <ctype.h>

#include <gtest/gtest.h>

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
