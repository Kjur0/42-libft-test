/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:56:42 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/21 15:15:43 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <ctype.h>

TEST(isalpha, space)
{
	const char	ch = ' ';

	const int	c = !!isalpha(ch);
	const int	ft = !!ft_isalpha(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalpha, digit)
{
	const char	ch = '5';

	const int	c = !!isalpha(ch);
	const int	ft = !!ft_isalpha(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalpha, lowercase)
{
	const char	ch = 'a';

	const int	c = !!isalpha(ch);
	const int	ft = !!ft_isalpha(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalpha, uppercase)
{
	const char	ch = 'A';

	const int	c = !!isalpha(ch);
	const int	ft = !!ft_isalpha(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalpha, punctuation)
{
	const char	ch = '-';

	const int	c = !!isalpha(ch);
	const int	ft = !!ft_isalpha(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalpha, null_char)
{
	const char	ch = 0;

	const int	c = !!isalpha(ch);
	const int	ft = !!ft_isalpha(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalpha, control_char)
{
	const char	ch = '\r';

	const int	c = !!isalpha(ch);
	const int	ft = !!ft_isalpha(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalpha, non_ascii)
{
	const char	ch = 255;

	const int	c = !!isalpha(ch);
	const int	ft = !!ft_isalpha(ch);

	EXPECT_EQ(c, ft);
}

TEST(isalpha, undefined_behavior)
{
	int	ch = 256 + 'a';
	int	d = 256 + '0';
	int	e = 256 + '-';
	int	f = 256 + ' ';
	int	g = 256 + '\r';
	int	h = -1;

	const int	c_ch = !!isalpha(ch);
	const int	ft_ch = !!ft_isalpha(ch);
	const int	c_d = !!isalpha(d);
	const int	ft_d = !!ft_isalpha(d);
	const int	c_e = !!isalpha(e);
	const int	ft_e = !!ft_isalpha(e);
	const int	c_f = !!isalpha(f);
	const int	ft_f = !!ft_isalpha(f);
	const int	c_g = !!isalpha(g);
	const int	ft_g = !!ft_isalpha(g);
	const int	c_h = !!isalpha(h);
	const int	ft_h = !!ft_isalpha(h);

	EXPECT_EQ(c_ch, ft_ch);
	EXPECT_EQ(c_d, ft_d);
	EXPECT_EQ(c_e, ft_e);
	EXPECT_EQ(c_f, ft_f);
	EXPECT_EQ(c_g, ft_g);
	EXPECT_EQ(c_h, ft_h);
}
