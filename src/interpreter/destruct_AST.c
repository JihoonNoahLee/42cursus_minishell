/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_AST.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:49:09 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/19 16:49:10 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		if (temp->content)
		{
			free(((t_token *)(temp->content))->value);
			free(temp->content);
		}
		free(temp);
	}
}

void	destruct_AST(t_AST_Node *node)
{
	if (node == NULL)
		return ;
	if (node->type == TYPE_PIPE)
	{
		destruct_AST(((t_pipe *)(node->content))->leftchild);
		destruct_AST(((t_pipe *)(node->content))->rightchild);
		free(node->content);
	}
	else if (node->type == TYPE_REDIRECT)
	{
		destruct_AST(((t_redirect *)(node->content))->child);
		free(((t_redirect *)(node->content))->after_fd);
		free(node->content);
	}
	else
	{
		if (node->content)
		{
			ft_lstclear(&(((t_cmd *)(node->content))->args), free);
			free(((t_cmd *)(node->content))->cmd);
			free(node->content);
		}
	}
	free(node);
}
