/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 03:00:53 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/28 03:23:56 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* converte recursivamente um número em uma string hexadecimal
* usando a base fornecida e grava-o na saída padrão.
* E retorna o comprimento da string hexadecimal.
*/
int	ft_hexadecimal(unsigned long long int nbr, char *base)
{
	int	length;

	length = 0;
	if (nbr >= 16)
	{
		length += ft_hexadecimal((nbr / 16), base);
		length += ft_hexadecimal((nbr % 16), base);
	}
	else
	{
		write(1, &base[nbr], 1);
		length++;
	}
	return (length);
}
