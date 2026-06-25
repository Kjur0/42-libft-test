/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:52:22 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:47:24 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(lstadd_back, basic)
{
	char	str1[] = "Hello, World!";
	char	str2[] = "42 is the best school!";
	char	str3[] = "This is a test.";
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
	ft_lstadd_back(&tmp, list3);

	ASSERT_STREQ((char *)tmp->content, str1);
	ASSERT_STREQ((char *)tmp->next->content, str2);
	ASSERT_STREQ((char *)tmp->next->next->content, str3);
	ASSERT_EQ(tmp, list1);
	ASSERT_EQ(tmp->next, list2);
	ASSERT_EQ(tmp->next->next, list3);
	ASSERT_EQ(tmp->next->next->next, nullptr);

	free(list1);
	free(list2);
	free(list3);
}

TEST(lstadd_back, null_list)
{
	char	str[] = "Hello, World!";
	t_list	*list = (t_list *)malloc(sizeof(t_list));
	list->content = str;
	list->next = nullptr;

	t_list	*tmp = nullptr;
	ft_lstadd_back(&tmp, list);

	ASSERT_STREQ((char *)tmp->content, str);
	ASSERT_EQ(tmp->next, nullptr);
	ASSERT_EQ(tmp, list);

	free(list);
}


TEST(lstadd_backDeathTest, nullptr_list)
{
	ASSERT_EXIT({
		t_list	*list = (t_list *)malloc(sizeof(t_list));
		list->content = nullptr;
		list->next = nullptr;

		ft_lstadd_back(nullptr, list);

		free(list);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(lstadd_backDeathTest, nullptr_new)
{
	ASSERT_EXIT({
		t_list		*list = (t_list *)malloc(sizeof(t_list));
		list->content = nullptr;
		list->next = nullptr;

		ft_lstadd_back(&list, nullptr);

		const int	res = !list;

		free(list);

		exit(res);
	}, ::testing::ExitedWithCode(0), "");
}
