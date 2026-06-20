/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:52:22 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 20:27:39 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(lstadd_back, basic)
{
	char	str1[] = "Hello, World!";
	char	str2[] = "42 is the best school!";
	t_list	*list1 = (t_list *)malloc(sizeof(t_list));
	t_list	*list2 = (t_list *)malloc(sizeof(t_list));
	t_list	*tmp = list1;
	list1->content = str1;
	list1->next = nullptr;
	list2->content = str2;
	list2->next = nullptr;

	ft_lstadd_back(&tmp, list2);

	ASSERT_STREQ((char *)tmp->content, str1);
	ASSERT_STREQ((char *)tmp->next->content, str2);
	ASSERT_EQ(tmp, list1);
	ASSERT_EQ(tmp->next, list2);
	ASSERT_EQ(tmp->next->next, nullptr);

	free(list1);
	free(list2);
}

TEST(lstadd_back, null_list)
{
	char	str[] = "Hello, World!";
	t_list	*list = (t_list *)malloc(sizeof(t_list));
	t_list	*tmp = nullptr;
	list->content = str;
	list->next = nullptr;

	ft_lstadd_back(&tmp, list);

	ASSERT_STREQ((char *)tmp->content, str);
	ASSERT_EQ(tmp->next, nullptr);
	ASSERT_EQ(tmp, list);

	free(list);
}
