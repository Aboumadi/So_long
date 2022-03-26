/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:43:20 by aboumadi          #+#    #+#             */
/*   Updated: 2022/03/19 22:19:44 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_intialise(t_all *map)
{
	map->h = 0;
	map->l = 0;
	map->itemse = 0;
	map->exits = 0;
	map->players = 0;
	map->map = NULL;
	map->count_mouv = 0;
	map->x = 0;
	map->y = 0;
}

char	*get_line(int fd, char	**line)
{
	*line = get_next_line(fd);
	return (*line);
}

void	count_line(t_all *count, char *file)
{
	char	*line;
	int		fd;
	int		i;
	int		larg;

	i = 0;
	larg = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(1, NULL);
	while (get_line(fd, &line))
	{
		if (larg == 0)
			larg = ft_strlen2(line);
		if (larg != ft_strlen2(line))
		{
			write(1, "it's not a rectangle\n", 21);
			exit (0);
		}
		free(line);
		i++;
	}
	count->h = i;
	count->l = larg;
	close(fd);
}

void	ft_read_map(int fd, t_all *count, char *file)
{
	char	*line;
	int		i;
	int		j;

	count_line(count, file);
	i = 0;
	j = count->l;
	count->map = (char **)malloc((count->h + 1) * sizeof(char *));
	if (!count->map)
		ft_error(0, count);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(1, count);
	i = 0;
	while (get_line(fd, &line))
		count->map[i++] = line;
	i = 0;
	while (i < count->h - 1)
	{
		count->map[i][ft_strlen2(count->map[i])] = '\0';
		i++;
	}
	free(line);
	close(fd);
}
