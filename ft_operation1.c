/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:49:01 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/08 23:44:44 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_b(t_stack **stack_b, int i)
{
	t_stack		*tmp;

	if (!(*stack_b))
		return ;
	else if ((*stack_b)->next == NULL)
		return ;
	tmp = *stack_b;
	ft_lstlast(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	if (i == 0)
		write(1, "rb\n", 3);
}

void	ft_rotate_a(t_stack **stack_a, int i)
{
	t_stack		*tmp;

	if (!(*stack_a))
		return ;
	else if ((*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	ft_lstlast(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
}

void	ft_reverse_rotate_b(t_stack **stack_b, int i)
{
	t_stack		*tmp;
	t_stack		*a;

	if (!(*stack_b))
		return ;
	else if ((*stack_b)->next == NULL)
		return ;
	a = *stack_b;
	tmp = ft_lstbeforelast(*stack_b);
	*stack_b = tmp->next;
	tmp->next->next = a;
	tmp->next = 0;
	if (i == 0)
		write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_a(t_stack **stack_a, int i)
{
	t_stack		*tmp;
	t_stack		*a;

	if (!(*stack_a))
		return ;
	else if ((*stack_a)->next == NULL)
		return ;
	a = *stack_a;
	tmp = ft_lstbeforelast(*stack_a);
	*stack_a = tmp->next;
	tmp->next->next = a;
	tmp->next = 0;
	if (i == 0)
		write(1, "rra\n", 4);
}
