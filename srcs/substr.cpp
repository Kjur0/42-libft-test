/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:32:30 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 19:32:56 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

TEST(substr, basic) {
	char	*str = ft_substr("Hello, World!", 7, 5);

	ASSERT_STREQ(str, "World");

	free(str);
}

TEST(substr, start_beyond_length) {
	char	*str = ft_substr("Hello", 10, 5);

	ASSERT_STREQ(str, "");

	free(str);
}

TEST(substr, length_exceeds) {
	char	*str = ft_substr("Hello", 1, 10);

	ASSERT_STREQ(str, "ello");

	free(str);
}

TEST(substr, zero_length) {
	char	*str = ft_substr("Hello", 1, 0);

	ASSERT_STREQ(str, "");

	free(str);
}
