/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 04:46:31 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/31 04:51:37 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **envp)
{
    t_shell *minishell;

    minishell = NULL;
    (void)argc;
    (void)argv;
    (void)envp;
    printf("%p\n", (void *)minishell);
}