/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:40:51 by shocquen          #+#    #+#             */
/*   Updated: 2022/03/01 17:39:13 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philonew(unsigned int index)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(*new));
	if (new)
	{
		memset(new, 0, sizeof(*new));
		new->index = index;
		new->state = PHI;
		gettimeofday(&new->birth, NULL);
	}
	return (new);
}

void	generate_philos(t_game **game)
{
	unsigned int	i;
	t_lst			*tmp;

	i = 0;
	while (++i <= (*game)->rules.nb_philos)
		ft_lstadd_back(&(*game)->philos, ft_lstnew(philonew(i)));
	tmp = (*game)->philos;
	while ((*game)->philos->next)
		(*game)->philos = (*game)->philos->next;
	(*game)->philos->next = tmp;
	(*game)->philos = (*game)->philos->next;
}
