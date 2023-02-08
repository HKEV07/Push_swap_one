/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_larg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:30:28 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/08 00:44:03 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_stack *stack)
{
	int		max;

	max = stack->num;
	while (stack)
	{
		if (max < stack->num)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

int	ft_max_index(t_stack *stack_b)
{
	int		max;
	int		index;

	max = ft_max(stack_b);
	index = 0;
	while (stack_b)
	{
		if (max == stack_b->num)
			return (index);
		index++;
		stack_b = stack_b->next;
	}
	return (index);
}

int	ft_isort_(t_stack *stack_a)
{
	int		i;
	int		size;
	int		max;

	i = 0;
	max = stack_a->num;
	size = ft_lstsize(stack_a) - 1;
	while (stack_a)
	{
		if (stack_a->num > max)
		{
			i++;
			max = stack_a->num;
		}
		stack_a = stack_a->next;
	}
	if (size == i)
		return (0);
	return (1);
}

void	ft_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = ft_lstsize(*stack_b) - 1;
	while (*stack_b)
	{
		if ((*stack_b)->index == size && size >= 0)
		{
			ft_push_a(stack_a, stack_b, 0);
			size--;
		}
		else if (ft_max_index(*stack_b) > size / 2)
			ft_reverse_rotate_b(stack_b, 0);
		else if (ft_max_index(*stack_b) <= size / 2)
			ft_rotate_b(stack_b, 0);
	}
}

void	ft_sort_larg(t_stack **stack_a, t_stack **stack_b, int m)
{
	int		i;
	int		j;

	i = 0;
	ft_index_stack(stack_a);
	while (*stack_a)
	{
		j = ft_lstsize(*stack_a) / m;
		if ((*stack_a)->index <= i)
		{
			ft_push_b(stack_a, stack_b, 0);
			i++;
		}
		else if ((*stack_a)->index <= i + j)
		{
			ft_push_b(stack_a, stack_b, 0);
			ft_rotate_b(stack_b, 0);
			i++;
		}
		else
			ft_rotate_a(stack_a, 0);
	}
	ft_sort_b(stack_a, stack_b);
}
