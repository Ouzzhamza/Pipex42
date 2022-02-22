/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:51:11 by houazzan          #+#    #+#             */
/*   Updated: 2022/02/22 20:09:22 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<unistd.h>
# include	<sys/wait.h>
# include	<sys/types.h>
# include   <fcntl.h>
# include   <errno.h>

/* **************************************************** */
/*             🅴🆁🆁🅾🆁 🅼🅴🆂🆂🅰🅶🅴🆂                  */
/* **************************************************** */

# define NUMBER   "Number of arguments is wrong.\n"
# define CMD   "Command not found.\n"
# define CMD1   "Command not valid to execute.\n"
# define PIPE   "Pipe problem.\n"
# define FILE  "Please check the existence of files or their permissions.\n"
# define PATH "No path available.\n"

typedef struct s_data
{
	int		infile;
	int		outfile;
	int		id;
	int		id2;
	int		end[2];
	char	*path;
	char	*cmd;
	char	**cmd_args;
	char	**cmd_path;
}	t_data;

char	*path_handling(char **path, char *cmd);

/* **************************************************** */
/*                 🅵🆄🅽🅲🆃🅸🅾🅽🆂                      */
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
/*                   🅿🆁🅾🅲🅴🆂🆂🅴🆂                    */
/* **************************************************** */

void	child_process(t_data *pipex, char *av[], char *envp[]);
void	parent_process(t_data *pipex, char *av[], char *envp[]);

/* **************************************************** */
/*        🅵🆁🅴🅴 & 🅴🆁🆁🅾🆁 🅵🆄🅽🅲🆃🅸🅾🅽🆂            */
/* **************************************************** */

void	ft_free(t_data *pipex);
void	ft_error(t_data *pipex, char *str);
void	err_msg(char *str);

#endif