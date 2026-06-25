/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:26:48 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/25 17:47:24 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(lstiter, basic)
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

	static int	i_r = 0;
	ft_lstiter(list1, [](void *content)
	{
		int	*i = (int *)content;
		ASSERT_EQ(*i, i_r++);
	});
	ASSERT_EQ(i_r, 3);

	free(list1);
	free(list2);
	free(list3);
}

TEST(lstiterDeathTest, nullptr_list)
{
	ASSERT_EXIT({
		static int	i_r = 0;
		ft_lstiter(nullptr, [](void *content)
		{
			(void)content;
			i_r++;
		});

		exit(i_r);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(lstiterDeathTest, nullptr_f)
{
	ASSERT_EXIT({
		t_list		*list = (t_list *)malloc(sizeof(t_list));
		int			i = 0;
		list->content = &i;
		list->next = nullptr;

		ft_lstiter(list, nullptr);

		free(list);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
