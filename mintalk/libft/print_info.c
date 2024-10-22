/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiangebeni <kiangebeni@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:16:52 by kmatias           #+#    #+#             */
/*   Updated: 2024/07/09 20:42:36 by kiangebeni       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_info(char *message)
{
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
}
