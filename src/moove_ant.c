/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:16:41 by jcoutare          #+#    #+#             */
/*   Updated: 2018/01/07 22:19:19 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int				lem_in_print(t_room *room)
{
	char		**lol;

	ft_putstr("L");
	ft_putnbr(room->fourmi);
	ft_putstr("-");
	if ((lol = ft_strsplit(room->next->name, " ")) == NULL)
		return (-1);
	ft_putstr(lol[0]);
	ft_putchar(' ');
	free(lol[0]);
	free(lol);
	return (0);
}

int				lance(t_room *room, t_dm *data_map)
{
	if (room->next)
		lance(room->next, data_map);
	if (room->fourmi != 0 && room->next != NULL)
	{
		if (lem_in_print(room) == -1)
			return (-1);
		room->next->fourmi = room->fourmi;
		room->fourmi = 0;
		return (1);
	}
	return (0);
}

int				nb_coup_total(t_dm *data_map, int *lol, int *xd)
{
	int			value;
	int			i;
	int			j;

	i = 0;
	j = 0;
	value = xd[i];
	while (i < ft_list_size_t(data_map->chemin))
	{
		if (xd[i] > value)
		{
			value = xd[i];
			j = i;
		}
		i++;
	}
	return (value + lol[j] - 1);
}

int				launch_the_nukes(t_dm *data_map, int *xd, int *lol, int i)
{
	t_truc		*chemin;
	int			round;
	int			ant;

	ant = 1;
	round = nb_coup_total(data_map, lol, xd);
	ft_putchar('\n');
	while (round--)
	{
		chemin = data_map->chemin;
		i = 0;
		while (chemin)
		{
			if (xd[i] > 0)
				if (ntm2(data_map, &ant, chemin) == -1)
					return (-1);
			i++;
			chemin = chemin->next;
		}
		ft_putchar('\n');
	}
	return (0);
}
