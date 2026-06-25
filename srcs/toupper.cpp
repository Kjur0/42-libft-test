/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:57:19 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:55:21 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(toupper, basic)
{
	const int	a = 'a';
	const int	z = 'z';
	const int	A = 'A';
	const int	Z = 'Z';

	const int	c_a = toupper(a);
	const int	ft_a = ft_toupper(a);
	const int	c_z = toupper(z);
	const int	ft_z = ft_toupper(z);
	const int	c_A = toupper(A);
	const int	ft_A = ft_toupper(A);
	const int	c_Z = toupper(Z);
	const int	ft_Z = ft_toupper(Z);

	EXPECT_EQ(c_a, ft_a);
	EXPECT_EQ(c_z, ft_z);
	EXPECT_EQ(c_A, ft_A);
	EXPECT_EQ(c_Z, ft_Z);
}

TEST(toupper, number)
{
	const int	zero = '0';
	const int	nine = '9';

	const int	c_zero = toupper(zero);
	const int	ft_zero = ft_toupper(zero);
	const int	c_nine = toupper(nine);
	const int	ft_nine = ft_toupper(nine);

	EXPECT_EQ(c_zero, ft_zero);
	EXPECT_EQ(c_nine, ft_nine);
}

TEST(toupper, special)
{
	const int	at = '@';
	const int	slash = '/';
	const int	colon = ':';

	const int	c_at = toupper(at);
	const int	ft_at = ft_toupper(at);
	const int	c_slash = toupper(slash);
	const int	ft_slash = ft_toupper(slash);
	const int	c_colon = toupper(colon);
	const int	ft_colon = ft_toupper(colon);

	EXPECT_EQ(c_at, ft_at);
	EXPECT_EQ(c_slash, ft_slash);
	EXPECT_EQ(c_colon, ft_colon);
}

TEST(toupper, non_ascii)
{
	const int	non_ascii = 128;

	const int	c_non_ascii = toupper(non_ascii);
	const int	ft_non_ascii = ft_toupper(non_ascii);

	ASSERT_EQ(c_non_ascii, ft_non_ascii);
}

TEST(toupper, negative)
{
	const int	negative = -12;

	const int	c_negative = toupper(negative);
	const int	ft_negative = ft_toupper(negative);

	ASSERT_EQ(c_negative, ft_negative);
}

TEST(toupper, out_of_range)
{
	const int	out_of_range = 256;

	const int	c_out_of_range = toupper(out_of_range);
	const int	ft_out_of_range = ft_toupper(out_of_range);

	ASSERT_EQ(c_out_of_range, ft_out_of_range);
}

TEST(toupper, null_char)
{
	const int	null_char = '\0';

	const int	c_null_char = toupper(null_char);
	const int	ft_null_char = ft_toupper(null_char);

	ASSERT_EQ(c_null_char, ft_null_char);
}

TEST(toupper, all_chars)
{
	for (int i = -128; i <= 255; ++i)
	{
		const int	c_i = toupper(i);
		const int	ft_i = ft_toupper(i);

		EXPECT_EQ(c_i, ft_i);
	}
}

TEST(toupper, eof)
{
	const int	eof = EOF;

	const int	c_eof = toupper(eof);
	const int	ft_eof = ft_toupper(eof);

	ASSERT_EQ(c_eof, ft_eof);
}
