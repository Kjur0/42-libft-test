/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:56:42 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/21 15:16:04 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <ctype.h>

TEST(isdigit, space)
{
	const char	ch = ' ';

	const int	c = !!isdigit(ch);
	const int	ft = !!ft_isdigit(ch);

	EXPECT_EQ(c, ft);
}

TEST(isdigit, digit)
{
	const char	ch = '5';

	const int	c = !!isdigit(ch);
	const int	ft = !!ft_isdigit(ch);

	EXPECT_EQ(c, ft);
}

TEST(isdigit, lowercase)
{
	const char	ch = 'a';

	const int	c = !!isdigit(ch);
	const int	ft = !!ft_isdigit(ch);

	EXPECT_EQ(c, ft);
}

TEST(isdigit, uppercase)
{
	const char	ch = 'A';

	const int	c = !!isdigit(ch);
	const int	ft = !!ft_isdigit(ch);

	EXPECT_EQ(c, ft);
}

TEST(isdigit, punctuation)
{
	const char	ch = '-';

	const int	c = !!isdigit(ch);
	const int	ft = !!ft_isdigit(ch);

	EXPECT_EQ(c, ft);
}

TEST(isdigit, null_char)
{
	const char	ch = 0;

	const int	c = !!isdigit(ch);
	const int	ft = !!ft_isdigit(ch);

	EXPECT_EQ(c, ft);
}

TEST(isdigit, control_char)
{
	const char	ch = '\r';

	const int	c = !!isdigit(ch);
	const int	ft = !!ft_isdigit(ch);

	EXPECT_EQ(c, ft);
}

TEST(isdigit, non_ascii)
{
	const char	ch = 255;

	const int	c = !!isdigit(ch);
	const int	ft = !!ft_isdigit(ch);

	EXPECT_EQ(c, ft);
}

TEST(isdigit, undefined_behavior)
{
	int	ch = 256 + 'a';
	int	d = 256 + '0';
	int	e = 256 + '-';
	int	f = 256 + ' ';
	int	g = 256 + '\r';
	int	h = -1;

	const int	c_ch = !!isdigit(ch);
	const int	ft_ch = !!ft_isdigit(ch);
	const int	c_d = !!isdigit(d);
	const int	ft_d = !!ft_isdigit(d);
	const int	c_e = !!isdigit(e);
	const int	ft_e = !!ft_isdigit(e);
	const int	c_f = !!isdigit(f);
	const int	ft_f = !!ft_isdigit(f);
	const int	c_g = !!isdigit(g);
	const int	ft_g = !!ft_isdigit(g);
	const int	c_h = !!isdigit(h);
	const int	ft_h = !!ft_isdigit(h);

	EXPECT_EQ(c_ch, ft_ch);
	EXPECT_EQ(c_d, ft_d);
	EXPECT_EQ(c_e, ft_e);
	EXPECT_EQ(c_f, ft_f);
	EXPECT_EQ(c_g, ft_g);
	EXPECT_EQ(c_h, ft_h);
}
