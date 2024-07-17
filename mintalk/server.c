/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiangebeni <kiangebeni@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:29:40 by kiangebeni        #+#    #+#             */
/*   Updated: 2024/07/12 22:29:12 by kiangebeni       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Calcula o valor de nbr elevado a power_nbr
int	ft_recursive_power(int nbr, int power_nbr)
{
	if (power_nbr == 0)
		return (1);
	else if (power_nbr < 0)
		return (0);
	return (nbr * ft_recursive_power(nbr, power_nbr - 1));
}

// Concatena uma string *s1 com um caractere chr
char	*ft_strjoin_chr(const char *s1, const char chr)
{
	size_t	len_s1;
	char	*str_join;

	len_s1 = ft_strlen(s1);
	str_join = (char *)malloc(sizeof(char) * (len_s1 + 2));
	if (!str_join)
		return (NULL);
	ft_strlcpy(str_join, s1, len_s1 + 1);
	str_join[len_s1] = chr;
	str_join[len_s1 + 1] = '\0';
	free((void *)s1);
	return (str_join);
}

// recebe sequencias binarias em forma de sinais e as conver em uma string.
void	handler_signal(int signal_number)
{
	static int	count = 0;
	static int	result = 0;
	static char	*final = NULL;

	if (!final)
		final = ft_strdup("");
	if (signal_number == SIGUSR1)
		result = result + 0;
	else if (signal_number == SIGUSR2)
		result = result + (1 * ft_recursive_power(2, 7 - count));
	count++;
	if (count == 8)
	{
		final = ft_strjoin_chr(final, result);
		if (result == '\0')
		{
			ft_putstr_fd(final, 1);
			free(final);
			final = NULL;
		}
		count = 0;
		result = 0;
	}
}

// funcao principal.
int	main(void)
{
	struct sigaction	received_signal;

	ft_putstr_fd("Server's PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	received_signal.sa_handler = handler_signal;
	received_signal.sa_flags = 0;
	sigaction(SIGUSR1, &received_signal, NULL);
	sigaction(SIGUSR2, &received_signal, NULL);
	while (1)
		usleep(50);
}
