/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:48:38 by jihoolee          #+#    #+#             */
/*   Updated: 2022/10/16 21:11:04 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

int	del_first_node(t_list **list, char *arg)
{
	char	**env;
	t_list	*temp;

	env = ft_split((*list)->content, '=');
	if (ft_strncmp(arg, env[0], ft_strlen(arg) + 1) == 0)
	{
		temp = (*list);
		*list = (*list)->next;
		free(temp->content);
		free(temp);
		free_str(env);
		return (SUCCESS);
	}
	free_str(env);
	return (1);
}

void	del_middle_node(t_list **list, char *arg)
{
	char	**env;
	t_list	*curr;
	t_list	*former;

	curr = *list;
	while (curr)
	{
		env = ft_split(curr->content, '=');
		if (ft_strncmp(arg, env[0], ft_strlen(arg) + 1) == 0)
		{
			former->next = curr->next;
			curr->next = NULL;
			free(curr->content);
			free(curr);
			curr = former->next;
		}
		else
		{
			former = curr;
			curr = curr->next;
		}
		free_str(env);
	}
}

void	del_node(t_list	**env_list, char *arg)
{
	if (!del_first_node(env_list, arg))
		return ;
	else
		del_middle_node(env_list, arg);
}

int	run_unset(t_list *args)
{
	int	result;

	result = 0;
	while (args)
	{
		result = check_dup(g_shell.export_list, (char *)args->content);
		if (result == 1)
			del_node(&g_shell.export_list, (char *)args->content);
		result = 0;
		result = check_dup(g_shell.env_list, (char *)args->content);
		if (result == 1)
			del_node(&g_shell.env_list, (char *)args->content);
		args = args->next;
	}
	return (SUCCESS);
}
