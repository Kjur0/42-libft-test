/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:40:28 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 19:32:34 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <string.h>

TEST(strmapi, index) {
	char	str[] = "9876543210";
	char	*result = ft_strmapi(str, [](unsigned int i, char c) -> char {
		(void)c;
		return ('0' + i);
	});
	EXPECT_STREQ(result, "0123456789");
	free(result);
}

TEST(strmapi, toupper) {
	char	str[] = "Hello World!";
	char	*result = ft_strmapi(str, [](unsigned int i, char c) -> char {
		(void)i;
		return (toupper(c));
	});
	EXPECT_STREQ(result, "HELLO WORLD!");
	free(result);
}

TEST(strmapi, tolower) {
	char	str[] = "Hello World!";
	char	*result = ft_strmapi(str, [](unsigned int i, char c) -> char {
		(void)i;
		return (tolower(c));
	});
	EXPECT_STREQ(result, "hello world!");
	free(result);
}

TEST(strmapi, empty) {
	char	str[] = "";
	char	*result = ft_strmapi(str, [](unsigned int i, char c) -> char {
		(void)i;
		return (c);
	});
	EXPECT_STREQ(result, "");
	free(result);
}
