/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striteri.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:36:29 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 13:39:52 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}

#include <gtest/gtest.h>

TEST(striteri, basic) {
	char	str[] = "0123456789";

	ft_striteri(str, [](unsigned int i, char c) {
		EXPECT_EQ(c, '0' + i);
	});
}
