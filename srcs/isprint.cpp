/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:02:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 21:43:18 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <ctype.h>

#include <gtest/gtest.h>

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
