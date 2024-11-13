/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:14:03 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/13 10:14:05 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_append(char *dest, char const *src)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (dest[i])
		i++;
	len = i;
	i = 0;
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s2;
	size_t	len_s1;
	char	*ms;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ms = (char *)malloc(sizeof(*ms) * (len_s1 + len_s2 + 1));
	if (ms == NULL)
	{
		return (NULL);
	}
	*ms = 0;
	ms = ft_append(ms, s1);
	ms = ft_append(ms, s2);
	return (ms);
}
/*int main()
{
        char *s1;
        char *s2;
        char *tot;
        
        s1 = NULL;
        s2 = "toi";

        tot = ft_strjoin(s1,s2);
        printf("%s",tot);
        return (0); 
}*/
/*int main(int argc, char *argv[])
{
        char *s1;
        char *s2;
        char *tot;
        
        s1 = argv[1];
        s2 = argv[2];

        tot = ft_strjoin(s1,s2);
        printf("%s",tot);
        return (0);
}*/