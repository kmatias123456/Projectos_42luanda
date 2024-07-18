/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:38:07 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/14 07:38:10 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* VIRIFICA SE UM DETERMINADO CARACTER PERTENCE A CLASSE DOS IMPRIVEIS
*/
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
