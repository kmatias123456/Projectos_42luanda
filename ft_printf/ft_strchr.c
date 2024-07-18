/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:45:53 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/28 01:59:55 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//retorna 1  se encontar a primeira ocorrencia do c, e 0 se nao.
int	ft_strchr(const char *str, int c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
		i++;
	while (i >= j)
	{
		if (str[j] == (char)c)
			return (1);
		j++;
	}
	return (0);
}
