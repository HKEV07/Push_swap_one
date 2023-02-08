/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:08:19 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/08 16:33:33 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_check_repeat_arg_b(t_stack *stack_a)
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

void	ft_check_space_bonus(char **av)
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

t_stack	*ft_ret_stack_b(char **av)
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
	ft_check_repeat_arg_b(ret);
	free(str);
	ft_free(s);
	return (ret);
}

void	ft_checke_op(char *s, t_stack **sta, t_stack **stb)
{
	if (!ft_strncmp("sa\n", s, 3))
		ft_swap_a(sta, 1);
	else if (!ft_strncmp("sb\n", s, 3))
		ft_swap_b(stb, 1);
	else if (!ft_strncmp("pa\n", s, 3))
		ft_push_a(sta, stb, 1);
	else if (!ft_strncmp("pb\n", s, 3))
		ft_push_b(sta, stb, 1);
	else if (!ft_strncmp("ra\n", s, 3))
		ft_rotate_a(sta, 1);
	else if (!ft_strncmp("rb\n", s, 3))
		ft_rotate_b(stb, 1);
	else if (!ft_strncmp("rra\n", s, 4))
		ft_reverse_rotate_a(sta, 1);
	else if (!ft_strncmp("rrb\n", s, 4))
		ft_reverse_rotate_b(stb, 1);
	else if (!ft_strncmp("rr\n", s, 3))
		ft_rotate_ab(sta, stb, 1);
	else if (!ft_strncmp("ss\n", s, 3))
		ft_ss(sta, stb, 1);
	else if (!ft_strncmp("rrr\n", s, 4))
		ft_reverse_rotate_ab(sta, stb, 1);
	else
		ft_error(1);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		*s;

	if (ac <= 1)
		ft_error(0);
	ft_check_space_bonus(av);
	stack_a = ft_ret_stack_b(av);
	s = get_next_line(0);
	while (s)
	{
		if (s == NULL)
			break ;
		ft_checke_op(s, &stack_a, &stack_b);
		free(s);
		s = get_next_line(0);
	}
	if (ft_isort_stack(stack_a) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
