/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 07:19:27 by nchairun          #+#    #+#             */
/*   Updated: 2025/04/01 08:10:25 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	unclosed_quotes(char *line)
{
	int		i;
	bool	in_single_quotes;
	bool	in_double_quotes;

	i = 0;
	in_single_quotes = false;
	in_double_quotes = false;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			if (in_double_quotes == false)
				in_single_quotes = !(in_single_quotes);
		}
		else if (line[i] == '"')
		{
			if (!in_single_quotes == true)
				in_double_quotes = !(in_double_quotes);
		}
		i++;
	}
	return (in_single_quotes || in_double_quotes);
}

// void minishell_loop(t_shell *minishell, char *line)
// {
//     // bool set_minishell
//     // execute minishell
// }

// bool set_minishell(t_shell *minishell, char *line)
// {
//     // path | minishell->env_path 
//     // lexer | minishell->token
// }