/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striteri.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:36:29 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:51:05 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

TEST(striteri, basic)
{
	char	str[] = "0123456789";

	static int	i_r = 0;
	ft_striteri(str, [](unsigned int i, char *c)
	{
		EXPECT_EQ(*c, '0' + i);
		i_r++;
	});
	ASSERT_EQ(i_r, 10);
}

TEST(striteri, empty)
{
	char	str[] = "";

	static int	i_r = 0;
	ft_striteri(str, [](unsigned int i, char *c)
	{
		(void)i;
		(void)c;
		i_r++;
	});

	ASSERT_EQ(i_r, 0);
}

TEST(striteri, change)
{
	char	str[] = "0123456789";

	ft_striteri(str, [](unsigned int i, char *c)
	{
		*c = 'a' + i;
	});

	ASSERT_STREQ(str, "abcdefghij");
}

TEST(striteriDeathTest, nullptr_str)
{
	ASSERT_EXIT({
		char	*str = nullptr;

		ft_striteri(str, [](unsigned int i, char *c)
		{
			*c = *c + i;
		});

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(striteriDeathTest, nullptr_f)
{
	ASSERT_EXIT({
		char	str[] = "Hello";

		ft_striteri(str, nullptr);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
