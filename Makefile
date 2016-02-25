# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/23 13:50:13 by ale-naou          #+#    #+#              #
#    Updated: 2016/02/23 13:50:26 by ale-naou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
LIB_PATH = ./libft/
INC_PATH = ./include/

NAME = libftprintf.a
CC = clang
CFGLAGS = -Werror -Wextra -Wall

SRC_NAME  = ft_printf.c check_err.c check_flags.c get_flags.c get_mods.c \
			get_prec.c get_type.c get_width.c parse_format.c print_arg.c \
			print_arg_base.c print_arg_char.c print_arg_int.c print_arg_ptr.c \
			print_arg_str.c print_arg_unsigned.c specify.c nbr_len.c \
			nbr_len_base.c print_base.c print_char.c print_int.c print_mem.c \
			print_str.c print_unsigned_int.c str_len.c print_wchar_t.c \
			nbr_binary.c nbr_len_unsigned.c print_str_wchar_t.c \
			print_arg_percent.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: clean fclean re

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	rm -f $(NAME)

re: fclean all
