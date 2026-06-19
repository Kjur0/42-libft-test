/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:42:14 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 19:32:02 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <string.h>

TEST(strdup, basic) {
	const char*	str = "Hello, World!";

	char*		c = strdup(str);
	char*		ft = ft_strdup(str);

	EXPECT_STREQ(c, ft);

	free(c);
	free(ft);
}

TEST(strdup, empty_string) {
	const char*	str = "";

	char*		c = strdup(str);
	char*		ft = ft_strdup(str);

	EXPECT_STREQ(c, ft);

	free(c);
	free(ft);
}

TEST(strdup, long_string) {
	const char*	str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

	char*		c = strdup(str);
	char*		ft = ft_strdup(str);

	EXPECT_STREQ(c, ft);

	free(c);
	free(ft);
}

TEST(strdup, string_with_null_char) {
	const char	str[] = "Hello\0World";

	char*		c = strdup(str);
	char*		ft = ft_strdup(str);

	EXPECT_STREQ(c, ft);

	free(c);
	free(ft);
}
