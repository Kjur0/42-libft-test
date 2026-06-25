/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:56:42 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:48:22 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <ctype.h>

TEST(isascii, space)
{
	const char	ch = ' ';

	const int	c = !!isascii(ch);
	const int	ft = !!ft_isascii(ch);

	ASSERT_EQ(c, ft);
}

TEST(isascii, digit)
{
	const char	ch = '5';

	const int	c = !!isascii(ch);
	const int	ft = !!ft_isascii(ch);

	ASSERT_EQ(c, ft);
}

TEST(isascii, lowercase)
{
	const char	ch = 'a';

	const int	c = !!isascii(ch);
	const int	ft = !!ft_isascii(ch);

	ASSERT_EQ(c, ft);
}

TEST(isascii, uppercase)
{
	const char	ch = 'A';

	const int	c = !!isascii(ch);
	const int	ft = !!ft_isascii(ch);

	ASSERT_EQ(c, ft);
}

TEST(isascii, punctuation)
{
	const char	ch = '-';

	const int	c = !!isascii(ch);
	const int	ft = !!ft_isascii(ch);

	ASSERT_EQ(c, ft);
}

TEST(isascii, null_char)
{
	const char	ch = 0;

	const int	c = !!isascii(ch);
	const int	ft = !!ft_isascii(ch);

	ASSERT_EQ(c, ft);
}

TEST(isascii, control_char)
{
	const char	ch = '\r';

	const int	c = !!isascii(ch);
	const int	ft = !!ft_isascii(ch);

	ASSERT_EQ(c, ft);
}

TEST(isascii, non_ascii)
{
	const char	ch = 255;

	const int	c = !!isascii(ch);
	const int	ft = !!ft_isascii(ch);

	ASSERT_EQ(c, ft);
}

TEST(isascii, undefined_behavior)
{
	int	ch = 256 + 'a';
	int	d = 256 + '0';
	int	e = 256 + '-';
	int	f = 256 + ' ';
	int	g = 256 + '\r';
	int	h = -1;

	const int	c_ch = !!isascii(ch);
	const int	ft_ch = !!ft_isascii(ch);
	const int	c_d = !!isascii(d);
	const int	ft_d = !!ft_isascii(d);
	const int	c_e = !!isascii(e);
	const int	ft_e = !!ft_isascii(e);
	const int	c_f = !!isascii(f);
	const int	ft_f = !!ft_isascii(f);
	const int	c_g = !!isascii(g);
	const int	ft_g = !!ft_isascii(g);
	const int	c_h = !!isascii(h);
	const int	ft_h = !!ft_isascii(h);

	EXPECT_EQ(c_ch, ft_ch);
	EXPECT_EQ(c_d, ft_d);
	EXPECT_EQ(c_e, ft_e);
	EXPECT_EQ(c_f, ft_f);
	EXPECT_EQ(c_g, ft_g);
	EXPECT_EQ(c_h, ft_h);
}
