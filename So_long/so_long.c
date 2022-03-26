/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:49:54 by aboumadi          #+#    #+#             */
/*   Updated: 2022/03/19 22:46:58 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	*file_to_image(char *file, t_all *mlx)
{
	void	*img;
	int		width;
	int		height;

	width = 0;
	height = 0;
	img = mlx_xpm_file_to_image(mlx->mlx, file, &width, &height);
	if (width == 0 || height == 0)
	{
		mlx_clear_window(mlx->mlx, mlx->mlx_win);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		ft_free(mlx);
		write (1, "error\n", 6);
		exit(0);
	}
	return (img);
}

void	get_image(t_all *mlx)
{
	mlx->wall = file_to_image("images/wall.xpm", mlx);
	mlx->hero = file_to_image("images/hero.xpm", mlx);
	mlx->collect = file_to_image("images/collect.xpm", mlx);
	mlx->exit = file_to_image("images/exit.xpm", mlx);
	mlx->floor = file_to_image("images/floor.xpm", mlx);
	if (!mlx->wall || !mlx->hero || !mlx->collect || !mlx->exit
		|| !mlx->floor)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		ft_error(4, mlx);
		exit(0);
	}
}

void	ft_put_image_window(t_all *map, void *img_ptr, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img_ptr, j * 64, i * 64);
}

void	put_image(t_all *map)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(map->mlx, map->mlx_win);
	while (i < map->h)
	{
		j = 0;
		while (j < map->l)
		{
			if (map->map[i][j] == '1')
				ft_put_image_window(map, map->wall, i, j);
			if (map->map[i][j] == '0')
				ft_put_image_window(map, map->floor, i, j);
			if (map->map[i][j] == 'P')
				ft_put_image_window(map, map->hero, i, j);
			if (map->map[i][j] == 'E')
				ft_put_image_window(map, map->exit, i, j);
			if (map->map[i][j] == 'C')
				ft_put_image_window(map, map->collect, i, j);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_all	map;

	if (ac != 2)
		ft_error(5, NULL);
	map.mlx = mlx_init();
	if (!map.mlx)
	{
		ft_error(4, NULL);
		exit(0);
	}
	ft_parsing(av, &map);
	map.mlx_win = mlx_new_window(map.mlx, map.l * 64, map.h * 64, "so_long");
	if (!map.mlx_win)
	{
		ft_error(4, &map);
		exit(0);
	}
	get_image(&map);
	put_image(&map);
	find_player(&map);
	mlx_hook(map.mlx_win, 17, 0, destroy_window, &map);
	mlx_key_hook(map.mlx_win, key_board, &map);
	mlx_loop(map.mlx);
}
