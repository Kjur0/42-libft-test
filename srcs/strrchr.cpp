/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:39:50 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 21:50:49 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <string.h>

TEST(strrchr, basic) {
	const char	str[] = "Hello, World!";
	char		c = 'o';

	const char*	c_result = strrchr(str, c);
	const char*	ft_result = ft_strrchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strrchr, not_found) {
	const char	str[] = "Hello, World!";
	char		c = 'x';

	const char*	c_result = strrchr(str, c);
	const char*	ft_result = ft_strrchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strrchr, null_terminator) {
	const char	str[] = "Hello, World!";
	char		c = '\0';

	const char*	c_result = strrchr(str, c);
	const char*	ft_result = ft_strrchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strrchr, empty_string) {
	const char	str[] = "";
	char		c = 'a';

	const char*	c_result = strrchr(str, c);
	const char*	ft_result = ft_strrchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strrchr, multiple_occurrences) {
	const char	str[] = "Hello, World!";
	char		c = 'l';

	const char*	c_result = strrchr(str, c);
	const char*	ft_result = ft_strrchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strrchr, non_ascii) {
	const char	str[] = "abc";
	int			c = 256 + 'a'; // 353

	const char*	c_result = strrchr(str, c);
	const char*	ft_result = ft_strrchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}
