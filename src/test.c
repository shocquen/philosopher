/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:03:03 by shocquen          #+#    #+#             */
/*   Updated: 2022/03/05 11:02:03 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*pphilo(void *philo)
{
	t_time	now;

	gettimeofday(&now, NULL);
	printf(
		"\tPhilo->index: "CYLW"%d\n"CNO
		"\tPhilo->state: "CYLW"%d\n"CNO
		"\tPhilo->fork: "CYLW"%d\n"CNO
		"\tDelta: "CYLW"%0.8f\n\n"CNO,
		((t_philo *)philo)->index,
		((t_philo *)philo)->state,
		((t_philo *)philo)->fork,
		time_diff(&((t_philo *)philo)->birth, &now)
		);
	ft_usleep(500000);
	return (NULL);
}

static void	ft_lstiter(t_lst *lst, void *(*f)(void *), unsigned int i)
{
	while (lst && i--)
	{
		if (f)
			(f)(lst->content);
		lst = lst->next;
	}
}

void	pgame(t_game *game)
{
	t_lst	*tmp;

	printf(
		CYLW"Game rules:\n"CNO
		"\trule.nb_philo: "CYLW"%d\n"CNO
		"\trule.tm_die: "CYLW"%d\n"CNO
		"\trule.tm_eat: "CYLW"%d\n"CNO
		"\trule.tm_sleep "CYLW"%d\n"CNO
		"\trule.limit: "CYLW"%d\n\n"CNO
		CYLW"Game philos:\n"CNO,
		game->rules.nb_philos,
		game->rules.tm_die,
		game->rules.tm_eat,
		game->rules.tm_sleep,
		game->rules.limit
		);
	tmp = game->philos;
	ft_lstiter(tmp, &pphilo, game->rules.nb_philos);
}

float	time_diff(struct timeval *start, struct timeval *end)
{
	return ((end->tv_sec - start->tv_sec) + (1e-6)
		* (end->tv_usec - start->tv_usec));
}

float	show_time(struct timeval *start)
{
	return ((start->tv_sec) + (1e-6) * (start->tv_usec));
}
