/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:04:08 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:54:18 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

TEST(strtrim, basic)
{
	const char	*set = " \n\t";
	const char	*str = " \n\tHello, World!\n\t ";

	char		*res = ft_strtrim(str, set);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res, "Hello, World!");

	free(res);
}

TEST(strtrim, no_trim)
{
	const char	*set = " \n\t";
	const char	*str = "Hello, World!";

	char		*res = ft_strtrim(str, set);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res, "Hello, World!");

	free(res);
}

TEST(strtrim, all_trim)
{
	const char	*set = " \n\t";
	const char	*str = " \n\t \n\t";

	char		*res = ft_strtrim(str, set);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res, "");

	free(res);
}

TEST(strtrim, empty_set)
{
	const char	*set = "";
	const char	*str = "Hello, World!";

	char		*res = ft_strtrim(str, set);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res, "Hello, World!");

	free(res);
}

TEST(strtrimDeathTest, nullptr_set)
{
	ASSERT_EXIT({
		const char	*set = nullptr;
		const char	*str = "Hello, World!";

		char		*res = ft_strtrim(str, set);

		const int	res_cmp = strcmp(res, "Hello, World!");

		free(res);

		exit(res_cmp);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(strtrimDeathTest, nullptr_str)
{
	ASSERT_EXIT({
		const char	*set = " \t";
		const char	*str = nullptr;

		char		*res = ft_strtrim(str, set);

		exit(!!res);
	}, ::testing::ExitedWithCode(0), "");
}
