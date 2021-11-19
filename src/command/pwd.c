/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:48:31 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/19 16:48:33 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_pwd(t_list *fd_table)
{
	int		stdout_fd;
	char	*path;

	stdout_fd = search_proc_fd(fd_table, 1);
	path = getcwd(NULL, 0);
	if (path == NULL)
		error(MALLOC_ERROR);
	write(stdout_fd, path, ft_strlen(path));
	write(stdout_fd, "\n", 1);
	free(path);
	path = NULL;
	return (SUCCESS);
}
