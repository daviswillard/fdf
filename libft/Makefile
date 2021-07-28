CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD
NAME = libft.a
SRCS = ft_memset.c ft_bzero.c \
      ft_memcpy.c ft_memccpy.c \
      ft_memcmp.c ft_memmove.c \
      ft_memchr.c ft_strlen.c \
      ft_isalpha.c ft_isdigit.c \
      ft_isalnum.c ft_isascii.c \
      ft_isprint.c ft_toupper.c \
      ft_tolower.c ft_strchr.c \
      ft_strrchr.c ft_substr.c \
      ft_strjoin.c ft_strtrim.c \
      ft_strncmp.c ft_strnstr.c \
      ft_calloc.c ft_strdup.c \
      ft_strlcpy.c ft_itoa.c \
      ft_strmapi.c ft_putchar_fd.c \
      ft_putstr_fd.c ft_putendl_fd.c \
      ft_putnbr_fd.c ft_strlcpy.c \
      ft_strlcat.c ft_atoi.c \
      ft_split.c ft_unite.c
BNS = ft_lstnew.c ft_lstadd_front.c \
      ft_lstsize.c ft_lstlast.c \
      ft_lstadd_back.c ft_lstdelone.c \
      ft_lstclear.c ft_lstiter.c \
      ft_lstmap.c
OBJS = ${SRCS:.c=.o}
BNS_OBJS = ${BNS:.c=.o}
DEP = $(SRCS:.c=.d)
BNS_DEP = ${BNS:.c=.d}
all: $(NAME)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	ar -rcs $(NAME) $?
bonus:
	make OBJS="$(BNS_OBJS)" DEP="$(BNS_DEP)" all
clean:
	rm -rf $(OBJS) $(BNS_OBJS) $(DEP) $(BNS_DEP)
fclean: clean
	rm -rf $(NAME)
re:	fclean all
.PHONY: all clean fclean re bonus
-include	$(OBJS:.o=.d) $(BNS_OBJS:.o=.d)