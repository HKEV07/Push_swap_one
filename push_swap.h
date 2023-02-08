/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:10:05 by ibenaait          #+#    #+#             */
/*   Updated: 2023/02/08 02:40:50 by ibenaait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int					num;
	int					index;
	struct s_stack		*next;
}	t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content, int index);
int		ft_isdigit(int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
void	ft_error(int ex);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
t_stack	*ft_lstbeforelast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_index_stack(t_stack **stack);
void	ft_push_b(t_stack **sta, t_stack **stb, int i);
void	ft_rotate_b(t_stack **stack, int i);
void	ft_rotate_a(t_stack **stack, int i);
int		ft_lstsize(t_stack *lst);
void	ft_push_a(t_stack **sta, t_stack **stb, int i);
void	ft_reverse_rotate_a(t_stack **stack, int i);
void	ft_reverse_rotate_b(t_stack **stack, int i);
char	*ft_strjoin(char *s1, char *s2);
void	ft_sort_5(t_stack **stack_a, t_stack **stack_b);
int		ft_isort_(t_stack *stack_a);
void	ft_swap_b(t_stack **stack_b, int i);
void	ft_swap_a(t_stack **stack_a, int i);
void	ft_sort_3(t_stack **stack_a);
void	ft_sort_4(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_a(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_larg(t_stack **stack_a, t_stack **stack_b, int m);
void	ft_free_stack(t_stack *stack);
void	ft_free(char **str);
int		ft_get_next_min(t_stack *stack, int in);
void	ft_index(t_stack *stack);
void	ft_check_space(char **av);
void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b, int i);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int i);
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b, int i);
#endif