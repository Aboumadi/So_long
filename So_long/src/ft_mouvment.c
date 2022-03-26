/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouvment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:20:48 by aboumadi          #+#    #+#             */
/*   Updated: 2022/03/19 20:46:41 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_items(t_all *map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->l)
		{
			if (map->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	find_player(t_all *map)
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
			{
				map->x = i;
				map->y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_mouv(t_all *map, int i, int j)
{
	if (map->map[i][j] == '1')
		return ;
	if (map->map[i][j] == 'E' && !count_items(map, 'C'))
	{
		mlx_clear_window(map->mlx, map->mlx_win);
		mlx_destroy_window(map->mlx, map->mlx_win);
		ft_free(map);
		ft_printf("succes\n");
		exit(0);
	}
	else if (map->map[i][j] == 'E' && count_items(map, 'C'))
		put_image(map);
	else
	{
		map->map[map->x][map->y] = '0';
		map->x = i;
		map->y = j;
		map->map[i][j] = 'P';
		ft_printf("%d\n", map->count_mouv);
		map->count_mouv++;
	}
	put_image(map);
}

int	key_board(int key, t_all *map)
{	
	if (key == 53)
	{
		mlx_clear_window(map->mlx, map->mlx_win);
		mlx_destroy_window(map->mlx, map->mlx_win);
		ft_free(map);
		exit(0);
	}
	if (key == 13)
		ft_mouv(map, map->x - 1, map->y);
	if (key == 2)
		ft_mouv(map, map->x, map->y + 1);
	if (key == 1)
		ft_mouv(map, map->x + 1, map->y);
	if (key == 0)
		ft_mouv(map, map->x, map->y - 1);
	return (0);
}
