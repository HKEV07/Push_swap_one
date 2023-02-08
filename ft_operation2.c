/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 02:19:01 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/08 01:30:07 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b, int i)
{
	ft_reverse_rotate_a(stack_a, 1);
	ft_reverse_rotate_b(stack_b, 1);
	if (i == 0)
		write(1, "rrr\n", 4);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, int i)
{
	ft_swap_a(stack_a, 1);
	ft_swap_b(stack_b, 1);
	if (i == 0)
		write(1, "ss\n", 3);
}

void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b, int i)
{
	ft_rotate_a(stack_a, 1);
	ft_rotate_b(stack_b, 1);
	if (i == 0)
		write(1, "rr\n", 3);
}
