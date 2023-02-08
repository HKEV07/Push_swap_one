/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:21:22 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/08 23:32:06 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	pl_m(const char *s, size_t j)
{
	long	p;
	int		m;

	p = 0;
	m = 0;
	while (s[j])
	{
		if (!ft_isdigit(s[j]) || m > 10)
			ft_error(1);
		p = (p * 10) + (s[j] - '0');
		j++;
		m++;
	}
	return (p);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		c;
	long	s;

	i = 0;
	c = 1;
	s = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' \
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			c = -1;
		i++;
		if (!ft_isdigit(str[i]))
			ft_error(1);
	}
	s = pl_m(str, i);
	if ((s * c) > 2147483647 || (s * c) < -2147483648)
		ft_error(1);
	return ((int)(s * c));
}
