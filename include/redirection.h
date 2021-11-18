/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:00:47 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/18 20:55:23 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "common.h"
# include "interpreter.h"

# define INVALID_FD	-1

typedef struct s_fd
{
	int	fd_shell;
	int	fd_proc;
}	t_fd;

t_fd	*fd_new(int fd_shell, int fd_proc);
int		search_proc_fd(t_list *fd_table, int shell_fd);
t_error	handle_redir(t_list **fd_table, t_redirect *redir);

t_list	*init_fd_table(void);

/*
format_filename.c
*/
char	*format_filename(int idx);

/*
redirect.c
*/
t_error	redirect(int redir_to_fd, t_list **fd_table, t_redirect *redir);

#endif
