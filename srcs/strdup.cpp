/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:42:14 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/23 23:24:00 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(strdup, basic)
{
	const char	*str = "Hello, World!";

	char		*c = strdup(str);
	char		*ft = ft_strdup(str);

	EXPECT_STREQ(c, ft);

	free(c);
	free(ft);
}

TEST(strdup, empty_string)
{
	const char	*str = "";

	char		*c = strdup(str);
	char		*ft = ft_strdup(str);

	EXPECT_STREQ(c, ft);

	free(c);
	free(ft);
}

TEST(strdup, long_string)
{
	const char	*str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

	char		*c = strdup(str);
	char		*ft = ft_strdup(str);

	EXPECT_STREQ(c, ft);

	free(c);
	free(ft);
}

TEST(strdup, string_with_null_char)
{
	const char	*str = "Hello\0World";

	char		*c = strdup(str);
	char		*ft = ft_strdup(str);

	EXPECT_STREQ(c, ft);

	free(c);
	free(ft);
}

TEST(strdupDeathTest, nullptr)
{
	EXPECT_EXIT(
	{
		const char	*str = nullptr;

		ft_strdup(str);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
