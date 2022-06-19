# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 09:45:09 by hthomas           #+#    #+#              #
#    Updated: 2022/06/19 12:55:52 by gianlucapir      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################### NAME

NAME 		= 	CUB3D

################################## VPATH

VPATH		=	./list/ ./srcs/ ./srcs/parsing/ ./srcs/utils/

################################## LIBRARIES

LIST		= 	list_m_add.c \
	  	  		list_m_array_to.c \
		  		list_m_free.c \
		  		list_m_init.c \
		  		list_m_insert.c \
		  		list_m_pop.c \
		  		list_m_popi.c \
		  		list_m_reverse.c \
		  		list_m_get.c \
		  		list_m_to_array.c

LIBFT 		= 	libft/libft.a
LIBFTDIR	= 	libft

GNL			=	gnl/get_next_line.c

LIBMLXDIR	=	 mlx
MLX_INCLUDE = 	-framework OpenGL -framework AppKit
LIBMLX 		= 	libmlx.a
LIBMLXLINK 	= 	-L $(LIBMLXDIR) -lmlx

################################## DIRECTORIES

PARSING		=	parsing.c\
				parsingutils.c

UTILS		=	exit.c

################################## FLAGS

CC			=	 gcc
CFLAGS 		+= 	-Wall -Werror -Wextra -g

ifdef sanitize
CFLAGS 		=	-Wall -fsanitize=address -Wextra -g
endif

################################## SRCS

SRCS		=	$(LIST) $(GNL) \
				$(PARSING) \
				$(UTILS) \
				main.c

OBJS 		= 	$(SRCS:.c=.o)

################################## INCLUDES

INCL 		= 	./includes

################################## LINKING AND COMPILING

all : $(LIBFT) $(LIBMLXDIR)/$(LIBMLX) $(NAME)

$(NAME) : $(OBJS) $(INC) $(LIBFT) $(LIBMLXDIR)/$(LIBMLX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(LIBMLXLINK) $(MLX_INCLUDE)

$(LIBFT) :
	make -C libft all

$(LIBMLXDIR)/$(LIBMLX) :
	make -C $(LIBMLXDIR) all

%.o: %.c $(INC)
	$(CC) -c $(CFLAGS) -I $(INCL) -o $@ $<

norminette:
	norminette	gnl libft list srcs $(filter-out ./includes/mlx.h ./includes/.DS_Store, $(shell find $(INCL) -mindepth 1))

sanitize: fclean
	@$(MAKE) sanitize=1

clean:
	@echo "$(REDL_FG)Deleting .o$(CLEAR_COLOR)"
	cd $(LIBFTDIR) && make clean
	# cd $(LIBMLXDIR) && make clean
	rm -rf $(OBJS) $(LIBFT) $(LIBMLX)

fclean:		clean
	@echo "$(RED_FG)Deleting exe$(CLEAR_COLOR)"
	cd $(LIBFTDIR) && make fclean
	cd $(LIBMLXDIR) && make clean
	rm -f $(NAME) a.out

re:		fclean all

.PHONY: clean fclean
