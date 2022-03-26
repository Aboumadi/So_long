/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base10.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:19:19 by aboumadi          #+#    #+#             */
/*   Updated: 2022/03/19 18:33:17 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putnbr_base10(int n, int *j)
{
	long int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
		*j += 1;
	}
	if (nb >= 0 && nb < 10)
	{
		ft_putchar(48 + nb);
		*j += 1;
	}
	else if (nb > 9)
	{
		ft_putnbr_base10((nb / 10), j);
		ft_putnbr_base10((nb % 10), j);
	}
}
