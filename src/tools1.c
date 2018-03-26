/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 22:09:13 by yguzman           #+#    #+#             */
/*   Updated: 2018/01/07 22:19:44 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include <stdlib.h>

int				ntm2(t_dm *data_map, int *ant, t_truc *chemin)
{
	t_room		*room;

	room = chemin->room;
	if (*ant <= data_map->nb_ant)
		room->fourmi = (*ant)++;
	if (lance(room, data_map) == -1)
		return (-1);
	return (0);
}

void			init_data_map(t_dm *dm)
{
	dm->nb_ant = -1;
	dm->name_room = NULL;
	dm->start = NULL;
	dm->end = NULL;
	dm->lien = NULL;
}

int				strcmp_trim2(char *s1, char *s2)
{
	char		**s11;
	char		**buf;
	int			ret;

	if ((s11 = ft_strsplit(s1, " ")) == NULL)
		return (-1);
	if ((buf = ft_strsplit(s2, "-")) == NULL)
		return (-1);
	ret = ft_strcmp(s11[0], buf[1]);
	free(s11[0]);
	free(s11);
	free(buf[0]);
	free(buf);
	return (ret);
}

int				strcmp_trim1(char *s1, char *s2)
{
	char		**s11;
	char		**buf;
	int			ret;

	if ((s11 = ft_strsplit(s1, " ")) == NULL)
		return (-1);
	if ((buf = ft_strsplit(s2, "-")) == NULL)
		return (-1);
	ret = ft_strcmp(s11[0], buf[0]);
	free(s11[0]);
	free(s11);
	free(buf[0]);
	free(buf);
	return (ret);
}

void			ntm1(t_dm *data_map, char **file, int lol, int *i)
{
	if (lol == 1)
		data_map->end = file[*i];
	else if (lol == 2)
		data_map->start = file[*i];
	free(file[*i - 1]);
}
