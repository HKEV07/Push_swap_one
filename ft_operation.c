/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:47:01 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/08 23:43:22 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstbeforelast(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_swap_a(t_stack **stack_a, int i)
{
	t_stack		*tmp;

	if (!(*stack_a))
		return ;
	else if ((*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (i == 0)
		write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack **stack_b, int i)
{
	t_stack		*tmp;

	if (!(*stack_b))
		return ;
	else if ((*stack_b)->next == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (i == 0)
		write(1, "sb\n", 3);
}

void	ft_push_a(t_stack **sta, t_stack **stb, int i)
{
	t_stack		*tmp;

	if (!(*stb))
		return ;
	tmp = (*stb);
	(*stb) = (*stb)->next;
	tmp->next = NULL;
	ft_lstadd_front(sta, tmp);
	if (i == 0)
		write(1, "pa\n", 3);
}

void	ft_push_b(t_stack **sta, t_stack **stb, int i)
{
	t_stack		*tmp;

	if (ft_lstsize(*sta) == 0)
		return ;
	tmp = (*sta);
	(*sta) = (*sta)->next;
	tmp->next = NULL;
	ft_lstadd_front(stb, tmp);
	if (i == 0)
		write(1, "pb\n", 3);
}
