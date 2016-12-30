/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:38:57 by khansman          #+#    #+#             */
/*   Updated: 2016/11/28 13:39:43 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAIN_FILE
#include "../includes/gomoku.h"

void		dump_mem()
{
	int		i;

	i = -1;
	ft_putstr("\n");
	while (++i < AI.id_count)
	{
		ft_putstr("ID: ");
		ft_putnbr(i);
		ft_putstr(" PID: ");
		ft_putnbr(AI.nodes[i].parentid);
		ft_putstr(" MM: ");
		ft_putnbr(AI.nodes[i].minmax);
		ft_putstr(" BW: ");
		ft_putnbr(AI.nodes[i].branchweight);
		ft_putstr("\n");
	}
}

void		run_ncurses()
{
	init_curses();
	manage_wins();
	manage_ui();
}

int			main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	getopts();
	ft_bzero(&env, sizeof(t_env));
	init_ai();
	run_ncurses();
	dump_mem();
}
