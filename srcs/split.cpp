/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:11:47 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:50:24 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

TEST(split, basic)
{
	const char	*str = "Hello World!";
	const char	c = ' ';

	char		**res = ft_split(str, c);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res[0], "Hello");
	ASSERT_STREQ(res[1], "World!");
	ASSERT_EQ(res[2], nullptr);

	free(res[0]);
	free(res[1]);
}

TEST(split, empty_string)
{
	const char	*str = "";
	const char	c = ' ';

	char		**res = ft_split(str, c);

	ASSERT_NE(res, nullptr);
	ASSERT_EQ(res[0], nullptr);
}

TEST(split, only_delimiters)
{
	const char	*str = "   ";
	const char	c = ' ';

	char		**res = ft_split(str, c);

	ASSERT_NE(res, nullptr);
	ASSERT_EQ(res[0], nullptr);
}

TEST(split, multiple_delimiters)
{
	const char	*str = "Hello   World!";
	const char	c = ' ';

	char		**res = ft_split(str, c);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res[0], "Hello");
	ASSERT_STREQ(res[1], "World!");
	ASSERT_EQ(res[2], nullptr);

	free(res[0]);
	free(res[1]);
}

TEST(split, no_delimiters)
{
	const char	*str = "HelloWorld!";
	const char	c = ' ';

	char		**res = ft_split(str, c);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res[0], "HelloWorld!");
	ASSERT_EQ(res[1], nullptr);

	free(res[0]);
}

TEST(split, null_delimiter)
{
	const char	*str = "Hello World!";
	const char	c = '\0';

	char		**res = ft_split(str, c);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res[0], "Hello World!");
	ASSERT_EQ(res[1], nullptr);

	free(res[0]);
}

TEST(split, consecutive)
{
	const char	*str = "Hello,,World!";
	const char	c = ',';

	char		**res = ft_split(str, c);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res[0], "Hello");
	ASSERT_STREQ(res[1], "World!");
	ASSERT_EQ(res[2], nullptr);

	free(res[0]);
	free(res[1]);
}

TEST(split, edges)
{
	const char	*str = ",Hello,World!,";
	const char	c = ',';

	char 		**res = ft_split(str, c);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res[0], "Hello");
	ASSERT_STREQ(res[1], "World!");
	ASSERT_EQ(res[2], nullptr);

	free(res[0]);
	free(res[1]);
}

TEST(splitDeathTest, nullptr)
{
	ASSERT_EXIT({
		const char	*str = nullptr;
		const char	c = ' ';

		char		**res = ft_split(str, c);

		exit(!!res);
	}, ::testing::ExitedWithCode(0), "");
}
