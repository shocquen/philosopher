/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:29:57 by shocquen          #+#    #+#             */
/*   Updated: 2022/03/05 11:03:33 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	ft_atoi(const char *str)
{
	unsigned int	nb;

	while (*str && ((*str >= '\t' && *str <= '\r') || (*str == ' ')))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	nb = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb);
}

void	ft_usleep(unsigned int time)
{
	t_time	now;
	t_time	comp;

	gettimeofday(&now, NULL);
	gettimeofday(&comp, NULL);
	while (now.tv_usec - comp.tv_usec < time)
	{
		gettimeofday(&comp, NULL);
		usleep(50);
		printf("test: %d\n", now.tv_usec - comp.tv_usec < time);
	}
}
