/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:20:48 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:47:24 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(memcpy, basic)
{
	ASSERT_EXIT({
		const char		str[] = "Hello, world!";
		const size_t	n = 14;
		char			c[n];
		char			ft[n];

		memcpy(c, str, n);
		ft_memcpy(ft, str, n);

		exit(memcmp(c, ft, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memcpy, zero_length)
{
	ASSERT_EXIT({
		const char		str[] = "Hello, world!";
		const size_t	n = 0;
		char			c[n];
		char			ft[n];

		memcpy(c, str, n);
		ft_memcpy(ft, str, n);

		exit(memcmp(c, ft, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memcpy, null_char)
{
	ASSERT_EXIT({
		const char		str[] = "Hello\0world!";
		const size_t	n = 13;
		char			c[n];
		char			ft[n];

		memcpy(c, str, n);
		ft_memcpy(ft, str, n);

		exit(memcmp(c, ft, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memcpy, partial_length)
{
	ASSERT_EXIT({
		const char		str[] = "Hello, world!";
		const size_t	n = 5;
		char			c[n];
		char			ft[n];

		memcpy(c, str, n);
		ft_memcpy(ft, str, n);

		exit(memcmp(c, ft, n));
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memcpyDeathTest, nullptr_dst)
{
	ASSERT_EXIT({
		const char		*str = "Hello, world!";
		const size_t	n = 5;
		char			*ft = nullptr;

		ft_memcpy(ft, str, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(memcpyDeathTest, nullptr_src)
{
	ASSERT_EXIT({
		const char		*str = nullptr;
		const size_t	n = 5;
		char			ft[6];

		ft_memcpy(ft, str, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
