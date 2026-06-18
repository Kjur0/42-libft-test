/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:28:55 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 12:35:46 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

int	main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return (RUN_ALL_TESTS());
}
