/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:06:06 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:47:24 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(lstclear, basic)
{
	ASSERT_EXIT({
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

		exit(!!list1);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(lstclearDeathTest, nullptr)
{
	ASSERT_EXIT({
		ft_lstclear(nullptr, free);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(lstclearDeathTest, nullptr_list)
{
	ASSERT_EXIT({
		t_list	*list = nullptr;

		ft_lstclear(&list, free);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(lstclearDeathTest, nullptr_del)
{
	ASSERT_EXIT({
		t_list		*lst = (t_list *)malloc(sizeof(t_list));
		int			*content = (int *)malloc(sizeof(int));
		lst->content = content;
		lst->next = nullptr;
		*content = 42;

		ft_lstclear(&lst, nullptr);

		const int	res = !content;

		free(content);

		exit(!!lst || res);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(lstclearDeathTest, nullptr_content)
{
	ASSERT_EXIT({
		t_list	*lst = (t_list *)malloc(sizeof(t_list));
		lst->content = nullptr;
		lst->next = nullptr;

		ft_lstclear(&lst, free);

		exit(!!lst);
	}, ::testing::ExitedWithCode(0), "");
}
