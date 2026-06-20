/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdelone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:59:06 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 15:05:04 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(lstdelone, basic) {
	t_list	*lst = (t_list *)malloc(sizeof(t_list));
	lst->content = malloc(sizeof(int));
	lst->next = nullptr;
	*((int *)lst->content) = 42;

	ft_lstdelone(lst, free);
}

TEST(lstdelone, null_node) {
	ft_lstdelone(nullptr, free);
}

TEST(lstdelone, no_del) {
	t_list	*lst = (t_list *)malloc(sizeof(t_list));
	lst->next = nullptr;
	void	*ptr = malloc(sizeof(int));
	*((int *)ptr) = 42;
	lst->content = ptr;

	ft_lstdelone(lst, nullptr);

	EXPECT_EQ(*((int *)ptr), 42);

	free(ptr);
}

TEST(lstdelone, null_content) {
	t_list	*lst = (t_list *)malloc(sizeof(t_list));
	lst->content = nullptr;
	lst->next = nullptr;

	ft_lstdelone(lst, free);
}
