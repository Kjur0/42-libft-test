/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:24:53 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 14:53:39 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <string.h>

#include <gtest/gtest.h>

TEST(memchr, basic) {
	const char	str[] = "Hello, world!";
	int			ch = 'o';
	size_t		n = 14;

	const char	*c = reinterpret_cast<const char *>(memchr(str, ch, n));
	const char	*ft = reinterpret_cast<const char *>(ft_memchr(str, ch, n));

	EXPECT_EQ(c, ft);
}

TEST(memchr, not_found) {
	const char	str[] = "Hello, world!";
	int			ch = 'x';
	size_t		n = 14;

	const char	*c = reinterpret_cast<const char *>(memchr(str, ch, n));
	const char	*ft = reinterpret_cast<const char *>(ft_memchr(str, ch, n));

	EXPECT_EQ(c, ft);
}

TEST(memchr, zero_length) {
	const char	str[] = "Hello, world!";
	int			ch = 'o';
	size_t		n = 0;

	const char	*c = reinterpret_cast<const char *>(memchr(str, ch, n));
	const char	*ft = reinterpret_cast<const char *>(ft_memchr(str, ch, n));

	EXPECT_EQ(c, ft);
}

TEST(memchr, null_char) {
	const char	str[] = "Hello\0world!";
	int			ch = '\0';
	size_t		n = 13;

	const char	*c = reinterpret_cast<const char *>(memchr(str, ch, n));
	const char	*ft = reinterpret_cast<const char *>(ft_memchr(str, ch, n));

	EXPECT_EQ(c, ft);
}

TEST(memchr, non_ascii) {
	const char	str[] = "Hello, world!";
	int			ch = 255;
	size_t		n = 14;

	const char	*c = reinterpret_cast<const char *>(memchr(str, ch, n));
	const char	*ft = reinterpret_cast<const char *>(ft_memchr(str, ch, n));

	EXPECT_EQ(c, ft);
}

TEST(memchr, multiple_occurrences) {
	const char	str[] = "Hello, world!";
	int			ch = 'o';
	size_t		n = 14;

	const char	*c = reinterpret_cast<const char *>(memchr(str, ch, n));
	const char	*ft = reinterpret_cast<const char *>(ft_memchr(str, ch, n));

	EXPECT_EQ(c, ft);
}
