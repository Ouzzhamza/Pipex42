CC = gcc 

CFLAGS = -Wall -Wextra -Werror -g

NAME = pipex

SRC = pipex.c processes.c errors.c free.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft
	@$(CC) $(OBJ) ./libft/libft.a -o $(NAME) 
	@echo "\n$(GREEN) $(BOLD)Your programme is ready to run$(END)\n"
	

%.o : %.c pipex.h
	@$(CC) $(CFLAGS) -c $<

bonus : all

clean :
	@make fclean -C ./libft 
	@rm -rf $(OBJ)  outfile

fclean : clean
	@rm -rf $(NAME)
	@echo "\n$(BOLD)$(RED)Programme have been cleaned$(END)\n"

re : fclean all

.PHONY : all clean fclean re