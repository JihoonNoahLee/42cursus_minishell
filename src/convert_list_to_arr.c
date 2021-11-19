/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list_to_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:50:47 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/19 16:50:50 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_list(t_list *list)
{
	int	result;

	result = 0;
	while (list)
	{
		result++;
		list = list->next;
	}
	return (result);
}

char	**convert_list_to_arr(t_list *list)
{
	char	**result;
	int		list_count;
	int		idx;

	idx = 0;
	list_count = count_list(list);
	result = (char **)malloc(sizeof(char *) * (list_count + 1));
	if (result == NULL)
		error(MALLOC_ERROR);
	result[list_count] = NULL;
	while (list)
	{
		result[idx] = ft_strdup((char *)list->content);
		list = list->next;
		idx++;
	}
	return (result);
}
