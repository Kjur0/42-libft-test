/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 12:09:20 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/23 22:16:16 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(lstadd_front, basic)
{
	char	str1[] = "Hello, World!";
	char	str2[] = "42Warsaw";
	char	str3[] = "FT_LIST";
	t_list	*list1 = (t_list *)malloc(sizeof(t_list));
	t_list	*list2 = (t_list *)malloc(sizeof(t_list));
	t_list	*list3 = (t_list *)malloc(sizeof(t_list));
	list1->content = str1;
	list1->next = list2;
	list2->content = str2;
	list2->next = nullptr;
	list3->content = str3;
	list3->next = nullptr;

	t_list	*tmp = list1;
	ft_lstadd_front(&tmp, list3);

	ASSERT_EQ(tmp, list3);
	ASSERT_EQ(list3->next, list1);
	ASSERT_EQ(list1->next, list2);
	ASSERT_STREQ((char *)tmp->content, str3);
	ASSERT_STREQ((char *)tmp->next->content, str1);
	ASSERT_STREQ((char *)tmp->next->next->content, str2);

	free(list1);
	free(list2);
	free(list3);
}

TEST(lstadd_front, null_list)
{
	char	str[] = "Hello, World!";
	t_list	*list = (t_list *)malloc(sizeof(t_list));
	list->content = str;
	list->next = nullptr;

	t_list	*tmp = nullptr;
	ft_lstadd_front(&tmp, list);

	ASSERT_EQ(list->next, nullptr);
	ASSERT_STREQ((char *)list->content, str);

	free(list);
}
