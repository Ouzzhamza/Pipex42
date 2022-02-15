#COMPILATION FLAGS

CC       = gcc 

CFLAGS   = -Wall -Wextra -Werror 
#CFLAGS	+= --no-print-directory

#FILES AND PATHES

NAME     = pipex

#functions
FSRC_DIR = functions/
FSRC 	 = ft_bzero.c ft_calloc.c ft_putstr_fd.c ft_split.c \
		   ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c \
		   ft_strncmp.c 
FSPATH   = $(addprefix $(FSRC_DIR), $(FSRC))
OBJ_F    = $(FSPATH:%.c=%.o)

#mandatory
MSRC_DIR = mandatory/
MSRC     = pipex.c processes.c errors.c free.c 
MSPATH   = $(addprefix $(MSRC_DIR), $(MSRC))
OBJ_M    = $(MSPATH:%.c=%.o)


#COMANDS
all : $(NAME)

$(NAME) : $(OBJ_F) $(OBJ_M)
		$(CC) $(OBJ_F) $(OBJ_M) -o $(NAME) 
		@echo "$(GREEN) $(BOLD)DONE $(END)"
	
%.o :%.c pipex.h 
	 @$(CC) $(CFLAGS) -c $<

#bonus : all

clean :
	 rm -rf $(OBJ_M) $(OBJ_F) outfile

fclean : clean
	  rm -rf $(NAME)
	  @echo "$(BOLD)$(RED)DONE$(END)"

re : fclean all


.PHONY : all clean fclean re
.SILENT :

#COLOR

GREEN = \033[1;32m
RED = \033[1;31m