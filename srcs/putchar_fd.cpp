/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 21:32:51 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/18 21:55:12 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
	#include <libft.h>
}
#include <fcntl.h>
#include <unistd.h>

#include <gtest/gtest.h>

TEST(putchar_fd, test) {
	char	c = 'A';
	int		fd = open("/tmp/tests/putchar_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putchar_fd(c, fd);
	char	out[1];
	close(fd);
	fd = open("/tmp/tests/putchar_fd.txt", O_RDONLY);
	read(fd, out, 1);

	EXPECT_EQ(out[0], c);

	close(fd);
}
