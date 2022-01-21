NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
AR = ar rcs
RM = rm -f
FILES = src/push \
	src/push_utilsa \
	src/push_utilsb \
	src/pushutils	\
	src/pushutils2	\
	src/pushutils3	\
	src/pushutils4	\
	src/pushutils5	\
	  libft/ft_lstadd_front \
	  libft/ft_lstsize \
 	 libft/ft_lstlast \
	 libft/ft_lstadd_back \
	 libft/ft_lstdelone \
	  libft/ft_lstclear \
	  libft/ft_lstiter \
	  libft/ft_lstmap \
	  libft/ft_lstnew \
	  libft/ft_memset \
        libft/ft_bzero        \
        libft/ft_memcpy       \
        libft/ft_memccpy      \
        libft/ft_memmove	\
        libft/ft_memchr        \
        libft/ft_memcmp        \
        libft/ft_strlen        \
        libft/ft_isalpha    	\
        libft/ft_isdigit        \
        libft/ft_isalnum        \
        libft/ft_isascii        \
        libft/ft_isprint        \
        libft/ft_toupper        \
        libft/ft_tolower        \
        libft/ft_strchr       \
        libft/ft_strrchr        \
        libft/ft_strncmp       \
        libft/ft_strlcpy        \
        libft/ft_strlcat        \
        libft/ft_strnstr       \
        libft/ft_atoi       \
        libft/ft_calloc        \
        libft/ft_strdup      \
		libft/ft_strtrim	\
		libft/ft_substr		\
		libft/ft_putchar_fd	\
		libft/ft_putstr_fd	\
		libft/ft_putendl_fd	\
		libft/ft_putnbr_fd	\
		libft/ft_putnbr	\
		libft/ft_strjoin	\
		libft/ft_itoa \
		libft/ft_split		\


SRCS_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: clean all

.PHONY: clean fclean %.o
