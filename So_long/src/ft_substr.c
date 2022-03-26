/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 01:21:20 by aboumadi          #+#    #+#             */
/*   Updated: 2022/03/19 20:49:36 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_substr(char *src, int s, size_t len)
{
	unsigned int	i;
	char			*dst;
	unsigned int	j;

	i = 0;
	if (!src)
		return (NULL);
	j = 0;
	while (i < len && src[i++] != '\0')
		j++;
	dst = malloc((j + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len && (s <= ft_strlen(src)) && (src[i + s] != '\0'))
	{
		dst[i] = src[i + s];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
