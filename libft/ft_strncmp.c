/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:43:12 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/15 14:43:14 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (*(const unsigned char *)(s1
			+ i) == *(const unsigned char *)(s2 + i))
		&& *(const unsigned char *)(s1 + i) && *(const unsigned char *)(s2 + i))
	{
		i++;
	}
	return ((*(const unsigned char *)(s1 + i)
		-*(const unsigned char *)(s2 + i)));
}
