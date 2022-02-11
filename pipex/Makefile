CC = gcc 

CFLAGS = -Wall -Wextra -Werror -Imlx -Ofast

NAME = pipex

SRC = pipex.c child_process.c parent_process.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ../libft
	@$(CC) $(OBJ) ../libft/libft.a -o $(NAME)
	@echo "\n$(GREEN) $(BOLD)Your programme is ready to run$(END)\n"
	

%.o : %.c pipex.h
	@$(CC) $(CFLAGS) -c $<

bonus : all

clean :
	@make fclean -C ../libft
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)
	@echo "\n$(BOLD)$(RED)Programme have been cleaned$(END)\n"

re : fclean all

.PHONY : all clean fclean re