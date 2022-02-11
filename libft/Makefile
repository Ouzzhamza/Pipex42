CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC	= ft_strlen.c ft_strlcpy.c  ft_strncmp.c ft_strjoin.c ft_split.c \
		ft_strdup.c ft_calloc.c ft_substr.c  ft_putstr_fd.c \


AR  	= ar rcs

OBJ 	=	$(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $@ $^

%.o : %.c libft.h
	@${CC} ${CFLAGS} -c $<

clean : 
	@rm -f $(OBJ) 

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re