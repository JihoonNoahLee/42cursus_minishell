/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:48:44 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/19 16:48:45 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

void	add_to_list(char *token, t_list **list)
{
	char	*arg;
	t_list	*new;

	arg = ft_strdup(token);
	new = ft_lstnew(arg);
	if (arg == NULL || new == NULL)
		error(MALLOC_ERROR);
	ft_lstadd_back(list, new);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	token_size(char **token)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (token[i++])
		len++;
	return (len);
}
