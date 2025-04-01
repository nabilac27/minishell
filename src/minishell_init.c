/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 05:12:52 by nchairun          #+#    #+#             */
/*   Updated: 2025/04/01 07:08:20 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_shell	*init_minishell(char **env)
{
	t_shell	*minishell;

	minishell = ft_malloc(sizeof(t_shell));
	if (minishell == NULL)
		exit(1);
	minishell->env = dup_env(env);
	// minishell->builtin = dup_builtin();
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

// char	**dup_builtin(void)
// {
// 	char	**builtin;
// 	int		i;

// 	builtin = ft_malloc(8 * sizeof(char *));
// 	if (builtin == NULL)
// 		return (NULL);
// 	builtin[0] = ft_strdup("echo");
// 	builtin[1] = ft_strdup("cd");
// 	builtin[2] = ft_strdup("pwd");
// 	builtin[3] = ft_strdup("export");
// 	builtin[4] = ft_strdup("unset");
// 	builtin[5] = ft_strdup("env");
// 	builtin[6] = ft_strdup("exit");
// 	builtin[7] = NULL;
// 	i = 0;
// 	while (i < 7)
// 	{
// 		gc_add_begin(builtin[i]);
// 		i++;
// 	}
// 	return (builtin);
// }
