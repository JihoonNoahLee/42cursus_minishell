/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:34:44 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/03 20:57:45 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H

# include "common.h"

#define CUR_NONE		0
#define CUR_PIPE		1
#define CUR_REDIRECT	2
#define CUR_BEFORE_FD	4
#define CUR_AFTER_FD	8
#define CUR_CMD			16
#define CUR_ARG			32
#define CUR_QUOTE		64
#define CUR_DQUOTE		128

typedef struct s_token
{
	int		type;
	char	*value;
}	t_token;

typedef struct s_pipe
{
	int			count;
	t_AST_Node	*leftchild;
	t_AST_Node	*rightchild;
}	t_pipe;

typedef struct s_redirect
{
	int			type;
	int			before_fd;
	char		*after_fd;
	t_AST_Node	*child;
}	t_redirect;

typedef struct s_cmd
{
	char	*cmd;
	t_list	*args;
}	t_cmd;

t_AST_Node	*interpreter(char *line);
t_list		*lexical_analyzer(char *line);
char		*get_special_item(char **line, int *cur_option);
char		*get_plain_item(char **line, int *cur_option);
t_AST_Node	*syntax_analyzer(t_list *token);
int			type_argument(t_cmd *cmd, t_list **arg, t_token *token);
int			type_redirect(t_AST_Node **curr, t_list **token);
t_AST_Node	*parse_cmd(t_list **token);
t_AST_Node	*parse_get_node(t_list **token);

void		malloc_error_check(void *item);
int			ft_malloc(void **dst, size_t size);
int 		check_invalid_fd(char *word);
int			set_quote_option(char **line, int *cur_option);

void 		print_series_token(t_list *token);
void		print_JSON(t_AST_Node	*AST, int indent);
void		print_indent(int indent);

#endif
