/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:57:19 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 11:48:35 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(toupper, basic) {
	int	a = 'a';
	int	z = 'z';
	int	A = 'A';
	int	Z = 'Z';

	EXPECT_EQ(toupper(a), ft_toupper(a));
	EXPECT_EQ(toupper(z), ft_toupper(z));
	EXPECT_EQ(toupper(A), ft_toupper(A));
	EXPECT_EQ(toupper(Z), ft_toupper(Z));
}

TEST(toupper, number) {
	int	zero = '0';
	int	nine = '9';

	EXPECT_EQ(toupper(zero), ft_toupper(zero));
	EXPECT_EQ(toupper(nine), ft_toupper(nine));
}

TEST(toupper, special) {
	int	at = '@';
	int	slash = '/';
	int	colon = ':';

	EXPECT_EQ(toupper(at), ft_toupper(at));
	EXPECT_EQ(toupper(slash), ft_toupper(slash));
	EXPECT_EQ(toupper(colon), ft_toupper(colon));
}

TEST(toupper, non_ascii) {
	int	non_ascii = 128;

	EXPECT_EQ(toupper(non_ascii), ft_toupper(non_ascii));
}

TEST(toupper, negative) {
	int	negative = -12;

	EXPECT_EQ(toupper(negative), ft_toupper(negative));
}

TEST(toupper, out_of_range) {
	int	out_of_range = 256;

	EXPECT_EQ(toupper(out_of_range), ft_toupper(out_of_range));
}

TEST(toupper, null_char) {
	int	null_char = '\0';

	EXPECT_EQ(toupper(null_char), ft_toupper(null_char));
}

TEST(toupper, all_chars) {
	for (int i = -128; i <= 255; ++i) {
		EXPECT_EQ(toupper(i), ft_toupper(i));
	}
}

TEST(toupper, eof) {
	int	eof = EOF;

	EXPECT_EQ(toupper(eof), ft_toupper(eof));
}
