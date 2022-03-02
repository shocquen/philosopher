/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:48:12 by shocquen          #+#    #+#             */
/*   Updated: 2022/03/02 14:36:41 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	launch_game(t_game *game)
{
	t_time			now;
	t_philo			*philo;
	int				i;

	pgame(game);
	printf(CGRN"============START============\n"CNO);
	gettimeofday(&now, NULL);
	printf("game init at: "CYLW"%0.8f\n"CNO, show_time(&game->start));
	printf("now: "CYLW"%0.8f\n\n"CNO, show_time(&now));
	i = 0;
	while (((t_philo *)game->philos->content)->state != DEAD)
	{
		philo = (t_philo *)game->philos->content;
		if (i++ >= 3)
			((t_philo *)game->philos->content)->state = DEAD;
		pthread_create(&philo->th, NULL, pphilo, philo);
		pthread_join(philo->th, NULL);
		game->philos = game->philos->next;
	}
	gettimeofday(&now, NULL);
	printf("end time: "CYLW"%0.8f\n"CNO, show_time(&now));
	printf("delta: "CYLW"%0.8f\n"CNO, time_diff(&game->start, &now));
}

/* void	launch_game(t_game *game)
{
	struct timeval	time;
	struct timeval	time2;
	t_philo			*philo;
	int				i;

	pgame(game);
	gettimeofday(&time, NULL);
	printf("start time: "CYLW"%ld\n\n"CNO, time.tv_usec);
	i = 0;
	while (((t_philo *)game->philos->content)->state != DEAD)
	{
		philo = (t_philo *)game->philos->content;
		if (i++ >= 3)
			((t_philo *)game->philos->content)->state = DEAD;
		pphilo(philo);
		game->philos = game->philos->next;
		usleep(500000);
	}
	gettimeofday(&time2, NULL);
	printf("end time: "CYLW"%ld\n"CNO, time2.tv_usec);
	printf("delta: "CYLW"%ld\n"CNO, time2.tv_usec - time.tv_usec);
} */
