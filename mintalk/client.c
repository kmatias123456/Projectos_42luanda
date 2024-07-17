/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiangebeni <kiangebeni@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:23:53 by kiangebeni        #+#    #+#             */
/*   Updated: 2024/07/12 22:28:04 by kiangebeni       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* 
* converte a string em uma sequencia binaria
* e a enviar como sinal para servidor.
*/
void	signal_send(int pid, char *info)
{
	int	chr;
	int	count;

	chr = -1;
	while (info[++chr])
	{
		count = -1;
		while (++count < 8)
		{
			if (((unsigned char)(info[chr] >> (7 - count)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(info[chr] >> (7 - count)) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(50);
		}
	}
	count = -1;
	while (++count < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
	}
}

// Funcao principal.
int	main(int ac, char *av[])
{
	int		id_server;
	char	*info;

	if (ac == 3)
	{
		id_server = ft_atoi(av[1]);
		if (!id_server)
		{
			print_info("Error. Argumento invalido!");
			return (0);
		}
		info = av[2];
		if (info[0] == '\0')
		{
			print_info("Upps!tens que escrever alguma mensagem: ex.:abc");
			return (0);
		}
		signal_send(id_server, info);
	}
	else
		print_info("E necessario o PID do servico e a Mensagem!");
	return (0);
}
