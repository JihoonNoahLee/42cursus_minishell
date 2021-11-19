/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:51:06 by jihoolee          #+#    #+#             */
/*   Updated: 2021/11/19 16:51:07 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

t_error	set_term_mode(struct termios *term)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, term) == -1)
		return (TERMIOS_ERROR);
	return (SUCCESS);
}

t_error	get_term_mode(struct termios *term)
{
	if (tcgetattr(STDIN_FILENO, term) == -1)
		return (TERMIOS_ERROR);
	return (SUCCESS);
}

t_error	set_nonc_mode(struct termios *term)
{
	rl_catch_signals = 0;
	rl_terminal_name = "dumb";
	term->c_lflag &= ~(ICANON | ECHOCTL);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	return (set_term_mode(term));
}

t_error	set_can_mode(struct termios *term)
{
	term->c_lflag |= (ICANON | ECHOCTL);
	return (set_term_mode(term));
}
