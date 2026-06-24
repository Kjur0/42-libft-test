/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdelone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:59:06 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/24 15:55:34 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"
#include <stdlib.h>

TEST(lstdelone, basic)
{
	EXPECT_EXIT({
		t_list		*lst = (t_list *)malloc(sizeof(t_list));
		int			*content = (int *)malloc(sizeof(int));
		lst->content = content;
		lst->next = nullptr;
		*content = 42;

		ft_lstdelone(lst, free);

		int		res = *((int *)lst->content);

		exit(!!res);
	}, ::testing::KilledBySignal(SIGSEGV), "");
}

TEST(lstdeloneDeathTest, nullptr_node)
{
	EXPECT_EXIT({
		ft_lstdelone(nullptr, free);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(lstdeloneDeathTest, nullptr_del)
{
	EXPECT_EXIT({
		t_list		*lst = (t_list *)malloc(sizeof(t_list));
		int			*content = (int *)malloc(sizeof(int));
		lst->content = content;
		lst->next = nullptr;
		*content = 42;

		ft_lstdelone(lst, nullptr);

		const int	res = !content;

		free(content);

		exit(res);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(lstdeloneDeathTest, nullptr_content)
{
	EXPECT_EXIT({
		t_list	*lst = (t_list *)malloc(sizeof(t_list));
		lst->content = nullptr;
		lst->next = nullptr;

		ft_lstdelone(lst, free);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
