/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:28:26 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/14 07:28:29 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* VIRIFICA SE UM DETERMINADO CARACTER PERTENCE A TABELA ASCII
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
