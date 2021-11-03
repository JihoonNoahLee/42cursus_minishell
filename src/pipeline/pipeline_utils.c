/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:54:22 by bylee             #+#    #+#             */
/*   Updated: 2021/11/03 21:08:12 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_exit(int error_code)
{
	printf("error : %d\n", error_code);
	exit(error_code);
}

int	hookup_pipes(int idx_cmd, int **fd_pipe, int nums_cmd)
{
	if (idx_cmd == 0)
	{
		if (dup2(fd_pipe[idx_cmd][1], STDOUT_FILENO) == -1)
			return (FD_DUP_ERROR);
	}
	else if (idx_cmd == nums_cmd - 1)
	{
		if (dup2(fd_pipe[idx_cmd - 1][0], STDIN_FILENO) == -1)
			return (FD_DUP_ERROR);
	}
	else
	{
		if (dup2(fd_pipe[idx_cmd][1], STDOUT_FILENO) == -1
			|| dup2(fd_pipe[idx_cmd - 1][0], STDIN_FILENO) == -1)
			return (FD_DUP_ERROR);
	}
	return (SUCCESS);
}

void	free_fd_table(int **fd_pipe)
{
	int	i;

	i = -1;
	while (fd_pipe[++i])
		free(fd_pipe[i]);
	free(fd_pipe);
}

void	close_fd_table(int nums_cmd, int **fd_pipe, int idx_cmd)
{
	int	i;

	i = -1;
	while (++i < nums_cmd - 1)
	{
		if (idx_cmd - 1 != i)
			close(fd_pipe[i][0]);
		if (idx_cmd != i)
			close(fd_pipe[i][1]);
	}
}

int	**malloc_fd_table(int nums_cmd)
{
	int	**fd_pipe;
	int	i;

	i = -1;
	fd_pipe = (int **)malloc(sizeof(int *) * nums_cmd);
	if (fd_pipe == NULL)
		return (NULL);
	fd_pipe[nums_cmd - 1] = NULL;
	while (++i < nums_cmd - 1)
	{
		fd_pipe[i] = (int *)malloc(sizeof(int) * 2);
		if (fd_pipe[i] == NULL)
		{
			free_fd_table(fd_pipe);
			return (NULL);
		}
	}
	return (fd_pipe);
}

int	fill_fd_table(int nums_cmd, int **fd_pipe)
{
	int	i;

	i = -1;
	while (++i < nums_cmd - 1)
	{
		if (pipe(fd_pipe[i]))
		{
			free_fd_table(fd_pipe);
			return (PIPE_ERROR);
		}
	}
	return (0);
}
