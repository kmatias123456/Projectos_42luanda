/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:02:10 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/27 16:02:15 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//funcao cria uma sub-string apartir de uma string passada como argumento.
//usando start como indice inicial e len com final.
char	*ft_substr(char *str, int start, int len)
{
	int		i;
	char	*sub;
	int		sum;

	i = 0;
	sum = len - start;
	if (sum == 0 || !str)
	{
		free(str);
		return (NULL);
	}
	sub = (char *)malloc(sizeof(char) * (sum + 1));
	if (!sub)
		return (NULL);
	while (str[start])
	{
		sub[i] = str[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	free(str);
	return (sub);
}

//funcao usada para liberar a memoria dinamicamente.
void	ft_free(char **str, char *buffer)
{
	free(buffer);
	free((*str));
	(*str) = NULL;
}

//funcao principal, imprimi uma de um arquivo.
char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	int			bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes != 0 && !(ft_strchr(str, '\n')))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			ft_free(&str, buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	buffer = ft_newline(str);
	str = ft_substr(str, str_len(buffer), str_len(str));
	return (buffer);
}
