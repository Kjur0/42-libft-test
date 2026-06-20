/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:39:24 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 20:00:56 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

TEST(lstsize, basic)
{
	t_list	*list1 = (t_list *)malloc(sizeof(t_list));
	t_list	*list2 = (t_list *)malloc(sizeof(t_list));
	t_list	*list3 = (t_list *)malloc(sizeof(t_list));
	list1->next = list2;
	list2->next = list3;
	list3->next = nullptr;

	ASSERT_EQ(ft_lstsize(list1), 3);

	free(list1);
	free(list2);
	free(list3);
}

TEST(lstsize, empty)
{
	t_list	*list = nullptr;

	ASSERT_EQ(ft_lstsize(list), 0);
}

TEST(lstsize, single)
{
	t_list	*list = (t_list *)malloc(sizeof(t_list));
	list->next = nullptr;

	ASSERT_EQ(ft_lstsize(list), 1);

	free(list);
}
