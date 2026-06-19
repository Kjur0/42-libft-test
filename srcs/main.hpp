/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:28:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/19 19:28:44 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <gtest/gtest.h>

extern "C" {
	#define new n
	#include <libft.h>
	#undef new
}
