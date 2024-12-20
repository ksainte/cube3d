/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:46:50 by ksainte           #+#    #+#             */
/*   Updated: 2024/12/17 02:21:21 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_str(char *test, char *buff, char *str)
{
	size_t	i;

	i = 0;
	while (test[i] != '\0' && test[i] != '\n')
		i++;
	if (test[i] == '\0')
		str = (char *)malloc(sizeof(char) * (i + 1));
	else if (test[i] == '\n' || i == 0)
		str = (char *)malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		return (NULL);
	str = ft_memcpy(str, test, i);
	if (test[i] == '\n')
	{
		str[i] = test[i];
		str[i + 1] = '\0';
		ft_memcpy(&buff[0], &test[i + 1], ft_strlen(test) - i - 1);
		ft_bzero(&buff[ft_strlen(test) - i - 1], BUFFER_SIZE
			- (ft_strlen(test) - i - 1));
	}
	else
		str[i] = '\0';
	free(test);
	return (str);
}

void	*ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_read_str(int fd, char *buff, char *test)
{
	int		nb_bytes_to_read;
	char	*str;
	char	*tmp;

	nb_bytes_to_read = -1;
	while (!ft_n_present(buff, '\n') && nb_bytes_to_read != 0)
	{
		nb_bytes_to_read = read(fd, buff, BUFFER_SIZE);
		if (nb_bytes_to_read == -1)
		{
			ft_bzero(buff, BUFFER_SIZE);
			free(test);
			return (NULL);
		}
		buff[nb_bytes_to_read] = '\0';
		if (nb_bytes_to_read != 0)
		{
			tmp = test;
			test = ft_strjoin(tmp, buff);
			free(tmp);
		}
	}
	str = "salut";
	return (get_str(test, buff, str));
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	char		*test;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	test = (char *)malloc(sizeof(char));
	if (test == NULL)
		return (NULL);
	*test = 0;
	if (*buff != 0)
	{
		tmp = test;
		test = ft_strjoin(tmp, buff);
		free(tmp);
	}
	line = ft_read_str(fd, buff, test);
	if (line == NULL)
		return (NULL);
	if (*line == '\0' && ft_free_str(line))
		return (NULL);
	return (line);
}
