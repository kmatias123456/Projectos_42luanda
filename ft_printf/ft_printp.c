/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 02:00:07 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/28 02:15:37 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* converte um inteiro longo e sem sinal que representa um
* ponteiro para uma string hexadecimal e grava-o na saída
* padrão. Ele retorna o comprimento da string impressa.
*/
int	ft_printp(unsigned long long int nbr)
{
	int	length;

	length = 0;
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return ((length += 5));
	}
	else
	{
		write(1, "0x", 2);
		length += 2;
		length += ft_hexadecimal(nbr, "0123456789abcdef");
	}
	return (length);
}
