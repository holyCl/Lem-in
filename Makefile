#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 17:45:08 by ivoloshi          #+#    #+#              #
#    Updated: 2018/07/21 07:25:07 by ivoloshi         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# name of the executable file

NAME :=			lem-in

# project directories

SRC_DIR :=		./src/
OBJ_DIR :=		./obj/
INC_DIR :=		./inc/
LIB_DIR :=		./libftprintf/

# project source files

#
# need to add all c files by name
#

SRC :=			main.c \

# project object files

OBJ = 			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# libraries

LIBFT =			$(LIB_DIR)libftprintf.a
LIBFT_INC :=	$(LIB_DIR)inc/

# compilation flags

FLAGS := -Wall -Wextra -Werror

# linking flags

LINK_FLAGS :=	$(LIBFT_FLAGS)

# header flags

HEADER_FLAGS :=	-I $(INC_DIR) -I $(LIBFT_INC)

# rules

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@ mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@ gcc -c $< -o $@ $(HEADER_FLAGS) $(FLAGS)

$(LIBFT):
	@ make -C $(LIB_DIR)

clean:
	@ rm -f $(OBJ)
	@ make clean -C $(LIB_DIR)

fclean:
	@ rm -f $(NAME)
	@ rm -rf $(OBJ_DIR)
	@ make fclean -C $(LIB_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re