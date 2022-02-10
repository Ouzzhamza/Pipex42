CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC	= ft_strlen.c ft_strlcpy.c  ft_strncmp.c ft_bzero.c ft_split.c \
		ft_strdup.c ft_calloc.c ft_substr.c  \

	
	
		

SRC_B = ft_lstnew.c	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		ft_lstmap.c \



AR  	= ar rcs

OBJ 	=	$(SRC:%.c=%.o)

OBJ_B	=	$(SRC_B:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $@ $^

%.o : %.c libft.h
	@${CC} ${CFLAGS} -c $<

bonus: ${NAME} $(OBJ_B)
	@$(AR) $^
	@echo "Your libft.a has been created successfully \n"

clean : 
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : bonus all clean fclean re