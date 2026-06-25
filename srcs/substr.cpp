/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:32:30 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:54:35 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

TEST(substr, basic)
{
	const char			*str = "Hello, World!";
	const unsigned int	start = 7;
	const size_t		len = 5;

	char				*res = ft_substr(str, start, len);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res, "World");

	free(res);
}

TEST(substr, start_beyond_length)
{
	const char			*str = "Hello";
	const unsigned int	start = 10;
	const size_t		len = 5;

	char				*res = ft_substr(str, start, len);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res, "");

	free(res);
}

TEST(substr, length_exceeds)
{
	const char			*str = "Hello";
	const unsigned int	start = 1;
	const size_t		len = 10;

	char				*res = ft_substr(str, start, len);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res, "ello");

	free(res);
}

TEST(substr, zero_length)
{
	const char			*str = "Hello";
	const unsigned int	start = 1;
	const size_t		len = 0;

	char				*res = ft_substr(str, start, len);

	ASSERT_NE(res, nullptr);
	ASSERT_STREQ(res, "");

	free(res);
}

TEST(substrDeathTest, nullptr)
{
	ASSERT_EXIT({
		const char			*str = nullptr;
		const unsigned int	start = 1;
		const size_t		len = 5;

		char				*res = ft_substr(str, start, len);

		exit(!!res);
	}, ::testing::ExitedWithCode(0), "");
}
