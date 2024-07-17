/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:31:34 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/14 07:31:37 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* VIRIFICA SE UM DETERMINADO CARACTER PERTENCE A CLASSE DOS DIGITOS
*/
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
