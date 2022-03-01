/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:48:12 by shocquen          #+#    #+#             */
/*   Updated: 2022/03/01 15:03:52 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	launch_game(t_game *game)
{
	t_time			time[3];
	t_philo			*philo;
	int				i;

	memset(time, 0, sizeof(*time));
	pgame(game);
	printf(CGRN"============START============\n"CNO);
	gettimeofday(&time[0], NULL);
	printf("start time: "CYLW"%ld\n\n"CNO, time[0].tv_usec);
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
	gettimeofday(&time[1], NULL);
	printf("end time: "CYLW"%ld\n"CNO, time[1].tv_usec);
	printf("delta: "CYLW"%ld\n"CNO, time[1].tv_usec - time[0].tv_usec);
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
