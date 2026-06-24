/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:43:28 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/24 15:08:23 by kjurkows         ###   ########.fr       */
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

	t_list	*last = ft_lstlast(list1);

	ASSERT_EQ(last, list3);

	free(list1);
	free(list2);
	free(list3);
}

TEST(lstlast, empty)
{
	t_list	*list = nullptr;

	t_list	*last = ft_lstlast(list);

	ASSERT_EQ(last, nullptr);
}

TEST(lstlast, single)
{
	t_list	*list = (t_list *)malloc(sizeof(t_list));
	list->next = nullptr;

	t_list	*last = ft_lstlast(list);

	ASSERT_EQ(last, list);

	free(list);
}

TEST(lstlastDeathTest, nullptr)
{
	EXPECT_EXIT({
		t_list	*list = nullptr;

		t_list	*last = ft_lstlast(list);

		exit(!!last);
	}, ::testing::ExitedWithCode(0), "");
}
