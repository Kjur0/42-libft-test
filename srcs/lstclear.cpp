/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:06:06 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 20:29:11 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(lstclear, basic)
{
	t_list	*list1 = (t_list *)malloc(sizeof(t_list));
	t_list	*list2 = (t_list *)malloc(sizeof(t_list));
	t_list	*list3 = (t_list *)malloc(sizeof(t_list));
	int		*content1 = (int *)malloc(sizeof(int));
	int		*content2 = (int *)malloc(sizeof(int));
	int		*content3 = (int *)malloc(sizeof(int));
	*content1 = 42;
	*content2 = 84;
	*content3 = 168;
	list1->content = content1;
	list1->next = list2;
	list2->content = content2;
	list2->next = list3;
	list3->content = content3;
	list3->next = nullptr;

	ft_lstclear(&list1, free);

	EXPECT_EQ(list1, nullptr);
}

TEST(lstclear, null_list)
{
	t_list	*list = nullptr;

	ft_lstclear(&list, free);
}
