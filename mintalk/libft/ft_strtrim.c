/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:52:36 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/17 11:52:40 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verify(char s1, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*snew;

	end = ft_strlen((char *)s1);
	start = 0;
	while (s1[start] && ft_verify(s1[start], (char *)set))
		start++;
	while (end > start && ft_verify(s1[end - 1], (char *)set))
		end--;
	snew = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (!snew)
		return (0);
	i = 0;
	while (start < end)
		snew[i++] = s1[start++];
	snew[i] = '\0';
	return (snew);
}
