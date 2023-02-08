/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:50 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/08 18:27:10 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_next_min(t_stack **stack)
{
	t_stack		*head;
	t_stack		*min;
	int			in;

	min = NULL;
	in = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (in == 0 || head->num < min->num))
			{
				min = head;
				in = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	ft_index_stack(t_stack **stack)
{
	t_stack		*head;
	int			index;

	index = 0;
	head = ft_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = ft_next_min(stack);
	}
}

void	ft_check_repeat_arg(t_stack *stack_a)
{
	int			i;
	int			c;
	t_stack		*tmp;
	t_stack		*head;

	head = stack_a;
	while (stack_a)
	{
		i = stack_a->num;
		c = 0;
		tmp = stack_a;
		while (tmp)
		{
			if (i == tmp->num)
				c++;
			if (tmp->num == i && c >= 2)
				ft_error(1);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	stack_a = head;
}

t_stack	*ft_ret_stack(char **av)
{
	int			i;
	char		*str;
	char		**s;
	t_stack		*ret;

	i = 1;
	ret = NULL;
	str = NULL;
	while (av[i])
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, av[i]);
		i++;
	}
	s = ft_split(str, ' ');
	i = 0;
	while (s[i])
	{
		ft_lstadd_back(&ret, ft_lstnew(ft_atoi(s[i]), -1));
		i++;
	}
	ft_check_repeat_arg(ret);
	free(str);
	ft_free(s);
	return (ret);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			i;

	i = 0;
	if (ac <= 1)
		ft_error(0);
	ft_check_space(av);
	stack_a = ft_ret_stack(av);
	ft_sort_a(&stack_a, &stack_b);
	ft_free_stack(stack_a);
	while(1){};
}
