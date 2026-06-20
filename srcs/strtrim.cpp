/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:04:08 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 11:48:35 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

TEST(strtrim, basic) {
	const char	*set = " \n\t";
	const char	*str = " \n\tHello, World!\n\t ";

	char		*result = ft_strtrim(str, set);

	ASSERT_STREQ(result, "Hello, World!");

	free(result);
}

TEST(strtrim, no_trim) {
	const char	*set = " \n\t";
	const char	*str = "Hello, World!";

	char		*result = ft_strtrim(str, set);

	ASSERT_STREQ(result, "Hello, World!");

	free(result);
}

TEST(strtrim, all_trim) {
	const char	*set = " \n\t";
	const char	*str = " \n\t \n\t";

	char		*result = ft_strtrim(str, set);

	ASSERT_STREQ(result, "");

	free(result);
}

TEST(strtrim, empty_set) {
	const char	*set = "";
	const char	*str = "Hello, World!";

	char		*result = ft_strtrim(str, set);

	ASSERT_STREQ(result, "Hello, World!");

	free(result);
}
