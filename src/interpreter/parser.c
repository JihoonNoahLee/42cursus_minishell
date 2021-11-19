/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:49:46 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/19 16:49:47 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_AST_Node	*syntax_analyzer(t_list *token)
{
	t_AST_Node	*node;

	node = parse_get_node(&token);
	return (node);
}
