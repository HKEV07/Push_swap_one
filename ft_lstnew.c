/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:44:12 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/07 22:28:53 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content, int i)
{
	t_stack		*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->num = content;
	node->index = i;
	node->next = NULL;
	return (node);
}
