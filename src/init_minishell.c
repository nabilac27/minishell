/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:12:52 by nchairun          #+#    #+#             */
/*   Updated: 2025/04/01 04:48:33 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**dup_env(char **envp);

t_shell	*init_minishell(char **env)
{
	t_shell	*minishell;

	minishell = malloc(sizeof(t_shell));
	if (minishell == NULL)
		exit(1);
	minishell->env = dup_env(env);
	minishell->exit_code = 0;
	return (minishell);
}

char	**dup_env(char **envp)
{
	int		len;
	char	**result;
	int		i;

	len = 0;
	while (envp[len])
		len++;
	result = ft_malloc((len + 1) * sizeof(char **));
	if (result == NULL)
		exit(1);
	i = 0;
	while (i < len)
	{
		result[i] = ft_strdup(envp[i]);
		gc_add_begin(result[i]);
		if (result[i] == NULL)
		{
			gc_free_all();
			exit(1);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
