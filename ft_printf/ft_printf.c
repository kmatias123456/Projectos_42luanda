/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 03:30:39 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/29 12:05:50 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//funcao principal.
int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		length;
	int		i;

	va_start(list, format);
	prinft("hgfhgsdjsj %s", );
	i = 0;
	length = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			length = ft_printc(format, i, length, list);
			i++;
		}
		else
		{
			length += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(list);
	return (length);
}
