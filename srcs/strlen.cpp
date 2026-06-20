/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:54:17 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 11:48:35 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(strlen, basic) {
	const char*	str = "Hello, World!";

	size_t		c_len = strlen(str);
	size_t		ft_len = ft_strlen(str);

	EXPECT_EQ(c_len, ft_len);
}

TEST(strlen, empty_string) {
	const char*	str = "";

	size_t		c_len = strlen(str);
	size_t		ft_len = ft_strlen(str);

	EXPECT_EQ(c_len, ft_len);
}

TEST(strlen, long_string) {
	const char*	str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

	size_t		c_len = strlen(str);
	size_t		ft_len = ft_strlen(str);

	EXPECT_EQ(c_len, ft_len);
}

TEST(strlen, string_with_null_char) {
	const char	str[] = "Hello\0World";

	size_t		c_len = strlen(str);
	size_t		ft_len = ft_strlen(str);

	EXPECT_EQ(c_len, ft_len);
}
