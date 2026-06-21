/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:57:19 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/21 15:34:09 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(toupper, basic)
{
	int		a = 'a';
	int		z = 'z';
	int		A = 'A';
	int		Z = 'Z';

	int	c_a = toupper(a);
	int	ft_a = ft_toupper(a);
	int	c_z = toupper(z);
	int	ft_z = ft_toupper(z);
	int	c_A = toupper(A);
	int	ft_A = ft_toupper(A);
	int	c_Z = toupper(Z);
	int	ft_Z = ft_toupper(Z);

	EXPECT_EQ(c_a, ft_a);
	EXPECT_EQ(c_z, ft_z);
	EXPECT_EQ(c_A, ft_A);
	EXPECT_EQ(c_Z, ft_Z);
}

TEST(toupper, number)
{
	int	zero = '0';
	int	nine = '9';

	int	c_zero = toupper(zero);
	int	ft_zero = ft_toupper(zero);
	int	c_nine = toupper(nine);
	int	ft_nine = ft_toupper(nine);

	EXPECT_EQ(c_zero, ft_zero);
	EXPECT_EQ(c_nine, ft_nine);
}

TEST(toupper, special)
{
	int	at = '@';
	int	slash = '/';
	int	colon = ':';

	int	c_at = toupper(at);
	int	ft_at = ft_toupper(at);
	int	c_slash = toupper(slash);
	int	ft_slash = ft_toupper(slash);
	int	c_colon = toupper(colon);
	int	ft_colon = ft_toupper(colon);

	EXPECT_EQ(c_at, ft_at);
	EXPECT_EQ(c_slash, ft_slash);
	EXPECT_EQ(c_colon, ft_colon);
}

TEST(toupper, non_ascii)
{
	int	non_ascii = 128;

	int	c_non_ascii = toupper(non_ascii);
	int	ft_non_ascii = ft_toupper(non_ascii);

	EXPECT_EQ(c_non_ascii, ft_non_ascii);
}

TEST(toupper, negative)
{
	int	negative = -12;

	int	c_negative = toupper(negative);
	int	ft_negative = ft_toupper(negative);

	EXPECT_EQ(c_negative, ft_negative);
}

TEST(toupper, out_of_range)
{
	int	out_of_range = 256;

	int	c_out_of_range = toupper(out_of_range);
	int	ft_out_of_range = ft_toupper(out_of_range);

	EXPECT_EQ(c_out_of_range, ft_out_of_range);
}

TEST(toupper, null_char)
{
	int	null_char = '\0';

	int	c_null_char = toupper(null_char);
	int	ft_null_char = ft_toupper(null_char);

	EXPECT_EQ(c_null_char, ft_null_char);
}

TEST(toupper, all_chars)
{
	for (int i = -128; i <= 255; ++i)
	{
		int	c_i = toupper(i);
		int	ft_i = ft_toupper(i);

		EXPECT_EQ(c_i, ft_i);
	}
}

TEST(toupper, eof)
{
	int	eof = EOF;

	int	c_eof = toupper(eof);
	int	ft_eof = ft_toupper(eof);

	EXPECT_EQ(c_eof, ft_eof);
}
