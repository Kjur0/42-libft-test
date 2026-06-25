/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:42:14 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:50:52 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(strdup, basic)
{
	const char	*str = "Hello, World!";

	char		*c = strdup(str);
	char		*ft = ft_strdup(str);

	ASSERT_NE(ft, nullptr);
	ASSERT_STREQ(c, ft);

	free(c);
	free(ft);
}

TEST(strdup, empty_string)
{
	const char	*str = "";

	char		*c = strdup(str);
	char		*ft = ft_strdup(str);

	ASSERT_NE(ft, nullptr);
	ASSERT_STREQ(c, ft);

	free(c);
	free(ft);
}

TEST(strdup, long_string)
{
	const char	*str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

	char		*c = strdup(str);
	char		*ft = ft_strdup(str);

	ASSERT_NE(ft, nullptr);
	ASSERT_STREQ(c, ft);

	free(c);
	free(ft);
}

TEST(strdup, string_with_null_char)
{
	const char	*str = "Hello\0World";

	char		*c = strdup(str);
	char		*ft = ft_strdup(str);

	ASSERT_NE(ft, nullptr);
	ASSERT_STREQ(c, ft);

	free(c);
	free(ft);
}

TEST(strdupDeathTest, nullptr)
{
	ASSERT_EXIT(
	{
		const char	*str = nullptr;

		char		*ft = ft_strdup(str);

		exit(!!ft);
	}, ::testing::ExitedWithCode(0), "");
}
