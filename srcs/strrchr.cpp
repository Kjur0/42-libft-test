/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:39:50 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:47:24 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(strrchr, basic)
{
	const char	*str = "Hello, World!";
	const int	c = 'o';

	const char	*c_result = strrchr(str, c);
	const char	*ft_result = ft_strrchr(str, c);

	ASSERT_EQ(c_result, ft_result);
}

TEST(strrchr, not_found)
{
	const char	*str = "Hello, World!";
	const int	c = 'x';

	const char	*c_result = strrchr(str, c);
	const char	*ft_result = ft_strrchr(str, c);

	ASSERT_EQ(c_result, ft_result);
}

TEST(strrchr, null_terminator)
{
	const char	*str = "Hello, World!";
	const int	c = '\0';

	const char	*c_result = strrchr(str, c);
	const char	*ft_result = ft_strrchr(str, c);

	ASSERT_EQ(c_result, ft_result);
}

TEST(strrchr, empty_string)
{
	const char	*str = "";
	const int	c = 'a';

	const char	*c_result = strrchr(str, c);
	const char	*ft_result = ft_strrchr(str, c);

	ASSERT_EQ(c_result, ft_result);
}

TEST(strrchr, multiple_occurrences)
{
	const char	*str = "Hello, World!";
	const int	c = 'l';

	const char	*c_result = strrchr(str, c);
	const char	*ft_result = ft_strrchr(str, c);

	ASSERT_EQ(c_result, ft_result);
}

TEST(strrchr, non_ascii)
{
	const char	*str = "abc";
	int			c = 256 + 'a'; // 353

	const char	*c_result = strrchr(str, c);
	const char	*ft_result = ft_strrchr(str, c);

	ASSERT_EQ(c_result, ft_result);
}

TEST(strrchrDeathTest, nullptr)
{
	ASSERT_EXIT({
	const char	*str = nullptr;
	const int	c = 1;

	ft_strrchr(str, c);

	exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
