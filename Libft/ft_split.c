/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:14:43 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/13 10:14:45 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	separator(const char str, char c)
{
	if (c == str)
		return (1);
	return (0);
}

static int	count_words(const char *str, char c)
{
	int	count;

	if (!str)
		return (-1);
	count = 0;
	while (*str)
	{
		while (*str && separator(*str, c))
			str++;
		if (*str && !separator(*str, c))
			count++;
		while (*str && !separator(*str, c))
			str++;
	}
	return (count);
}

static char	**ft_free_arr(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	*ft_copy(const char *src, int n)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count;
	int		i;
	int		j;

	count = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (split == NULL)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		while (*s && separator(*s, c))
			s++;
		j = 0;
		while (s[j] && !separator(s[j], c))
			j++;
		split[i] = ft_copy(s, j);
		if (split[i] == NULL)
			return (ft_free_arr(split));
		s += j;
	}
	split[i] = 0;
	return (split);
}
/*int main(int argc,char *argv[])
{
	char **split;
	char c = 'l';
	int i;
	//char *str = NULL;

	str = argv[1];
	//c = argv[2];

	split = ft_split(str,c);
	i = 0;
	while (split[i])
	{
		printf("%s\n",split[i]);
		i++;
	}
	return (0);
}*/