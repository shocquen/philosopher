/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:03:03 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/24 19:03:59 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pphilo(void *philo)
{
	printf(
		"\tPhilo->index: "CYLW"%d\n"CNO
		"\tPhilo->state: "CYLW"%d\n"CNO
		"\tPhilo->fork: "CYLW"%d\n\n"CNO,
		((t_philo *)philo)->index,
		((t_philo *)philo)->state,
		((t_philo *)philo)->fork
		);
}

static void	ft_lstiter(t_lst *lst, void (*f)(void *), unsigned int i)
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
	ft_lstiter(tmp, pphilo, game->rules.nb_philos);
	printf(CGRN"START!\n\n"CNO);
}
