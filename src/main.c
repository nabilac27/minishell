/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:46:31 by nchairun          #+#    #+#             */
/*   Updated: 2025/04/01 07:01:26 by nchairun         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	t_shell				*minishell;
	t_garbage_collector	*gc_init_garbage_collector();
	char				*line;

	if (argc != 1 || *argv == NULL)
		return (2);
	minishell = init_minishell(envp);
	while (1)
	{
		line = readline("$ ");
		if (line == NULL)
			break ;
		if (unclosed_quotes(line) == true)
			printf("error: there is unclosed quote");
	}
	gc_free_all();
	return (0);
}
