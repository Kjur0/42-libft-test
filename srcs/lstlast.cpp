/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:43:28 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 20:27:22 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

TEST(lstlast, basic)
{
	t_list	*list1 = (t_list *)malloc(sizeof(t_list));
	t_list	*list2 = (t_list *)malloc(sizeof(t_list));
	t_list	*list3 = (t_list *)malloc(sizeof(t_list));
	list1->next = list2;
	list2->next = list3;
	list3->next = nullptr;

	ASSERT_EQ(ft_lstlast(list1), list3);

	free(list1);
	free(list2);
	free(list3);
}

TEST(lstlast, empty)
{
	t_list	*list = nullptr;

	ASSERT_EQ(ft_lstlast(list), nullptr);
}

TEST(lstlast, single)
{
	t_list	*list = (t_list *)malloc(sizeof(t_list));
	list->next = nullptr;

	ASSERT_EQ(ft_lstlast(list), list);

	free(list);
}
