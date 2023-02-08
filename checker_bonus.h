/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:51:12 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/07 23:04:56 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_save_remaining(char *remaining, int *flag);
char	*ft_get_line(char *remaining);
int		find_new_line(char *str);
char	*read_from_file(int fd, char *remaining);
int		ft_isort_stack(t_stack *stack_a);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif