/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 22:04:11 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 22:05:29 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}

#include <gtest/gtest.h>

TEST(itoa, 0) {
	EXPECT_STREQ(ft_itoa(0), "0");
}

TEST(itoa, 42) {
	EXPECT_STREQ(ft_itoa(42), "42");
}

TEST(itoa, 123) {
	EXPECT_STREQ(ft_itoa(123), "123");
}

TEST(itoa, neg42) {
	EXPECT_STREQ(ft_itoa(-42), "-42");
}

TEST(itoa, int_min) {
	EXPECT_STREQ(ft_itoa(-2147483648), "-2147483648");
}

TEST(itoa, int_max) {
	EXPECT_STREQ(ft_itoa(2147483647), "2147483647");
}
