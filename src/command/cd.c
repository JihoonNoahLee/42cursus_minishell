/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:47:43 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/19 16:47:48 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_cd(t_list *args, t_list *fd_table)
{
	int		result;
	int		err_fd;
	char	*path;

	err_fd = search_proc_fd(fd_table, 2);
	if (args == NULL)
	{
		path = get_env_str("HOME");
		result = chdir(path);
		free(path);
	}
	else
		result = chdir((char *)args->content);
	if (result == -1)
	{
		write(err_fd, "bash: cd: ", 10);
		write(err_fd, args->content, ft_strlen(args->content));
		write(err_fd, ": No such file or directory\n", 28);
		return (1);
	}
	return (SUCCESS);
}
