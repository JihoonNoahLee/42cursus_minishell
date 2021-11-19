/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_home.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:50:00 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/19 16:50:01 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	translate_home_case(int case_num, t_list *token, char *line)
{
	char	*temp;

	if (case_num == 1)
	{
		free(line);
		((t_token *)(token->content))->value = get_env_str("HOME");
	}
	else if (case_num == 2)
	{
		temp = ft_strjoin_free(get_env_str("HOME"), "/", 1);
		temp = ft_strjoin_free(temp, line + 2, 1);
		free(line);
		((t_token *)(token->content))->value = temp;
	}
	return (SUCCESS);
}
