/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utlis_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:21:01 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/08 16:06:50 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack		*head;
	t_stack		*tmp;

	head = stack;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = NULL;
		head = tmp;
	}
}

void	ft_index(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}

int	ft_get_next_min(t_stack *stack, int in)
{
	int		min;
	int		index;

	index = 0;
	min = stack->num;
	ft_index(stack);
	while (stack)
	{
		if ((min > stack->num) && stack->index != in)
		{
			index = stack->index;
			min = stack->num;
		}
		stack = stack->next;
	}
	return (index);
}

void	ft_check_space(char **av)
{
	int		i;
	int		j;
	int		c;

	i = 1;
	while (av[i])
	{
		c = 0;
		j = 0;
		if (ft_strlen(av[i]) == 0)
			ft_error(1);
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 1)
				c++;
			j++;
		}
		if (c == 0)
			ft_error(1);
		i++;
	}
}
