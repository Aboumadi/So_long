/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:12:02 by aboumadi          #+#    #+#             */
/*   Updated: 2022/03/19 19:04:14 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

char	*check(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (0);
	}
	tmp = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i++;
	while (str[i])
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

char	*print_line(char *str)
{
	int		i;
	char	*string;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	string = (char *)malloc((i + 2) * sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		string[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		string[i++] = '\n';
	string[i] = '\0';
	return (string);
}

char	*n_read(int fd, char *str, int bufer)
{
	int		r;
	char	*buff;

	buff = (char *)malloc((bufer + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buff, bufer);
		if (r == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[r] = '\0';
		str = ft_strjoin(str, buff);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	int			buffer;

	buffer = 1;
	if ((fd < 0) || (buffer <= 0))
		return (NULL);
	str = n_read(fd, str, buffer);
	if (!str)
		return (NULL);
	tmp = print_line(str);
	str = check(str);
	if (tmp[0] == '\0')
	{
		free(str);
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
