/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 11:48:06 by kjurkows          #+#    #+#             */
/*   Updated: 2026/06/20 20:00:56 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

TEST(lstnew, basic)
{
	char	str[] = "Hello, World!";
	t_list	*list = ft_lstnew(str);

	ASSERT_NE(list, nullptr);
	ASSERT_STREQ((char *)list->content, str);
	ASSERT_EQ(list->next, nullptr);

	free(list);
}
