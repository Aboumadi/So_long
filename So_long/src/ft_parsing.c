/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:24:32 by aboumadi          #+#    #+#             */
/*   Updated: 2022/03/19 22:45:34 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_parsing(char **av, t_all *map2)
{
	int	fd;

	ft_intialise(map2);
	ft_check_extention(av[1]);
	count_line(map2, av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error(1, NULL);
	ft_read_map(fd, map2, av[1]);
	check_itms(map2);
	check_wall(map2);
}
