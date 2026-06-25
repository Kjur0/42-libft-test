/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:56:42 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:48:34 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <ctype.h>

TEST(isprint, space)
{
	const char	ch = ' ';

	const int	c = !!isprint(ch);
	const int	ft = !!ft_isprint(ch);

	ASSERT_EQ(c, ft);
}

TEST(isprint, digit)
{
	const char	ch = '5';

	const int	c = !!isprint(ch);
	const int	ft = !!ft_isprint(ch);

	ASSERT_EQ(c, ft);
}

TEST(isprint, lowercase)
{
	const char	ch = 'a';

	const int	c = !!isprint(ch);
	const int	ft = !!ft_isprint(ch);

	ASSERT_EQ(c, ft);
}

TEST(isprint, uppercase)
{
	const char	ch = 'A';

	const int	c = !!isprint(ch);
	const int	ft = !!ft_isprint(ch);

	ASSERT_EQ(c, ft);
}

TEST(isprint, punctuation)
{
	const char	ch = '-';

	const int	c = !!isprint(ch);
	const int	ft = !!ft_isprint(ch);

	ASSERT_EQ(c, ft);
}

TEST(isprint, null_char)
{
	const char	ch = 0;

	const int	c = !!isprint(ch);
	const int	ft = !!ft_isprint(ch);

	ASSERT_EQ(c, ft);
}

TEST(isprint, control_char)
{
	const char	ch = '\r';

	const int	c = !!isprint(ch);
	const int	ft = !!ft_isprint(ch);

	ASSERT_EQ(c, ft);
}

TEST(isprint, non_ascii)
{
	const char	ch = 255;

	const int	c = !!isprint(ch);
	const int	ft = !!ft_isprint(ch);

	ASSERT_EQ(c, ft);
}

TEST(isprint, undefined_behavior)
{
	int	ch = 256 + 'a';
	int	d = 256 + '0';
	int	e = 256 + '-';
	int	f = 256 + ' ';
	int	g = 256 + '\r';
	int	h = -1;

	const int	c_ch = !!isprint(ch);
	const int	ft_ch = !!ft_isprint(ch);
	const int	c_d = !!isprint(d);
	const int	ft_d = !!ft_isprint(d);
	const int	c_e = !!isprint(e);
	const int	ft_e = !!ft_isprint(e);
	const int	c_f = !!isprint(f);
	const int	ft_f = !!ft_isprint(f);
	const int	c_g = !!isprint(g);
	const int	ft_g = !!ft_isprint(g);
	const int	c_h = !!isprint(h);
	const int	ft_h = !!ft_isprint(h);

	EXPECT_EQ(c_ch, ft_ch);
	EXPECT_EQ(c_d, ft_d);
	EXPECT_EQ(c_e, ft_e);
	EXPECT_EQ(c_f, ft_f);
	EXPECT_EQ(c_g, ft_g);
	EXPECT_EQ(c_h, ft_h);
}
