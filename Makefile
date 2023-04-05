# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slampine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 10:08:26 by slampine          #+#    #+#              #
#    Updated: 2023/02/10 10:08:28 by slampine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = main.c validate_map.c movement.c update_map.c map_creation.c cleanup.c \
map_utils.c
OBJECTS = $(SOURCES:%.c=%.o)
INCLUDE = -lmlx -framework OpenGL -framework AppKit 

all: $(NAME)

$(NAME): $(OBJECTS) so_long.h
	$(MAKE) -C libft
	cp libft/libft.a libft.a
	cc $(CFLAGS) $(OBJECTS) $(INCLUDE) -o $(NAME) libft.a 

clean:
	rm -f $(OBJECTS)
	$(MAKE) clean -C./libft
fclean: clean
	rm -f $(NAME)
	rm -f libft.
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re