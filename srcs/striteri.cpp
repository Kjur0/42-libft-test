/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striteri.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:36:29 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 20:45:21 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

TEST(striteri, basic) {
	char		str[] = "0123456789";
	static int	i_r = 0;

	ft_striteri(str, [](unsigned int i, char c) {
		EXPECT_EQ(c, '0' + i);
		i_r++;
	});
	EXPECT_EQ(i_r, 10);
}
