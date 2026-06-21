/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:51:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/21 14:30:18 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(calloc, basic)
{
	EXPECT_EXIT({
		size_t	nmemb = 5;
		size_t	size = sizeof(int);

		int		*c_ptr = (int *)calloc(nmemb, size);
		int		*ft_ptr = (int *)ft_calloc(nmemb, size);

		exit(memcmp(c_ptr, ft_ptr, nmemb * size));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(calloc, zero_nmemb)
{
	EXPECT_EXIT({
		size_t	nmemb = 0;
		size_t	size = sizeof(int);

		int		*c_ptr = (int *)calloc(nmemb, size);
		int		*ft_ptr = (int *)ft_calloc(nmemb, size);

		exit(memcmp(c_ptr, ft_ptr, nmemb * size));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(calloc, zero_size)
{
	EXPECT_EXIT({
		size_t	nmemb = 5;
		size_t	size = 0;

		int		*c_ptr = (int *)calloc(nmemb, size);
		int		*ft_ptr = (int *)ft_calloc(nmemb, size);

		exit(memcmp(c_ptr, ft_ptr, nmemb * size));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(calloc, overflow)
{
	EXPECT_EXIT({
		size_t	nmemb = __SIZE_MAX__;
		size_t	size = 2;

		int		*c_ptr = (int *)calloc(nmemb, size);
		int		*ft_ptr = (int *)ft_calloc(nmemb, size);

		exit((size_t)c_ptr != (size_t)ft_ptr);
	}, ::testing::ExitedWithCode(0), "");
}
