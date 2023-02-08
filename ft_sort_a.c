/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:12:56 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/08 00:54:17 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_move(t_stack *stack, int next_min)
{
	int		move;

	move = 0;
	while (stack)
	{
		if (stack->index == next_min)
			break ;
		move++;
		stack = stack->next;
	}
	return (move);
}

void	ft_sort_3(t_stack **stack_a)
{
	int		min;
	int		next_min;

	if (ft_isort_(*stack_a) == 0)
		return ;
	min = ft_get_next_min(*stack_a, -1);
	next_min = ft_get_next_min(*stack_a, min);
	if ((*stack_a)->index == min && (*stack_a)->next->index != next_min)
	{
		ft_rotate_a(stack_a, 0);
		ft_swap_a(stack_a, 0);
		ft_reverse_rotate_a(stack_a, 0);
	}
	else if ((*stack_a)->index == next_min)
	{
		if ((*stack_a)->next->index == min)
			ft_swap_a(stack_a, 0);
		else
			ft_reverse_rotate_a(stack_a, 0);
	}
	else
	{
		ft_rotate_a(stack_a, 0);
		ft_sort_3(stack_a);
	}
}

void	ft_sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int		move;

	move = ft_move(*stack_a, ft_get_next_min(*stack_a, -1));
	if (move == 1)
		ft_rotate_a(stack_a, 0);
	else if (move == 2)
	{
		ft_rotate_a(stack_a, 0);
		ft_rotate_a(stack_a, 0);
	}
	else if (move == 3)
		ft_reverse_rotate_a(stack_a, 0);
	ft_push_b(stack_a, stack_b, 0);
	ft_sort_3(stack_a);
	ft_push_a(stack_a, stack_b, 0);
}

void	ft_sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	move;

	move = ft_move(*stack_a, ft_get_next_min(*stack_a, -1));
	if (move == 1)
		ft_rotate_a(stack_a, 0);
	else if (move == 2)
	{
		ft_rotate_a(stack_a, 0);
		ft_rotate_a(stack_a, 0);
	}
	else if (move == 3)
	{
		ft_reverse_rotate_a(stack_a, 0);
		ft_reverse_rotate_a(stack_a, 0);
	}
	else if (move == 4)
		ft_reverse_rotate_a(stack_a, 0);
	ft_push_b(stack_a, stack_b, 0);
	ft_sort_4(stack_a, stack_b);
	ft_push_a(stack_a, stack_b, 0);
}

void	ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	if (ft_isort_(*stack_a) == 0 || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		ft_error(0);
	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_swap_a(stack_a, 0);
	else if (size == 3)
		ft_sort_3(stack_a);
	else if (size == 4)
		ft_sort_4(stack_a, stack_b);
	else if (size == 5)
		ft_sort_5(stack_a, stack_b);
	else if (size <= 200)
		ft_sort_larg(stack_a, stack_b, 4);
	else
		ft_sort_larg(stack_a, stack_b, 10);
}
