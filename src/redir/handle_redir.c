/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:07:34 by jihoolee          #+#    #+#             */
/*   Updated: 2021/10/21 17:03:12 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redir.h"

t_redir_type	check_redir_type(char *token)
{

}

t_error	handle_redir(t_fd **fd_table, t_token **tokens)
{
	int		iter;
	t_list	*redirs;
	t_redir	redir;

	iter = 0;
	while (tokens[iter])
	{
		redir = parse_redir(tokens + iter);
		if (redir.type >= INPUT)
		{
			append_redir(redir, &redirs);
			del_redir_tokens();
		}
		else
			iter++;
	}
	return (SUCCESS);
}
