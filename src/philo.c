/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:40:51 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/24 18:31:27 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philonew(unsigned int index)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(*new));
	if (new)
	{
		new->index = index;
		new->fork = 0;
		new->state = PHI;
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
