/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:43:29 by nchairun          #+#    #+#             */
/*   Updated: 2025/04/01 04:53:09 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

typedef struct s_shell
{
	char	**env;
	int		exit_code;
}			t_shell;

t_shell		*init_minishell(char **env);

#endif