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


# define NUMBER   "insufficient Number of arguments.\n"
# define CMD   "command not found : "
# define PIPE   "Pipe"
# define FILE  "INFILE"





typedef struct s_data
{
    int infile;
    int outfile;
    int end[2];
    char *path;
    char *cmd;
    char **cmd_args;
    char **cmd_path;

}   t_data;

/* **************************************************** */
/*                   The main file                      */
/* **************************************************** */

int     main(int ac, char *av[], char *envp[]);
char  *path_handling(char **path, char *cmd);


/* **************************************************** */
/*                   Functions                          */
/* **************************************************** */
 int    ft_strncmp(const char *s1, const char *s2, size_t n);
 char	*ft_strjoin(char const *s1, char const *s2);
 char	**ft_split(char const *s, char c);
 void   ft_putstr_fd(char *s, int fd);
 char   *ft_strdup(const char *src);
 void   ft_error(char *str);
 int    err_msg(char *str);


/* **************************************************** */
/*                   The child file                     */
/* **************************************************** */

void child_process1(t_data *pipex, char *av[], char *envp[]);
void child_process2(t_data *pipex, char *av[], char *envp[]);




# endif