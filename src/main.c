/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:46:31 by nchairun          #+#    #+#             */
/*   Updated: 2025/04/01 04:54:08 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell				*minishell;
	t_garbage_collector	*gc_init_garbage_collector();

	if (argc != 1 || *argv == NULL)
		return (2);
	minishell = init_minishell(envp);
	gc_free_all();
	return (0);
}
