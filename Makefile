# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibenaait <ibenaait@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 19:22:33 by ibenaait          #+#    #+#              #
#    Updated: 2023/02/08 16:27:27 by ibenaait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=CC
FLAGS= -Wall -Werror -Wextra
RM=rm -rf
NAME=push_swap
BONUS=checker
FILES=	ft_sort_a ft_sort_larg ft_operation ft_operation1 ft_split ft_utlis_fun ft_substr ft_strlen \
		push_swap ft_strjoin ft_strdup ft_memmove ft_lstnew ft_lstsize \
		ft_lstadd_back ft_lstadd_front ft_lstlast ft_atoi ft_error \
		ft_isalpha ft_isdigit ft_operation2	

BFILES= ft_operation ft_operation1 ft_split ft_utlis_fun ft_substr ft_strlen \
		ft_strjoin ft_strdup ft_memmove ft_lstnew ft_lstsize \
		ft_lstadd_back ft_lstadd_front ft_lstlast ft_atoi ft_error \
		ft_isalpha ft_isdigit checker_bonus get_next_line get_next_line_utils \
		ft_operation2 ft_fun_utlis_bonus ft_strncmp

OBJ=$(FILES:=.o)
BOBJ=$(BFILES:=.o)

all: $(NAME)

%_bonus.o: %_bonus.c checker_bonus.h
	$(CC) $(FLAGS) -c $<

bonus: $(BOBJ)
	@$(CC) $(BOBJ) -o $(BONUS)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJ) push_swap.h
	@$(CC)  $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ) $(BOBJ)

fclean: clean
	@$(RM) $(NAME) $(BONUS)

re: fclean all bonus