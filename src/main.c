/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:57:57 by shocquen          #+#    #+#             */
/*   Updated: 2022/03/01 17:41:08 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (check_args(argc, argv))
		return (1);
	game = init_game();
	if (!game)
		return (1);
	game->rules = init_rules(argv);
	gettimeofday(&game->start, NULL);
	generate_philos(&game);
	launch_game(game);
	ft_lstclear(&game->philos, free, game->rules.nb_philos);
	free(game);
	return (0);
}

/* 
	1: number_of_philosophers
	2: time_to_die (in milliseconds)
	3: time_to_eat (in milliseconds)
	4: time_to_sleep (in milliseconds)
	5: number_of_times_each_philosopher_must_eat (optional argument)
*/