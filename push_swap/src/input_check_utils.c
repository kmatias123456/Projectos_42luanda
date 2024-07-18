/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:39:04 by kmatias           #+#    #+#             */
/*   Updated: 2024/06/26 23:39:06 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_digit:
*   Verifica se o caractere é um dígito.
*   Retorno: 1 se o caractere for um dígito, 0 se não for.
*/
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* is_sign:
*   Verifica se o caractere é um sinal numérico, + ou -.
*   Retorno: 1 se o caractere for um sinal, 0 se não for.
*/
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

/* nbstr_cmp:
*   Compara duas strings de dígitos para verificar se são iguais ou não.
*   Se uma das strings começar com um sinal '+', ele é ignorado e o resto
*   da string numérica é verificado.
*   Isso é para que +123 == 123, mas -123 != 123.
*   Retorno: 0 se as strings forem iguais, outro valor se não forem.
*/
int	nbstr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
