# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gpirro <gpirro@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/04 09:45:09 by hthomas       #+#    #+#                  #
#    Updated: 2022/10/28 12:21:06 by gpirro        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################### NAME

NAME 		= 	CUB3D

################################## VPATH

VPATH		=	./gnl/ ./list/ ./srcs/ ./srcs/parsing/ ./srcs/error/ ./srcs/events ./srcs/drawing ./srcs/debug ./srcs/math ./srcs/raycaster ./srcs/minimap

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
LIBFTDIR	= 	./libft/

GNL			=	get_next_line.c

LIBMLXDIR	=	 mlx42
MLX_INCLUDE = 	-I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -Lmlx42 -lmlx42
LIBMLX 		= 	libmlx42.a

################################## DIRECTORIES

PARSING		=	parsing.c \
				parsingutils.c \
				startingpos.c \
				parsetexture.c

EVENTS		=	keypress.c

ERROR		=	error.c \
				errorutils.c \
				get_fn.c

DRAWING		=	drawline.c

MATH		=	rotate.c \
				math_utils.c

RAYCASTER	=	raycaster.c \
				raycasterutils.c

MINIMAP		=	minimap.c \
				minimap_utils.c

################################## FLAGS

CC			=	 gcc
CFLAGS 		+= 	-Wall -Werror -Wextra -g

ifdef sanitize
CFLAGS 		=	-Wall -fsanitize=address -Wextra -g
endif

################################## SRCS

SRCS		=	$(LIST) \
				$(GNL) \
				$(PARSING) \
				$(ERROR) \
				$(EVENTS) \
				$(DRAWING) \
				$(MATH) \
				$(RAYCASTER) \
				$(MINIMAP) \
				render.c \
				utils.c \
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

%.o: %.c $(INCL)
	$(CC) -c $(CFLAGS) -I $(INCL) -o $@ $<

norminette:
	norminette	gnl libft list srcs $(filter-out ./includes/mlx.h ./includes/MLX42.h ./includes/MLX42_Input.h ./includes/.DS_Store, $(shell find $(INCL) -mindepth 1))

sanitize: fclean
	@$(MAKE) sanitize=1

clean:
	cd $(LIBFTDIR) && make clean
	cd $(LIBMLXDIR) && make clean
	rm -rf $(OBJS) $(LIBFT) $(LIBMLX)

fclean:	clean
	cd $(LIBFTDIR) && make fclean
	cd $(LIBMLXDIR) && make clean
	rm -f $(NAME) a.out

re:		fclean all

.PHONY: clean fclean
