/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 03:15:21 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/28 03:27:24 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//funcao que faz a verificao do formato;
//Para saber qual funcao usar para imprimir.
int	ft_printc(const char *format, int i, int length, va_list list)
{
	if (format[i + 1] == 's')
		return (length += ft_putstr(va_arg(list, char *)));
	else if (format[i + 1] == 'c')
		return ((length += ft_putchar(va_arg(list, int))));
	else if (format[i + 1] == 'i' || format[i + 1] == 'd')
		return ((length += ft_putnbr(va_arg(list, int))));
	else if (format[i + 1] == 'p')
		return ((length += ft_printp(va_arg(list, unsigned long long int))));
	else if (format[i + 1] == 'u')
		return ((length += ft_unsigned(va_arg(list, unsigned int))));
	else if (format[i + 1] == 'x')
		return ((length += ft_hexadecimal(va_arg(list, unsigned int),
					"0123456789abcdef")));
	else if (format[i + 1] == 'X')
		return ((length += ft_hexadecimal(va_arg(list, unsigned int),
					"0123456789ABCDEF")));
	else if (format[i + 1] == '%')
		return ((length += ft_putchar('%')));
	return (length);
}
