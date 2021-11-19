/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_and_exe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:51:15 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/19 16:51:16 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

static void	delete_tempfile(int idx_cmd)
{
	char	*filename;

	filename = format_filename(idx_cmd);
	if (filename == NULL)
		error(MALLOC_ERROR);
	unlink(filename);
	free(filename);
}

static void	clear_redir_fd(t_list **fd_table)
{
	t_list	*curr;

	curr = *fd_table;
	while (curr)
	{
		close(((t_fd *)(curr->content))->fd_proc);
		curr = curr->next;
	}
	ft_lstclear(fd_table, free);
}

void	redir_and_exe(int idx_cmd, t_AST_Node *node)
{
	t_list		*fd_table;
	t_AST_Node	*curr;

	fd_table = init_fd_table();
	if (fd_table == NULL)
		error(MALLOC_ERROR);
	curr = node;
	while (curr->type == TYPE_REDIRECT)
	{
		if (handle_redir(&fd_table, curr->content) != SUCCESS)
			break ;
		curr = ((t_redirect *)curr->content)->child;
	}
	if (curr->type == TYPE_CMD)
		execute_cmd(curr, fd_table);
	clear_redir_fd(&fd_table);
	delete_tempfile(idx_cmd);
}
