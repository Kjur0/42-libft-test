/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:57:21 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/23 23:21:11 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(atoi, 0)
{
	const char	str[] = "0";

	const int	c = atoi(str);
	const int	ft = ft_atoi(str);

	EXPECT_EQ(c, ft);
}

TEST(atoi, 1)
{
	const char	str[] = "1";

	const int	c = atoi(str);
	const int	ft = ft_atoi(str);

	EXPECT_EQ(c, ft);
}

TEST(atoi, 42)
{
	const char	str[] = "42";

	const int	c = atoi(str);
	const int	ft = ft_atoi(str);

	EXPECT_EQ(c, ft);
}

TEST(atoi, overflow)
{
	const char	str[] = "2147483648";

	const int	c = atoi(str);
	const int	ft = ft_atoi(str);

	EXPECT_EQ(c, ft);
}

TEST(atoi, underflow)
{
	const char	str[] = "-2147483649";

	const int	c = atoi(str);
	const int	ft = ft_atoi(str);

	EXPECT_EQ(c, ft);
}

TEST(atoi, whitespace)
{
	const char	str[] = "\t\n\v\f\r 42";

	const int	c = atoi(str);
	const int	ft = ft_atoi(str);

	EXPECT_EQ(c, ft);
}

TEST(atoi, plus_sign)
{
	const char	str[] = "+42";

	const int	c = atoi(str);
	const int	ft = ft_atoi(str);

	EXPECT_EQ(c, ft);
}

TEST(atoi, minus_sign)
{
	const char	str[] = "-42";

	const int	c = atoi(str);
	const int	ft = ft_atoi(str);

	EXPECT_EQ(c, ft);
}

TEST(atoi, non_numeric)
{
	const char	str[] = "42abc";

	const int	c = atoi(str);
	const int	ft = ft_atoi(str);

	EXPECT_EQ(c, ft);
}

TEST(atoi, empty_string)
{
	const char	str[] = "";

	const int	c = atoi(str);
	const int	ft = ft_atoi(str);

	EXPECT_EQ(c, ft);
}

TEST(atoi, only_whitespace)
{
	const char	str[] = "\t\n\v\f\r ";

	const int	c = atoi(str);
	const int	ft = ft_atoi(str);

	EXPECT_EQ(c, ft);
}

TEST(atoi, multiple_signs)
{
	const char	str1[] = "--42";
	const char	str2[] = "++42";
	const char	str3[] = "+-42";
	const char	str4[] = "-+42";

	const int	c1 = atoi(str1);
	const int	ft1 = ft_atoi(str1);
	const int	c2 = atoi(str2);
	const int	ft2 = ft_atoi(str2);
	const int	c3 = atoi(str3);
	const int	ft3 = ft_atoi(str3);
	const int	c4 = atoi(str4);
	const int	ft4 = ft_atoi(str4);

	EXPECT_EQ(c1, ft1);
	EXPECT_EQ(c2, ft2);
	EXPECT_EQ(c3, ft3);
	EXPECT_EQ(c4, ft4);
}

TEST(atoi, too_large_number)
{
	const char	str[] = "999999999999999999999999";

	const int	c = atoi(str);
	const int	ft = ft_atoi(str);

	EXPECT_EQ(c, ft);
}

TEST(atoi, too_small_number)
{
	const char	str[] = "-999999999999999999999999";

	const int	c = atoi(str);
	const int	ft = ft_atoi(str);

	EXPECT_EQ(c, ft);
}

TEST(atoiDeathTest, nullptr)
{
	EXPECT_EXIT({
		const char	*str = nullptr;

		ft_atoi(str);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
