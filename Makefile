LIBFT = ./LIBFT/libft.a

NAME = libftprintf.a

SRCS =  ft_printf.c ft_printf_parse.c ft_printf_chars.c ft_printf_char_utils.c \
		ft_printf_pointers.c  ft_printf_numbers.c ft_printf_number_utils.c \

SRCSB = ft_printf_bonus.c ft_printf_parse.c ft_printf_chars.c ft_printf_char_utils.c \
		ft_printf_pointers.c  ft_printf_numbers.c ft_printf_number_utils.c ft_printf_flag_utils.c \
		ft_printf_chars_bonus.c ft_printf_pointers_bonus.c ft_printf_numbers_bonus.c \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror


OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) all -C ./LIBFT
	cp LIBFT/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

bonus: $(OBJSB)
	$(MAKE) all -C ./LIBFT
	cp LIBFT/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCSB)
	ar -rcs $(NAME) $(OBJSB)

clean :
	$(MAKE) clean -C ./LIBFT
	rm -rf $(OBJS) $(OBJSB)

fclean : clean
	$(MAKE) fclean -C ./LIBFT
	rm -rf $(NAME)

re : fclean all
