/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:57:21 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 21:41:50 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <stdlib.h>

#include <gtest/gtest.h>

TEST(atoi, 0) {
	const char	str[] = "0";

	EXPECT_EQ(atoi(str), ft_atoi(str));
}

TEST(atoi, 1) {
	const char	str[] = "1";

	EXPECT_EQ(atoi(str), ft_atoi(str));
}

TEST(atoi, 42) {
	const char	str[] = "42";

	EXPECT_EQ(atoi(str), ft_atoi(str));
}

TEST(atoi, overflow) {
	const char	str[] = "2147483648";

	EXPECT_EQ(atoi(str), ft_atoi(str));
}

TEST(atoi, underflow) {
	const char	str[] = "-2147483649";

	EXPECT_EQ(atoi(str), ft_atoi(str));
}

TEST(atoi, whitespace) {
	const char	str[] = "   42";

	EXPECT_EQ(atoi(str), ft_atoi(str));
}

TEST(atoi, plus_sign) {
	const char	str[] = "+42";

	EXPECT_EQ(atoi(str), ft_atoi(str));
}

TEST(atoi, minus_sign) {
	const char	str[] = "-42";

	EXPECT_EQ(atoi(str), ft_atoi(str));
}

TEST(atoi, non_numeric) {
	const char	str[] = "42abc";

	EXPECT_EQ(atoi(str), ft_atoi(str));
}

TEST(atoi, empty_string) {
	const char	str[] = "";

	EXPECT_EQ(atoi(str), ft_atoi(str));
}

TEST(atoi, only_whitespace) {
	const char	str[] = "   ";

	EXPECT_EQ(atoi(str), ft_atoi(str));
}

TEST(atoi, multiple_signs) {
	const char	str1[] = "--42";
	const char	str2[] = "++42";
	const char	str3[] = "+-42";
	const char	str4[] = "-+42";

	EXPECT_EQ(atoi(str1), ft_atoi(str1));
	EXPECT_EQ(atoi(str2), ft_atoi(str2));
	EXPECT_EQ(atoi(str3), ft_atoi(str3));
	EXPECT_EQ(atoi(str4), ft_atoi(str4));
}

TEST(atoi, too_large_number) {
	const char	str[] = "999999999999999999999999";

	EXPECT_EQ(atoi(str), ft_atoi(str));
}

TEST(atoi, too_small_number) {
	const char	str[] = "-999999999999999999999999";
	
	EXPECT_EQ(atoi(str), ft_atoi(str));
}
