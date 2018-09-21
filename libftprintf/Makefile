#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 17:45:08 by ivoloshi          #+#    #+#              #
#    Updated: 2018/05/23 17:45:10 by ivoloshi         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# name of the executable file

NAME :=			libftprintf.a

# project directories

SRC_DIR :=		./src/
OBJ_DIR :=		./obj/
INC_DIR :=		./inc/
LIB_DIR :=		./libft/

# project source files

#
# need to add all c files by name
#

SRC :=			ft_printf.c \
				numbers.c \
				numbers2.c \
				reading.c \
				strings.c \
				strings2.c\
				conversions.c \
				chars.c \
				unsignedconv.c \
				pointers.c \
				lenght.c \
				ft_itoa_base.c \
				ft_len_u.c \
				hash.c \
				precision_zeros.c \
				utf_str.c \

# project object files

OBJ = 			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# libraries

LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=	$(LIB_DIR)
LIBFT_INC :=	$(LIBFT_DIR)
LIBFT_FLAGS :=	-lft -L $(LIBFT_DIR)

# compilation flags

FLAGS := -Wall -Wextra -Werror -O3

# linking flags

LINK_FLAGS :=	$(LIBFT_FLAGS)

# header flags

HEADER_FLAGS :=	-I $(INC_DIR) -I $(LIBFT_INC)

# rules

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@ ar rc $(NAME) $(OBJ) libft/*.o
		@ ranlib $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@ mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@ gcc -c $< -o $@ -I $(FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@ make -C $(LIBFT_DIR)

clean:
	@ rm -f $(OBJ)
	@ make clean -C $(LIBFT_DIR)

fclean:
	@ rm -f $(NAME)
	@ rm -rf $(OBJ_DIR)
	@ make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re