/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:51:10 by jihoolee          #+#    #+#             */
/*   Updated: 2022/10/16 23:47:30 by jihoolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

void	show_ascii_art(void)
{
	char	*ascii_art;

	ascii_art = "\
              _       _      __         ____\n\
   ____ ___  (_)___  (_)____/ /_  ___  / / /\n\
  / __ `__ \\/ / __ \\/ / ___/ __ \\/ _ \\/ / / \n\
 / / / / / / / / / / (__  ) / / /  __/ / /  \n\
/_/ /_/ /_/_/_/ /_/_/____/_/ /_/\\___/_/_/   \n\
                                            \n";
	write(1, ascii_art, 271);
}

void	execute_line(t_AST_Node *AST)
{
	if (AST != NULL)
	{
		if (g_shell.cmd_cnt > 1)
			build_pipeline(AST, g_shell.cmd_cnt);
		else
			redir_and_exe(0, AST);
	}
}

void	loop_minishell(struct termios *term)
{
	t_AST_Node	*AST;

	while (1)
	{
		if (set_nonc_mode(term) == TERMIOS_ERROR)
			error(TERMIOS_ERROR);
		g_shell.input_mode |= INPUT_CMD;
		g_shell.line = readline("minishell> ");
		if (g_shell.line == NULL)
		{
			write(STDOUT_FILENO, "\033[1A", 4);
			write(STDOUT_FILENO, "\nminishell> exit\n", 17);
			break ;
		}
		g_shell.input_mode ^= INPUT_CMD;
		if (set_can_mode(term) == TERMIOS_ERROR)
			error(TERMIOS_ERROR);
		add_history(g_shell.line);
		AST = interpreter(g_shell.line);
		execute_line(AST);
		destruct_AST(AST);
		free(g_shell.line);
	}
}

void	handler(int signum)
{
	if (signum == SIGQUIT && g_shell.input_mode & INPUT_CMD)
		return ;
	else if (signum == SIGINT && g_shell.input_mode & INPUT_CMD)
	{
		write(STDOUT_FILENO, "\n", 1);
		if (rl_on_new_line() == -1)
			error(RL_ERROR);
		rl_replace_line("", 1);
		rl_redisplay();
	}
	else if (signum == SIGINT && g_shell.input_mode == INPUT_STDIN)
		write(STDOUT_FILENO, "\n", 1);
	else if (signum == SIGQUIT && g_shell.input_mode == INPUT_STDIN)
		write(STDOUT_FILENO, "Quit: 3\n", 8);
	else if ((signum == SIGINT) && g_shell.input_mode & INPUT_HEREDOC)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\x04");
		write(STDOUT_FILENO, "\n", 1);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	struct termios	term;

	(void)argc;
	(void)argv;
	ft_memset(&g_shell, 0, sizeof(g_shell));
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	if (init_envp(envp) == MALLOC_ERROR)
		error(MALLOC_ERROR);
	if (get_term_mode(&term) == TERMIOS_ERROR)
		error(TERMIOS_ERROR);
	show_ascii_art();
	loop_minishell(&term);
	ft_lstclear(&(g_shell.export_list), free);
	ft_lstclear(&(g_shell.env_list), free);
	return (0);
}
