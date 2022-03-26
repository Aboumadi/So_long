/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base10_ns2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:18:54 by aboumadi          #+#    #+#             */
/*   Updated: 2022/03/19 18:33:20 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putnbr_base10_ns2(unsigned int n, int *j)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		*j += 1;
	}
	if (nb >= 0 && nb < 10)
	{
		ft_putchar(48 + nb);
		*j += 1;
	}
	else if (nb > 9)
	{
		ft_putnbr_base10_ns2((nb / 10), j);
		ft_putnbr_base10_ns2((nb % 10), j);
	}
}
