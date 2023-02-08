/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_utlis_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:54:15 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/08 23:42:24 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_isort_stack(t_stack *stack_a)
{
	int		i;
	int		size;
	int		max;

	i = 0;
	if(!stack_a)
		return (1);
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
