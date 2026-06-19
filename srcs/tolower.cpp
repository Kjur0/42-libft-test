/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:57:19 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 20:04:56 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <string.h>

TEST(tolower, basic) {
	int	a = 'a';
	int	z = 'z';
	int	A = 'A';
	int	Z = 'Z';

	EXPECT_EQ(tolower(a), ft_tolower(a));
	EXPECT_EQ(tolower(z), ft_tolower(z));
	EXPECT_EQ(tolower(A), ft_tolower(A));
	EXPECT_EQ(tolower(Z), ft_tolower(Z));
}

TEST(tolower, number) {
	int	zero = '0';
	int	nine = '9';

	EXPECT_EQ(tolower(zero), ft_tolower(zero));
	EXPECT_EQ(tolower(nine), ft_tolower(nine));
}

TEST(tolower, special) {
	int	at = '@';
	int	slash = '/';
	int	colon = ':';

	EXPECT_EQ(tolower(at), ft_tolower(at));
	EXPECT_EQ(tolower(slash), ft_tolower(slash));
	EXPECT_EQ(tolower(colon), ft_tolower(colon));
}

TEST(tolower, non_ascii) {
	int	non_ascii = 128;

	EXPECT_EQ(tolower(non_ascii), ft_tolower(non_ascii));
}

TEST(tolower, negative) {
	int	negative = -12;

	EXPECT_EQ(tolower(negative), ft_tolower(negative));
}

TEST(tolower, out_of_range) {
	int	out_of_range = 256;

	EXPECT_EQ(tolower(out_of_range), ft_tolower(out_of_range));
}

TEST(tolower, null_char) {
	int	null_char = '\0';

	EXPECT_EQ(tolower(null_char), ft_tolower(null_char));
}

TEST(tolower, all_chars) {
	for (int i = -128; i <= 255; ++i) {
		EXPECT_EQ(tolower(i), ft_tolower(i));
	}
}

TEST(tolower, eof) {
	int	eof = EOF;

	EXPECT_EQ(tolower(eof), ft_tolower(eof));
}
