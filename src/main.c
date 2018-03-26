/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:34:03 by yguzman           #+#    #+#             */
/*   Updated: 2018/01/07 22:14:39 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

void		free_tab(char **buff)
{
	int		i;

	i = 0;
	while (buff[i])
	{
		free(buff[i]);
		++i;
	}
	free(buff);
}

void		free_room(t_room *dm)
{
	t_room	*tmp;

	tmp = dm;
	while (tmp)
	{
		free(dm->name);
		tmp = dm->next;
		free(dm);
		dm = tmp;
	}
}

void		free_alldatamap(t_dm *dm)
{
	t_truc	*tmp;

	free_room(dm->room);
	tmp = dm->chemin;
	while (tmp)
	{
		free_room(dm->chemin->room);
		tmp = dm->chemin->next;
		free(dm->chemin);
		dm->chemin = tmp;
	}
}

void		free_alldata(t_tree *data)
{
	t_tree	*tmp;

	tmp = data;
	while (tmp)
	{
		free(data->name);
		free(data->branch);
		tmp = data->next;
		free(data);
		data = tmp;
	}
}

int			main(void)
{
	t_tree	*data;
	t_dm	data_map;

	data = NULL;
	init_data_map(&data_map);
	if (read_and_fill_lemin(&data, &data_map) == -1)
		return (-1);
	if (algo_lemdeux(&data, &data_map) == -1)
		return (-1);
	free_alldata(data);
	free_alldatamap(&data_map);
	return (0);
}
