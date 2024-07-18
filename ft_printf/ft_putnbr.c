/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:10:14 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/28 01:25:16 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//converte numero negativo para positivo e imprime '-'.
static int	ft_isnegative(int n)
{
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	return (n);
}

//conta numero de digitos que componhem um numero.
static int	ft_countwordls(int n)
{
	int	wordls;

	wordls = 0;
	if (n < 0)
	{
		wordls++;
		n *= -1;
	}
	if (n == 0)
		wordls++;
	while (n != 0)
	{
		n = n / 10;
		wordls++;
	}
	return (wordls);
}

/*
* verifica se o n e igual ao minimo int possivel
* imprime o -2147483648 1 se for e 0 se nao.
*/
static int	ft_minint(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	return (0);
}

int	ft_putnbr(int n)
{
	int	i;
	int	worlds;

	worlds = 0;
	i = 0;
	worlds = ft_countwordls(n);
	if (ft_minint(n))
		return (11);
	n = ft_isnegative(n);
	if (n > 9)
	{
		i = i + (n % 10);
		ft_putnbr(n / 10);
		i = i + '0';
		write(1, &i, 1);
		return (worlds);
	}
	else
	{
		n += '0';
		write(1, &n, 1);
	}
	return (worlds);
}
