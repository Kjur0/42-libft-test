/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl_fd.cpp                                     :+:      :+:    :+:   */
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

TEST(putendl_fd, test)
{
	char	s[] = "Hello, World!";
	int		fd = open("/tmp/tests/putendl_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putendl_fd(s, fd);

	close(fd);
	char	out[15];
	fd = open("/tmp/tests/putendl_fd.txt", O_RDONLY);
	read(fd, out, 15);
	close(fd);
	ASSERT_STREQ(out, "Hello, World!\n");
}

TEST(putendl_fdDeathTest, nullptr)
{
	ASSERT_EXIT({
		char	*s = nullptr;
		int		fd = 1;

		ft_putendl_fd(s, fd);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
