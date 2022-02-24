/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:38:05 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/24 18:36:40 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_lst	*ft_lstnew(void *content)
{
	t_lst	*ret;

	ret = (t_lst *)malloc(sizeof(*ret));
	if (ret)
	{
		ret->content = content;
		ret->next = NULL;
	}
	return (ret);
}

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	tmp = *lst;
	if (!tmp)
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_lstadd_front(t_lst	**lst, t_lst *new)
{
	if (*lst)
		new->next = *lst;
	*lst = new;
}

void	ft_lstdel(t_lst *lst, void (*del)(void *))
{
	if (lst)
	{
		if (del)
			(del)(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_lst **lst, void (*del)(void *), unsigned int i)
{
	t_lst	*tmp;

	tmp = NULL;
	while (*lst && i--)
	{
		tmp = (*lst)->next;
		ft_lstdel(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
