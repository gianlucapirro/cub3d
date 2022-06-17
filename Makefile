# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 09:45:09 by hthomas           #+#    #+#              #
#    Updated: 2022/06/18 01:40:35 by gianlucapir      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MAKE = make
CC = gcc
CFLAGS += -Wall -Werror -Wextra

COMMONS =	srcs/main.c

SRCS =	$(COMMONS)

OBJS = $(SRCS:.c=.o)

INCL = includes/
HEADER = $(INCL)cub3d.h

LIBFT = libft.a
LIBFTDIR = libft
LIBFTINCL = includes/
LIBMLXDIR	= mlx
MLX_INCLUDE = -framework OpenGL -framework AppKit
LIBMLX = libmlx.a
LIBMLXLINK = -L $(LIBMLXDIR) -lmlx

###########################ALL
all : $(LIBFTDIR)/$(LIBFT) $(LIBMLXDIR)/$(LIBMLX) $(NAME)

$(NAME) : $(OBJS) $(HEADER) $(LIBFTDIR)/$(LIBFT) $(LIBMLXDIR)/$(LIBMLX)
	$(CC) -o $@ $(OBJS) $(LIBMLXLINK) $(MLX_INCLUDE)

###########################LIBS
$(LIBFTDIR)/$(LIBFT) :
	$(MAKE) -C libft all

$(LIBMLXDIR)/$(LIBMLX) :
	$(MAKE) -C $(LIBMLXDIR) all

%.o: %.c $(HEADER)
	$(CC) -c $(LDFLAGS) -I $(INCL) -o $@ $<

###########################CLEAN
clean:
	@echo "$(REDL_FG)Deleting .o$(CLEAR_COLOR)"
	cd $(LIBFTDIR) && $(MAKE) clean
	# cd $(LIBMLXDIR) && $(MAKE) clean
	rm -rf $(OBJS) $(LIBFT) $(LIBMLX)

fclean:		clean
	@echo "$(RED_FG)Deleting exe$(CLEAR_COLOR)"
	cd $(LIBFTDIR) && $(MAKE) fclean
	cd $(LIBMLXDIR) && $(MAKE) clean
	rm -f $(NAME) a.out

re:		fclean all

.PHONY: clean fclean
