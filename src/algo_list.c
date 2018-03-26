/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:05:00 by jcoutare          #+#    #+#             */
/*   Updated: 2018/01/07 22:06:27 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

t_room		*lemin_new(char *name)
{
	t_room	*new;

	if (!(new = malloc(sizeof(t_room))))
		return (NULL);
	if (!(new->name = ft_strdup(name)))
		return (NULL);
	new->fourmi = 0;
	new->next = NULL;
	return (new);
}

int			l_push_back(t_room **begin_list, char *name)
{
	t_room	*list;

	if (*begin_list == NULL)
	{
		if (!(*begin_list = lemin_new(name)))
			return (-1);
	}
	else
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		if (!(list->next = lemin_new(name)))
			return (-1);
	}
	return (1);
}

void		ntm(t_dm *data_map, t_tree *data)
{
	data->validroom = 0;
	lst_remove_last(&data_map->room);
}

void		lst_remove_last(t_room **begin_list)
{
	t_room	*list;

	list = *begin_list;
	if (list == NULL || list->next == NULL)
	{
		list = NULL;
		return ;
	}
	while (list->next->next)
		list = list->next;
	free(list->next->name);
	free(list->next);
	list->next = NULL;
}
