/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:17:36 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/24 14:26:30 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_rules	init_rules(char **argv)
{
	t_rules	new;

	new.nb_philos = ft_atoi(argv[1]);
	new.tm_die = ft_atoi(argv[2]);
	new.tm_eat = ft_atoi(argv[3]);
	new.tm_sleep = ft_atoi(argv[4]);
	new.limit = 0;
	if (argv[5])
		new.limit = ft_atoi(argv[5]);
	return (new);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(*game));
	if (game)
		memset(game, 0, 2);
	return (game);
}