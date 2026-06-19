/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:04:08 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 16:05:33 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}

#include <gtest/gtest.h>

TEST(strtrim, basic) {
	const char	*set = " \n\t";
	const char	*str = " \n\tHello, World!\n\t ";

	char		*result = ft_strtrim(str, set);

	ASSERT_STREQ(result, "Hello, World!");
	
	free(result);
}
