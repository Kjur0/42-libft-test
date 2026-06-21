/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:30:51 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/21 14:18:11 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(lstmap, basic)
{
	t_list		*list1 = (t_list *)malloc(sizeof(t_list));
	t_list		*list2 = (t_list *)malloc(sizeof(t_list));
	t_list		*list3 = (t_list *)malloc(sizeof(t_list));
	int			i1 = 0;
	int			i2 = 1;
	int			i3 = 2;
	list1->content = &i1;
	list1->next = list2;
	list2->content = &i2;
	list2->next = list3;
	list3->content = &i3;
	list3->next = nullptr;

	t_list		*new_list = ft_lstmap(list1, [](void *content) -> void *
{
		int	*i = (int *)content;
		int	*new_i = (int *)malloc(sizeof(int));
		*new_i = *i + 10;
		return new_i;
	}, free);
	t_list	*current_new = new_list;
	for (int i = 0; i < 3; i++)
	{
		int *value = (int *)current_new->content;
		EXPECT_EQ(*value, i + 10);
		current_new = current_new->next;
	}
	EXPECT_EQ(current_new, nullptr);

	free(new_list->next->next->content);
	free(new_list->next->next);
	free(new_list->next->content);
	free(new_list->next);
	free(new_list->content);
	free(new_list);
	free(list1);
	free(list2);
	free(list3);
}

TEST(lstmap, null_list)
{
	t_list	*new_list = ft_lstmap(nullptr, [](void *content) -> void *
	{
		int	*i = (int *)content;
		int	*new_i = (int *)malloc(sizeof(int));
		*new_i = *i + 10;
		return new_i;
	}, free);

	EXPECT_EQ(new_list, nullptr);
}
