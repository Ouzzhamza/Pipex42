#ifndef PIPEX_H
# define PIPEX_H


# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<unistd.h>
# include	<sys/wait.h>
# include	<sys/types.h>
# include 	<fcntl.h>
# include 	<errno.h>




typedef struct s_data
{
    int file1;
    int file2;
    int fd[2];
    char *path;
    char **command;

}   t_data;

/* **************************************************** */
/*                   The main file                      */
/* **************************************************** */

int main(int ac, char *av[], char *envp[]);



/* **************************************************** */
/*                   Functions                          */
/* **************************************************** */
 int     ft_strncmp(const char *s1, const char *s2, size_t n);
 char	*ft_strdup(const char *src);
 void	ft_putstr_fd(char *s, int fd);
 void	ft_error(void);


/* **************************************************** */
/*                   The child file                     */
/* **************************************************** */

void child_process(t_data *pipex, char *av[]);




# endif