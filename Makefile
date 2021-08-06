NAME = fdf
LIBFT = libft.a
LIB_DIR = ./libft/
CFLAGS = -Wall -Wextra -Werror -MMD
SRCS = 	sources/main.c				sources/get_map.c \
		sources/get_next_line.c		sources/draw.c
OBJS = ${SRCS:.c=.o}
DEP = $(SRCS:.c=.d)
all: $(LIBFT) $(NAME)
.c.o:
	gcc $(CFLAGS) -Imlx -c $< -o $@
$(LIBFT):
	$(MAKE) all -C $(LIB_DIR)
	$(MAKE) bonus -C $(LIB_DIR)
$(NAME): $(OBJS)
	cp $(LIB_DIR)$(LIBFT) $(NAME).a
	ar -rcs $(NAME).a $(OBJS)
	gcc $(CFLAGS) -Lmlx/ -lmlx -framework OpenGL -framework AppKit $(NAME).a -o $(NAME)
clean:
	$(MAKE) clean -sC $(LIB_DIR)
	rm -rf $(OBJS) $(DEP)
fclean: clean
	$(MAKE) clean -sC $(LIB_DIR)
	rm -rf $(NAME).a $(NAME)
re: fclean all
.PHONY: all clean fclean re
-include	$(OBJS:.o=.d)