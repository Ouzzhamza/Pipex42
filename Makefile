#COMPILATION FLAGS

CC       = gcc 

CFLAGS   = -Wall -Wextra -Werror 
#CFLAGS	+= --no-print-directory

#FILES AND PATHES
NAME     = pipex
BNAME    = pipex_bonus


#functions
FSRC_DIR = functions/
FSRC 	 = ft_bzero.c ft_calloc.c ft_putstr_fd.c ft_split.c \
		   ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c \
		   ft_strncmp.c ft_strcmp.c get_next_line.c\

FSPATH   = $(addprefix $(FSRC_DIR), $(FSRC))
OBJ_F    = $(FSPATH:%.c=%.o)

#mandatory
MSRC_DIR = mandatory/
MSRC     = pipex.c processes.c errors.c free.c 
MSPATH   = $(addprefix $(MSRC_DIR), $(MSRC))
OBJ_M    = $(MSPATH:%.c=%.o)

#bonus
BSRC_DIR = bonus/
BSRC     = bonus_pipex.c bonus_errors.c bonus_processes.c bonus_free.c her_doc.c\

BSPATH   = $(addprefix $(BSRC_DIR), $(BSRC))
OBJ_B    = $(BSPATH:%.c=%.o)


#COMANDS
all      : $(NAME) $(BNAME)
mandatory: $(NAME)
bonus    : $(BNAME)

$(NAME)  : $(OBJ_F) $(OBJ_M)
		 $(CC) $(OBJ_F) $(OBJ_M) -o $(NAME) 
		 @echo "$(GREEN)$(BOLD)MANDATORY CREATED! $(END)"
	
$(BNAME) : $(OBJ_F) $(OBJ_B)
		 $(CC) $(OBJ_F) $(OBJ_B) -o $(BNAME)
		 @echo "$(GREEN)$(BOLD)BONUS CREATED! $(END)"


%.o      :%.c pipex.h bonus_pipex.h
	  	 @$(CC) $(CFLAGS) -c $< -o 



clean    :
	     rm -rf $(OBJ_M) $(OBJ_B) $(OBJ_F) outfile .temp
	     @echo "$(BOLD)$(ORANGE)OBJECT FILE DELETED !$(END)"

fclean   : clean
	     rm -rf $(NAME) $(BNAME)
	     @echo "$(BOLD)$(RED)ALL DELETED !$(END)"

re       : fclean all 


.PHONY  : all clean fclean re
.SILENT :

#COLOR

GREEN = \033[1;32m
RED = \033[1;31m
ORANGE = \033[0;33m