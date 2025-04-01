/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:43:29 by nchairun          #+#    #+#             */
/*   Updated: 2025/04/01 07:26:19 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>

typedef struct s_shell
{
	char	**env;
	char	**builtin;
	int		exit_code;
	char	**env_path;
}			t_shell;

//	minishell_init.c
t_shell		*init_minishell(char **env);
char		**dup_env(char **envp);
char		**dup_builtin(void);

// minishell_loop.c
bool		unclosed_quotes(char *line);

#endif