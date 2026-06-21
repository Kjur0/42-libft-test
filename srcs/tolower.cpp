/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:57:19 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/21 15:33:47 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(tolower, basic)
{
	int		a = 'a';
	int		z = 'z';
	int		A = 'A';
	int		Z = 'Z';

	int	c_a = tolower(a);
	int	ft_a = ft_tolower(a);
	int	c_z = tolower(z);
	int	ft_z = ft_tolower(z);
	int	c_A = tolower(A);
	int	ft_A = ft_tolower(A);
	int	c_Z = tolower(Z);
	int	ft_Z = ft_tolower(Z);

	EXPECT_EQ(c_a, ft_a);
	EXPECT_EQ(c_z, ft_z);
	EXPECT_EQ(c_A, ft_A);
	EXPECT_EQ(c_Z, ft_Z);
}

TEST(tolower, number)
{
	int	zero = '0';
	int	nine = '9';

	int	c_zero = tolower(zero);
	int	ft_zero = ft_tolower(zero);
	int	c_nine = tolower(nine);
	int	ft_nine = ft_tolower(nine);

	EXPECT_EQ(c_zero, ft_zero);
	EXPECT_EQ(c_nine, ft_nine);
}

TEST(tolower, special)
{
	int	at = '@';
	int	slash = '/';
	int	colon = ':';

	int	c_at = tolower(at);
	int	ft_at = ft_tolower(at);
	int	c_slash = tolower(slash);
	int	ft_slash = ft_tolower(slash);
	int	c_colon = tolower(colon);
	int	ft_colon = ft_tolower(colon);

	EXPECT_EQ(c_at, ft_at);
	EXPECT_EQ(c_slash, ft_slash);
	EXPECT_EQ(c_colon, ft_colon);
}

TEST(tolower, non_ascii)
{
	int	non_ascii = 128;

	int	c_non_ascii = tolower(non_ascii);
	int	ft_non_ascii = ft_tolower(non_ascii);

	EXPECT_EQ(c_non_ascii, ft_non_ascii);
}

TEST(tolower, negative)
{
	int	negative = -12;

	int	c_negative = tolower(negative);
	int	ft_negative = ft_tolower(negative);

	EXPECT_EQ(c_negative, ft_negative);
}

TEST(tolower, out_of_range)
{
	int	out_of_range = 256;

	int	c_out_of_range = tolower(out_of_range);
	int	ft_out_of_range = ft_tolower(out_of_range);

	EXPECT_EQ(c_out_of_range, ft_out_of_range);
}

TEST(tolower, null_char)
{
	int	null_char = '\0';

	int	c_null_char = tolower(null_char);
	int	ft_null_char = ft_tolower(null_char);

	EXPECT_EQ(c_null_char, ft_null_char);
}

TEST(tolower, all_chars)
{
	for (int i = -128; i <= 255; ++i)
	{
		int	c_i = tolower(i);
		int	ft_i = ft_tolower(i);

		EXPECT_EQ(c_i, ft_i);
	}
}

TEST(tolower, eof)
{
	int	eof = EOF;

	int	c_eof = tolower(eof);
	int	ft_eof = ft_tolower(eof);

	EXPECT_EQ(c_eof, ft_eof);
}
