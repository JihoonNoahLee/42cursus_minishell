/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_export_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:51:19 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/19 16:51:20 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

int	get_short_len(char *s1, char *s2)
{
	if (ft_strlen(s1) < ft_strlen(s2))
		return (ft_strlen(s1));
	else
		return (ft_strlen(s2));
}

void	sort_export_list(t_list **export_list)
{
	t_list	*cur;
	t_list	*cur2;
	t_list	*temp;
	int		i;

	cur = *export_list;
	while (cur)
	{
		cur2 = *export_list;
		i = -1;
		while (++i < ft_lstsize(*export_list) - 1)
		{
			if (ft_strncmp((char *)(cur2->content)
				, (char *)(cur2->next->content), get_short_len
				((char *)(cur2->content), (char *)(cur2->next->content))) > 0)
			{
				temp = cur2->content;
				cur2->content = cur2->next->content;
				cur2->next->content = temp;
			}
			cur2 = cur2->next;
		}
		cur = cur->next;
	}
}
