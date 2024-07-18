/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:02:34 by kmatias           #+#    #+#             */
/*   Updated: 2024/05/27 16:02:39 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//conta a quantidade de caracteres de uma string.
int	str_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

//retorna a string apartir da primeira ocorrencia de c.
char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = str_len((char *)s);
		return (&s[i]);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

//concatena str e buffer e armazena na new_str, usei na ft_strjoin.
char	*ft_join(char *new_str, char *str, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (buffer && buffer[j])
	{
		new_str[i + j] = buffer[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

//concatena str e buffer e armazena na new_str.
//usando alocacao dinamica, a ft_join.
char	*ft_strjoin(char *str, char *buffer)
{
	char	*new_str;

	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	new_str = (char *)malloc((1 + str_len(str)) + str_len(buffer)
			* sizeof(char));
	if (!new_str)
		return (NULL);
	new_str = ft_join(new_str, str, buffer);
	free(str);
	return (new_str);
}

//extrai uma substring desde o inicio
//ate encontrar o primeiro '\n'.
char	*ft_newline(char *str)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	while (j < i)
	{
		new_line[j] = str[j];
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}
