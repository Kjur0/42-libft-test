/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:39:50 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 16:44:37 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <string.h>

#include <gtest/gtest.h>

TEST(strchr, basic) {
	const char	str[] = "Hello, World!";
	char		c = 'o';

	const char*	c_result = strchr(str, c);
	const char*	ft_result = ft_strchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strchr, not_found) {
	const char	str[] = "Hello, World!";
	char		c = 'x';

	const char*	c_result = strchr(str, c);
	const char*	ft_result = ft_strchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strchr, null_terminator) {
	const char	str[] = "Hello, World!";
	char		c = '\0';

	const char*	c_result = strchr(str, c);
	const char*	ft_result = ft_strchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strchr, empty_string) {
	const char	str[] = "";
	char		c = 'a';

	const char*	c_result = strchr(str, c);
	const char*	ft_result = ft_strchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}

TEST(strchr, multiple_occurrences) {
	const char	str[] = "Hello, World!";
	char		c = 'l';

	const char*	c_result = strchr(str, c);
	const char*	ft_result = ft_strchr(str, c);

	EXPECT_EQ(c_result, ft_result);
}
