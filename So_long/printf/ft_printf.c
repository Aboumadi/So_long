/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:26:21 by aboumadi          #+#    #+#             */
/*   Updated: 2022/03/19 20:16:42 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_2(char c, va_list argp, int *count)
{
	if (c == 'c')
		*count += ft_putchar(va_arg(argp, int));
	else if (c == 'd' || c == 'i')
		ft_putnbr_base10(va_arg(argp, int), count);
	else if (c == 'u')
		ft_putnbr_base10_ns2(va_arg(argp, int), count);
	if (c == '%')
		*count += ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	argp;

	count = 0;
	i = 0;
	va_start(argp, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			check_2(format[++i], argp, &count);
			i++;
		}
		else
		{
			write (1, &format[i], 1);
			i++;
			count++;
		}
	}
	va_end(argp);
	return (count);
}
