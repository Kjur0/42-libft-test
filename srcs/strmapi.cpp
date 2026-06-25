/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:40:28 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:53:14 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(strmapi, index)
{
	const char	*str = "9876543210";

	char	*res = ft_strmapi(str, [](unsigned int i, char c) -> char
	{
		(void)c;
		return ('0' + i);
	});

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res, "0123456789");

	free(res);
}

TEST(strmapi, toupper)
{
	const char	*str = "Hello World!";

	char	*res = ft_strmapi(str, [](unsigned int i, char c) -> char
	{
		(void)i;
		return (toupper(c));
	});

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res, "HELLO WORLD!");

	free(res);
}

TEST(strmapi, tolower)
{
	const char	*str = "Hello World!";

	char	*res = ft_strmapi(str, [](unsigned int i, char c) -> char
	{
		(void)i;
		return (tolower(c));
	});

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res, "hello world!");

	free(res);
}

TEST(strmapi, empty)
{
	const char	*str = "";

	char		*res = ft_strmapi(str, [](unsigned int i, char c) -> char
	{
		(void)i;
		return (c);
	});

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res, "");

	free(res);
}

TEST(strmapiDeathTest, nullptr_str)
{
	ASSERT_EXIT({
		const char	*str = nullptr;

		char		*res = ft_strmapi(str, [](unsigned int i, char c) -> char
		{
			(void)i;
			return (c);
		});

		exit(!!res);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(strmapiDeathTest, nullptr_f)
{
	ASSERT_EXIT({
		const char	*str = "HELLO";

		char		*res = ft_strmapi(str, nullptr);

		exit(!!res);
	}, ::testing::ExitedWithCode(0), "");
}
