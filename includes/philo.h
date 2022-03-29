/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:33:40 by shocquen          #+#    #+#             */
/*   Updated: 2022/03/11 10:19:46 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/* Colors */
# define CRED "\033[0;31m"
# define CGRN "\033[0;32m"
# define CYLW "\033[0;33m"
# define CNO "\033[0;39m"

/* States of a philo */
# define DEAD 0
# define EAT 1
# define SLEEP 2
# define PHI 3

typedef struct timeval	t_time;
/* List */
typedef struct s_lst
{
	void			*content;
	struct s_lst	*next;
}	t_lst;

t_lst			*ft_lstnew(void *content);
void			ft_lstadd_back(t_lst **lst, t_lst *new);
void			ft_lstadd_front(t_lst	**lst, t_lst *new);
void			ft_lstdel(t_lst *lst, void (*del)(void *));
void			ft_lstclear(t_lst **lst, void (*del)(void *), unsigned int i);

/* Game */
typedef struct s_rules
{
	unsigned int	nb_philos;
	unsigned int	tm_die;
	unsigned int	tm_eat;
	unsigned int	tm_sleep;
	unsigned int	limit;
}	t_rules;

typedef struct s_game
{
	t_rules	rules;
	t_lst	*philos;
	t_time	start;
}	t_game;

t_rules			init_rules(char **argv);
t_game			*init_game(void);

/* Philo */
typedef struct s_philo
{
	unsigned int	index;
	int				state;
	int				fork;
	pthread_t		th;
	t_time			birth;
}	t_philo;

t_philo			*philonew(unsigned int index);
void			generate_philos(t_game **game);

/* Check_args */
int				check_args(int argc, char **argv);

/* Utils */
unsigned int	ft_atoi(const char *str);

/* Launch */
void			launch_game(t_game *game);

/* TEST */
void			pgame(t_game *game);
void			*pphilo(void *philo);
float			time_diff(struct timeval *start, struct timeval *end);
float			show_time(struct timeval *start);

#endif