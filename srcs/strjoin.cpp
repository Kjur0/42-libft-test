/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:42:06 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 16:06:01 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}

#include <gtest/gtest.h>

TEST(strjoin, basic) {
	char	s1[] = "Hello, ";
	char	s2[] = "World!";

	char	*result = ft_strjoin(s1, s2);

	ASSERT_STREQ(result, "Hello, World!");

	free(result);
}

TEST(strjoin, empty_first) {
	char	s1[] = "";
	char	s2[] = "World!";

	char	*result = ft_strjoin(s1, s2);

	ASSERT_STREQ(result, "World!");

	free(result);
}

TEST(strjoin, empty_second) {
	char	s1[] = "Hello, ";
	char	s2[] = "";

	char	*result = ft_strjoin(s1, s2);

	ASSERT_STREQ(result, "Hello, ");

	free(result);
}

TEST(strjoin, both_empty) {
	char	s1[] = "";
	char	s2[] = "";

	char	*result = ft_strjoin(s1, s2);

	ASSERT_STREQ(result, "");

	free(result);
}
