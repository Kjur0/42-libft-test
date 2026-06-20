/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 12:09:20 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 15:23:29 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(lstadd_front, basic) {
	char	str1[] = "Hello, World!";
	char	str2[] = "42Warsaw";
	t_list	*list1 = (t_list *)malloc(sizeof(t_list));
	t_list	*list2 = (t_list *)malloc(sizeof(t_list));
	t_list	*tmp = list1;
	list1->content = str1;
	list1->next = nullptr;
	list2->content = str2;
	list2->next = nullptr;

	ft_lstadd_front(&tmp, list2);

	ASSERT_EQ(tmp, list2);
	ASSERT_EQ(list2->next, list1);
	ASSERT_STREQ((char *)tmp->next->content, str1);
	ASSERT_STREQ((char *)tmp->content, str2);

	free(list1);
	free(list2);
}

TEST(lstadd_front, null_list) {
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

TEST(lstadd_front, null_node) {
	char	str[] = "Hello, World!";
	t_list	*list = (t_list *)malloc(sizeof(t_list));
	list->content = str;
	list->next = nullptr;
	t_list	*tmp = list;

	ft_lstadd_front(&tmp, nullptr);

	ASSERT_EQ(tmp, list);
	ASSERT_EQ(list->next, nullptr);
	ASSERT_STREQ((char *)list->content, str);

	free(list);
}

TEST(lstadd_front, nullptr) {
	t_list	*lst = (t_list *)malloc(sizeof(t_list));

	ft_lstadd_front(nullptr, lst);

	free(lst);
}
