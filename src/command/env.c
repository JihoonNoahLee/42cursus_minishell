/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:47:54 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/19 16:47:56 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

int	get_env(void)
{
	t_list	*envp;

	envp = g_shell.env_list;
	while (envp)
	{
		printf ("%s\n", (char *)(envp->content));
		envp = envp->next;
	}
	return (SUCCESS);
}
