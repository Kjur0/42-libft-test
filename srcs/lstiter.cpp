/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:26:48 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 20:30:23 by kjurkows         ###   ########.fr       */
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
	static int	i_r = 0;
	list1->content = &i1;
	list1->next = list2;
	list2->content = &i2;
	list2->next = list3;
	list3->content = &i3;
	list3->next = nullptr;

	ft_lstiter(list1, [](void *content)
	{
		int	*i = (int *)content;
		EXPECT_EQ(*i, i_r);
		i_r++;
	});
	EXPECT_EQ(i_r, 3);

	free(list1);
	free(list2);
	free(list3);
}

TEST(lstiter, null_list)
{
	static int	i_r = 0;

	ft_lstiter(nullptr, [](void *content)
	{
		(void)content;
		i_r++;
	});
	EXPECT_EQ(i_r, 0);
}
