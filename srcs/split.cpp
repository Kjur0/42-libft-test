/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:11:47 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 21:14:35 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

TEST(split, basic) {
	char	**result = ft_split("Hello World!", ' ');
	
	EXPECT_STREQ(result[0], "Hello");
	EXPECT_STREQ(result[1], "World!");
	EXPECT_EQ(result[2], nullptr);

	free(result[0]);
	free(result[1]);
}

TEST(split, empty_string) {
	char	**result = ft_split("", ' ');

	EXPECT_EQ(result[0], nullptr);
}

TEST(split, only_delimiters) {
	char	**result = ft_split("   ", ' ');

	EXPECT_EQ(result[0], nullptr);
}

TEST(split, multiple_delimiters) {
	char	**result = ft_split("Hello   World!", ' ');

	EXPECT_STREQ(result[0], "Hello");
	EXPECT_STREQ(result[1], "World!");
	EXPECT_EQ(result[2], nullptr);

	free(result[0]);
	free(result[1]);
}

TEST(split, no_delimiters) {
	char	**result = ft_split("HelloWorld!", ' ');

	EXPECT_STREQ(result[0], "HelloWorld!");
	EXPECT_EQ(result[1], nullptr);

	free(result[0]);
}

TEST(split, null_delimiter) {
	char	**result = ft_split("Hello World!", '\0');

	EXPECT_STREQ(result[0], "Hello World!");
	EXPECT_EQ(result[1], nullptr);

	free(result[0]);
}

TEST(split, consecutive) {
	char	**result = ft_split("Hello,,World!", ',');

	EXPECT_STREQ(result[0], "Hello");
	EXPECT_STREQ(result[1], "World!");
	EXPECT_EQ(result[2], nullptr);

	free(result[0]);
	free(result[1]);
}

TEST(split, edges) {
	char **result = ft_split(",Hello,World!,", ',');

	EXPECT_STREQ(result[0], "Hello");
	EXPECT_STREQ(result[1], "World!");
	EXPECT_EQ(result[2], nullptr);

	free(result[0]);
	free(result[1]);
}
