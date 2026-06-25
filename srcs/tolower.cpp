/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:57:19 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:54:57 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(tolower, basic)
{
	const int	a = 'a';
	const int	z = 'z';
	const int	A = 'A';
	const int	Z = 'Z';

	const int	c_a = tolower(a);
	const int	ft_a = ft_tolower(a);
	const int	c_z = tolower(z);
	const int	ft_z = ft_tolower(z);
	const int	c_A = tolower(A);
	const int	ft_A = ft_tolower(A);
	const int	c_Z = tolower(Z);
	const int	ft_Z = ft_tolower(Z);

	EXPECT_EQ(c_a, ft_a);
	EXPECT_EQ(c_z, ft_z);
	EXPECT_EQ(c_A, ft_A);
	EXPECT_EQ(c_Z, ft_Z);
}

TEST(tolower, number)
{
	const int	zero = '0';
	const int	nine = '9';

	const int	c_zero = tolower(zero);
	const int	ft_zero = ft_tolower(zero);
	const int	c_nine = tolower(nine);
	const int	ft_nine = ft_tolower(nine);

	EXPECT_EQ(c_zero, ft_zero);
	EXPECT_EQ(c_nine, ft_nine);
}

TEST(tolower, special)
{
	const int	at = '@';
	const int	slash = '/';
	const int	colon = ':';

	const int	c_at = tolower(at);
	const int	ft_at = ft_tolower(at);
	const int	c_slash = tolower(slash);
	const int	ft_slash = ft_tolower(slash);
	const int	c_colon = tolower(colon);
	const int	ft_colon = ft_tolower(colon);

	EXPECT_EQ(c_at, ft_at);
	EXPECT_EQ(c_slash, ft_slash);
	EXPECT_EQ(c_colon, ft_colon);
}

TEST(tolower, non_ascii)
{
	const int	non_ascii = 128;

	const int	c_non_ascii = tolower(non_ascii);
	const int	ft_non_ascii = ft_tolower(non_ascii);

	ASSERT_EQ(c_non_ascii, ft_non_ascii);
}

TEST(tolower, negative)
{
	const int	negative = -12;

	const int	c_negative = tolower(negative);
	const int	ft_negative = ft_tolower(negative);

	ASSERT_EQ(c_negative, ft_negative);
}

TEST(tolower, out_of_range)
{
	const int	out_of_range = 256;

	const int	c_out_of_range = tolower(out_of_range);
	const int	ft_out_of_range = ft_tolower(out_of_range);

	ASSERT_EQ(c_out_of_range, ft_out_of_range);
}

TEST(tolower, null_char)
{
	const int	null_char = '\0';

	const int	c_null_char = tolower(null_char);
	const int	ft_null_char = ft_tolower(null_char);

	ASSERT_EQ(c_null_char, ft_null_char);
}

TEST(tolower, all_chars)
{
	for (int i = -128; i <= 255; ++i)
	{
		const int	c_i = tolower(i);
		const int	ft_i = ft_tolower(i);

		EXPECT_EQ(c_i, ft_i);
	}
}

TEST(tolower, eof)
{
	const int	eof = EOF;

	const int	c_eof = tolower(eof);
	const int	ft_eof = ft_tolower(eof);

	ASSERT_EQ(c_eof, ft_eof);
}
