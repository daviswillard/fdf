NAME = fdf
LIBFT = libft.a
LIB_DIR = libft/
CFLAGS = -Wall -Wextra -Werror -MMD
SRCS = 	sources/main.c				sources/get_map.c \
		sources/get_next_line.c		sources/draw.c	  \
		sources/utils.c 			sources/hooksnwins.c
OBJS = ${SRCS:.c=.o}
DEP = $(SRCS:.c=.d)
all: $(LIBFT) $(NAME)
.c.o:
	gcc $(CFLAGS) -Imlx -c $< -o $@
$(LIBFT):
	$(MAKE) all -sC $(LIB_DIR)
$(NAME): $(OBJS) $(LIBFT)
	gcc $(CFLAGS) $(OBJS) -Lmlx/ -lmlx -framework OpenGL -framework AppKit -L$(LIB_DIR) -lft -o $(NAME)
clean:
	$(MAKE) clean -sC $(LIB_DIR)
	rm -rf $(OBJS) $(DEP)
fclean: clean
	$(MAKE) fclean -sC $(LIB_DIR)
	rm -rf $(NAME).a $(NAME)
re: fclean all
.PHONY: all clean fclean re
-include	$(OBJS:.o=.d)