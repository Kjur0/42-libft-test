/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 21:32:51 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 11:48:35 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <fcntl.h>
#include <unistd.h>

TEST(putnbr_fd, 42) {
	int		n = 42;
	int		fd = open("/tmp/tests/putnbr_fd_42.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putnbr_fd(n, fd);
	char	out[3];
	close(fd);
	fd = open("/tmp/tests/putnbr_fd_42.txt", O_RDONLY);
	read(fd, out, 3);

	EXPECT_STREQ(out, "42");

	close(fd);
}

TEST(putnbr_fd, 0) {
	int		n = 0;
	int		fd = open("/tmp/tests/putnbr_fd_0.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putnbr_fd(n, fd);
	char	out[2];
	close(fd);
	fd = open("/tmp/tests/putnbr_fd_0.txt", O_RDONLY);
	read(fd, out, 2);

	EXPECT_STREQ(out, "0");

	close(fd);
}

TEST(putnbr_fd, neg1) {
	int		n = -1;
	int		fd = open("/tmp/tests/putnbr_fd_neg.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putnbr_fd(n, fd);
	char	out[3];
	close(fd);
	fd = open("/tmp/tests/putnbr_fd_neg.txt", O_RDONLY);
	read(fd, out, 3);

	EXPECT_STREQ(out, "-1");

	close(fd);
}

TEST(putnbr_fd, neg42) {
	int		n = -42;
	int		fd = open("/tmp/tests/putnbr_fd_neg42.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putnbr_fd(n, fd);
	char	out[4];
	close(fd);
	fd = open("/tmp/tests/putnbr_fd_neg42.txt", O_RDONLY);
	read(fd, out, 4);

	EXPECT_STREQ(out, "-42");

	close(fd);
}

TEST(putnbr_fd, int_min) {
	int		n = -2147483648;
	int		fd = open("/tmp/tests/putnbr_fd_int_min.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putnbr_fd(n, fd);
	char	out[12];
	close(fd);
	fd = open("/tmp/tests/putnbr_fd_int_min.txt", O_RDONLY);
	read(fd, out, 12);

	EXPECT_STREQ(out, "-2147483648");

	close(fd);
}

TEST(putnbr_fd, int_max) {
	int		n = 2147483647;
	int		fd = open("/tmp/tests/putnbr_fd_int_max.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putnbr_fd(n, fd);
	char	out[11];
	close(fd);
	fd = open("/tmp/tests/putnbr_fd_int_max.txt", O_RDONLY);
	read(fd, out, 11);

	EXPECT_STREQ(out, "2147483647");

	close(fd);
}
