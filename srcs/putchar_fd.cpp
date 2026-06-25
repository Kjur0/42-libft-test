/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 21:32:51 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:47:24 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <fcntl.h>
#include <unistd.h>

TEST(putchar_fd, test)
{
	char	c = 'A';
	int		fd = open("/tmp/tests/putchar_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putchar_fd(c, fd);

	close(fd);
	char	out[1];
	fd = open("/tmp/tests/putchar_fd.txt", O_RDONLY);
	read(fd, out, 1);
	close(fd);
	ASSERT_EQ(out[0], c);
}
