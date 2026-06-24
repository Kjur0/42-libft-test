/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:24:53 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/24 16:29:49 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <string.h>

TEST(memchr, basic)
{
	const char		*str = "Hello, world!";
	const int		ch = 'o';
	const size_t	n = 14;

	const char	*c = reinterpret_cast<const char *>(memchr(str, ch, n));
	const char	*ft = reinterpret_cast<const char *>(ft_memchr(str, ch, n));

	EXPECT_EQ(c, ft);
}

TEST(memchr, not_found)
{
	const char		*str = "Hello, world!";
	const int		ch = 'x';
	const size_t	n = 14;

	const char	*c = reinterpret_cast<const char *>(memchr(str, ch, n));
	const char	*ft = reinterpret_cast<const char *>(ft_memchr(str, ch, n));

	EXPECT_EQ(c, ft);
}

TEST(memchr, zero_length)
{
	const char		*str = "Hello, world!";
	const int		ch = 'o';
	const size_t	n = 0;

	const char	*c = reinterpret_cast<const char *>(memchr(str, ch, n));
	const char	*ft = reinterpret_cast<const char *>(ft_memchr(str, ch, n));

	EXPECT_EQ(c, ft);
}

TEST(memchr, null_char)
{
	const char		*str = "Hello\0world!";
	const int		ch = '\0';
	const size_t	n = 13;

	const char	*c = reinterpret_cast<const char *>(memchr(str, ch, n));
	const char	*ft = reinterpret_cast<const char *>(ft_memchr(str, ch, n));

	EXPECT_EQ(c, ft);
}

TEST(memchr, non_ascii)
{
	const char		*str = "Hello, \255world!";
	const int		ch = 255;
	const size_t	n = 15;

	const char	*c = reinterpret_cast<const char *>(memchr(str, ch, n));
	const char	*ft = reinterpret_cast<const char *>(ft_memchr(str, ch, n));

	EXPECT_EQ(c, ft);
}

TEST(memchr, multiple_occurrences)
{
	const char		*str = "Hello, world!";
	const int		ch = 'l';
	const size_t	n = 14;

	const char	*c = reinterpret_cast<const char *>(memchr(str, ch, n));
	const char	*ft = reinterpret_cast<const char *>(ft_memchr(str, ch, n));

	EXPECT_EQ(c, ft);
}

TEST(memchr, cast)
{
	const char		*str = "Hello, \255world!";
	const int		ch = 256;
	const size_t	n = 15;

	const char	*c = reinterpret_cast<const char *>(memchr(str, ch, n));
	const char	*ft = reinterpret_cast<const char *>(ft_memchr(str, ch, n));

	EXPECT_EQ(c, ft);
}

TEST(memchrDeathTest, nullptr)
{
	EXPECT_EXIT({
		const char		*str = nullptr;
		const int		ch = 1;
		const size_t	n = 2;

		ft_memchr(str, ch, n);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
