/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:14:39 by aboumadi          #+#    #+#             */
/*   Updated: 2022/03/19 22:43:11 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(t_all *map)
{
	int	i;

	i = 0;
	if (map->map[i] == NULL)
		exit(0);
	while (i < map->h)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	ft_error(int w, t_all *map)
{
	if (w == 0)
		write (1, "error in allocation\n", 20);
	if (w == 1)
		write (1, "errore in read\n", 15);
	if (w == 2)
		write (1, "errore in struct\n", 16);
	if (w == 3)
		write (1, "errore in map\n", 15);
	if (w == 4)
		write (1, "errore in mlx\n", 15);
	if (w == 5)
	{
		write (1, "errore in argument\n", 19);
		exit(0);
	}
	if (map != NULL)
		ft_free(map);
	exit(0);
}
