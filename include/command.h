/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:46:26 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/19 16:46:30 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "common.h"
# include "interpreter.h"

# define END 1

void	free_str(char **str);
int		token_size(char **token);
int		run_cd(t_list *args, t_list *fd_table);
int		get_pwd(t_list *fd_table);
void	print_export_list(void);
void	add_to_list(char *token, t_list **list);
int		run_export(t_list *args);
int		check_dup(t_list *list, char *arg);
int		run_unset(t_list *args);
int		get_env(void);
int		ft_exit(t_list *args, t_list *fd_table);
void	run_execve(t_cmd *cmd);

#endif
