/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:51:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:57:05 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(calloc, basic)
{
	ASSERT_EXIT({
		const size_t	nmemb = 5;
		const size_t	size = sizeof(int);

		int				*c_ptr = (int *)calloc(nmemb, size);
		int				*ft_ptr = (int *)ft_calloc(nmemb, size);

		const int		res = memcmp(c_ptr, ft_ptr, nmemb * size);

		free(c_ptr);
		free(ft_ptr);

		exit(res);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(calloc, zero_nmemb)
{
	ASSERT_EXIT({
		const size_t	nmemb = 0;
		const size_t	size = sizeof(int);

		int				*c_ptr = (int *)calloc(nmemb, size);
		int				*ft_ptr = (int *)ft_calloc(nmemb, size);

		free(c_ptr);
		free(ft_ptr);

		exit((c_ptr || ft_ptr) && !(c_ptr && ft_ptr));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(calloc, zero_size)
{
	ASSERT_EXIT({
		const size_t	nmemb = 5;
		const size_t	size = 0;

		int				*c_ptr = (int *)calloc(nmemb, size);
		int				*ft_ptr = (int *)ft_calloc(nmemb, size);

		free(c_ptr);
		free(ft_ptr);

		exit((c_ptr || ft_ptr) && !(c_ptr && ft_ptr));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(calloc, overflow)
{
	ASSERT_EXIT({
		const size_t	nmemb = __SIZE_MAX__;
		const size_t	size = sizeof(int);

		const int		*ft_ptr = (int *)ft_calloc(nmemb, size);

		exit(!!ft_ptr);
	}, ::testing::ExitedWithCode(0), "");
}
