/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:56:42 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/21 15:15:31 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <ctype.h>

TEST(isalnum, space)
{
	const char	ch = ' ';

	const int	c = !!isalnum(ch);
	const int	ft = !!ft_isalnum(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalnum, digit)
{
	const char	ch = '5';

	const int	c = !!isalnum(ch);
	const int	ft = !!ft_isalnum(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalnum, lowercase)
{
	const char	ch = 'a';

	const int	c = !!isalnum(ch);
	const int	ft = !!ft_isalnum(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalnum, uppercase)
{
	const char	ch = 'A';

	const int	c = !!isalnum(ch);
	const int	ft = !!ft_isalnum(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalnum, punctuation)
{
	const char	ch = '-';

	const int	c = !!isalnum(ch);
	const int	ft = !!ft_isalnum(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalnum, null_char)
{
	const char	ch = 0;

	const int	c = !!isalnum(ch);
	const int	ft = !!ft_isalnum(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalnum, control_char)
{
	const char	ch = '\r';

	const int	c = !!isalnum(ch);
	const int	ft = !!ft_isalnum(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalnum, non_ascii)
{
	const char	ch = 255;

	const int	c = !!isalnum(ch);
	const int	ft = !!ft_isalnum(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalnum, undefined_behavior)
{
	int	ch = 256 + 'a';
	int	d = 256 + '0';
	int	e = 256 + '-';
	int	f = 256 + ' ';
	int	g = 256 + '\r';
	int	h = -1;

	const int	c_ch = !!isalnum(ch);
	const int	ft_ch = !!ft_isalnum(ch);
	const int	c_d = !!isalnum(d);
	const int	ft_d = !!ft_isalnum(d);
	const int	c_e = !!isalnum(e);
	const int	ft_e = !!ft_isalnum(e);
	const int	c_f = !!isalnum(f);
	const int	ft_f = !!ft_isalnum(f);
	const int	c_g = !!isalnum(g);
	const int	ft_g = !!ft_isalnum(g);
	const int	c_h = !!isalnum(h);
	const int	ft_h = !!ft_isalnum(h);

	EXPECT_EQ(c_ch, ft_ch);
	EXPECT_EQ(c_d, ft_d);
	EXPECT_EQ(c_e, ft_e);
	EXPECT_EQ(c_f, ft_f);
	EXPECT_EQ(c_g, ft_g);
	EXPECT_EQ(c_h, ft_h);
}
