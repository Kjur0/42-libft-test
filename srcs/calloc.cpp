/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:51:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 20:00:56 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(calloc, basic)
{
	size_t	nmemb = 5;
	size_t	size = sizeof(int);

	int		*c_ptr = (int *)calloc(nmemb, size);
	int		*ft_ptr = (int *)ft_calloc(nmemb, size);

	ASSERT_NE(c_ptr, nullptr);
	ASSERT_NE(ft_ptr, nullptr);
	EXPECT_EQ(memcmp(c_ptr, ft_ptr, nmemb * size), 0);

	free(c_ptr);
	free(ft_ptr);
}

TEST(calloc, zero_nmemb)
{
	size_t	nmemb = 0;
	size_t	size = sizeof(int);

	int		*c_ptr = (int *)calloc(nmemb, size);
	int		*ft_ptr = (int *)ft_calloc(nmemb, size);

	ASSERT_NE(c_ptr, nullptr);
	ASSERT_NE(ft_ptr, nullptr);
	EXPECT_EQ(memcmp(c_ptr, ft_ptr, nmemb * size), 0);

	free(c_ptr);
	free(ft_ptr);
}

TEST(calloc, zero_size)
{
	size_t	nmemb = 5;
	size_t	size = 0;

	int		*c_ptr = (int *)calloc(nmemb, size);
	int		*ft_ptr = (int *)ft_calloc(nmemb, size);

	ASSERT_NE(c_ptr, nullptr);
	ASSERT_NE(ft_ptr, nullptr);
	EXPECT_EQ(memcmp(c_ptr, ft_ptr, nmemb * size), 0);

	free(c_ptr);
	free(ft_ptr);
}

TEST(calloc, overflow)
{
	size_t	nmemb = __SIZE_MAX__;
	size_t	size = 2;

	int		*c_ptr = (int *)calloc(nmemb, size);
	int		*ft_ptr = (int *)ft_calloc(nmemb, size);

	EXPECT_EQ(c_ptr, nullptr);
	EXPECT_EQ(ft_ptr, nullptr);
}
