/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:39:50 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/23 23:06:58 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(strchr, basic)
{
	const char	*str = "Hello, World!";
	const int	c = 'o';

	const char	*c_result = strchr(str, c);
	const char	*ft_result = ft_strchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strchr, not_found)
{
	const char	*str = "Hello, World!";
	const int	c = 'x';

	const char	*c_result = strchr(str, c);
	const char	*ft_result = ft_strchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strchr, null_terminator)
{
	const char	*str = "Hello, World!";
	const int	c = '\0';

	const char	*c_result = strchr(str, c);
	const char	*ft_result = ft_strchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strchr, empty_string)
{
	const char	*str = "";
	const int	c = 'a';

	const char	*c_result = strchr(str, c);
	const char	*ft_result = ft_strchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strchr, multiple_occurrences)
{
	const char	*str = "Hello, World!";
	const int	c = 'l';

	const char	*c_result = strchr(str, c);
	const char	*ft_result = ft_strchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strchr, non_ascii)
{
	const char	*str = "abc";
	const int	c = 256 + 'a'; // 353

	const char	*c_result = strchr(str, c);
	const char	*ft_result = ft_strchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strchrDeathTest, nullptr)
{
	EXPECT_EXIT({
	const char	*str = nullptr;
	const int	c = 1;

	ft_strchr(str, c);

	exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
