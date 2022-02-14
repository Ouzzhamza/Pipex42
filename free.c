#include   "pipex.h"

void    ft_free(t_data *pipex)
{
    int i;

    i = 0;

    while(pipex->cmd_args[i])
    {
        free(pipex->cmd_args[i]);
        i++;
    }
    free(pipex->cmd_path);
    free(pipex->cmd);
}