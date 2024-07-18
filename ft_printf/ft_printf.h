/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 02:10:49 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/28 02:33:52 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/*****************************************************************************/
/*                                                                           */
/*                           FUNCOES USADAS!.                                */
/*                                                                           */
/*****************************************************************************/
int	ft_printf(const char *format, ...);
int	ft_printc(const char *format, int i, int length, va_list list);
int	ft_strchr(const char *str, int c);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_strlen(char *str);
int	ft_hexadecimal(unsigned long long int nbr, char *base);
int	ft_printp(unsigned long long int nbr);
int	ft_unsigned(unsigned int n);

#endif
