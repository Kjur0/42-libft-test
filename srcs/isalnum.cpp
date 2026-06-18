/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:56:42 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 21:42:39 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <ctype.h>

#include <gtest/gtest.h>

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
