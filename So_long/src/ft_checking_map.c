/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:32:45 by aboumadi          #+#    #+#             */
/*   Updated: 2022/03/19 20:43:04 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_wall(t_all *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->l)
		{
			if (i == 0 || j == 0 || i == map->h - 1 || j == map->l - 1)
			{
				if (map->map[i][j] != '1')
					ft_error(2, map);
			}
			j++;
		}
		i++;
	}
}

void	check_itms(t_all *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				map->players++;
			if (map->map[i][j] == 'E')
				map->exits++;
			if (map->map[i][j] == 'C')
				map->itemse++;
			j++;
		}
		i++;
	}
	if (map->players < 1 || map->players > 1
		|| map->itemse < 1 || map->exits < 1)
		ft_error(3, map);
}

void	ft_check_extention(char *file)
{
	char	*check;

	if (ft_strlen2(file) == 0)
	{
		write(1, "invalid map\n", 12);
		exit(0);
	}
	check = ft_strchr(file, '.');
	if (!check || ft_strcmp(".ber", check))
	{
		write (1, "error in file name\n", 19);
		exit(0);
	}
}
