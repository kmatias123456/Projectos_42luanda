/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:29:49 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/20 12:30:00 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	tamlist;
	int	i;

	i = 0;
	tamlist = ft_lstsize(lst);
	while (i < tamlist - 1)
	{
		i++;
		lst = lst->next;
	}
	return (lst);
}
