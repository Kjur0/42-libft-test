/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdelone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:59:06 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/21 15:10:29 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(lstdelone, basic)
{
	EXPECT_EXIT({
		t_list	*lst = (t_list *)malloc(sizeof(t_list));
		lst->content = malloc(sizeof(int));
		lst->next = nullptr;
		*((int *)lst->content) = 42;

		ft_lstdelone(lst, free);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(lstdelone, null_node)
{
	EXPECT_EXIT({
		ft_lstdelone(nullptr, free);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
