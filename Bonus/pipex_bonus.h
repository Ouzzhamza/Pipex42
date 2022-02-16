/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:51:22 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/16 21:55:59 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<unistd.h>
# include	<sys/wait.h>
# include	<sys/types.h>
# include   <fcntl.h>
# include   <errno.h>

# define NUMBER   "insufficient Number of arguments.\n"
# define CMD   "command not found : "
# define PIPE   "Pipe"
# define FILE  "infile"
# define PATH "no path available"

typedef struct s_bdata
{
	int		infile;
	int		outfile;
	int		end[2];
	char	*path;
	char	*cmd;
	char	**cmd_args;
	char	**cmd_path;
}	t_bdata;

char	*path_handling_bonus(char **path, char *cmd);

/* **************************************************** */
/*                   Functions                          */
/* **************************************************** */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);

/* **************************************************** */
/*                   The child file                     */
/* **************************************************** */

void	child_process_bonus(t_bdata *pipex, char *av[], char *envp[]);
void	parent_process_bonus(t_bdata *pipex, char *av[], char *envp[]);

/* **************************************************** */
/*              free & error functions                  */
/* **************************************************** */

void	ft_free_bonus(t_bdata *pipex);
void	ft_error_bonus(t_bdata *pipex, char *str);
int		err_msg_bonus(t_bdata *pipex, char *str);

#endif