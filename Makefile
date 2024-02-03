NAME = push_swap

SRCS =	ft_utils_lst.c \
		ft_utils3.c \
		ft_utils2.c \
		ft_basic_sort.c \
		ft_radix.c \
		push_swap.c \
		ft_free.c \
		ft_check.c \
		ft_index.c \
		ft_spr.c 

OBJS = $(SRCS:.c=.o)

CC = gcc

AFLAGS =  -Wall -Wextra -Werror

RM = rm -rf

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(AFLAGS) $(OBJS) -o $(NAME)

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJS)

re : fclean all

.PHONY : all fclean clean re