/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.cpp                                      :+:      :+:    :+:   */
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

TEST(putstr_fd, test) {
	char	s[] = "Hello, World!";
	int		fd = open("/tmp/tests/putstr_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putstr_fd(s, fd);
	char	out[14];
	close(fd);
	fd = open("/tmp/tests/putstr_fd.txt", O_RDONLY);
	read(fd, out, 14);

	EXPECT_STREQ(out, s);

	close(fd);
}
