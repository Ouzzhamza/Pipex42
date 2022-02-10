#ifndef PIPEX_H
# define PIPEX_H


# include	<stdio.h>
# include	<unistd.h>
# include	<sys/wait.h>
# include	<sys/types.h>
# include 	<fcntl.h>



typedef struct s_data
{
    int file1;
    int file2;
    int pend;
    char *path;

}   t_data;



# endif