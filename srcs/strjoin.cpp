/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:42:06 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/24 15:37:43 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

TEST(strjoin, basic)
{
	const char	*s1 = "Hello, ";
	const char	*s2 = "World!";

	char		*res = ft_strjoin(s1, s2);

	ASSERT_STREQ(res, "Hello, World!");

	free(res);
}

TEST(strjoin, empty_first)
{
	const char	*s1 = "";
	const char	*s2 = "World!";

	char		*res = ft_strjoin(s1, s2);

	ASSERT_STREQ(res, "World!");

	free(res);
}

TEST(strjoin, empty_second)
{
	const char	*s1 = "Hello, ";
	const char	*s2 = "";

	char		*res = ft_strjoin(s1, s2);

	ASSERT_STREQ(res, "Hello, ");

	free(res);
}

TEST(strjoin, both_empty)
{
	const char	*s1 = "";
	const char	*s2 = "";

	char		*res = ft_strjoin(s1, s2);

	ASSERT_STREQ(res, "");

	free(res);
}

TEST(strjoinDeathTest, nullptr1)
{
	EXPECT_EXIT({
		const char	*s1 = nullptr;
		const char	*s2 = "Hello";

		char		*res = ft_strjoin(s1, s2);

		const int	res_cmp = strcmp(res, "Hello");

		free(res);

		exit(res_cmp);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(strjoinDeathTest, nullptr2)
{
	EXPECT_EXIT({
		const char	*s1 = "Hello";
		const char	*s2 = nullptr;

		char		*res = ft_strjoin(s1, s2);

		const int	res_cmp = strcmp(res, "Hello");

		free(res);

		exit(res_cmp);
	}, ::testing::ExitedWithCode(0), "");
}
