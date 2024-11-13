/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:17:05 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/13 10:17:06 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ((void) NULL);
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*int main()
{
    #include <fcntl.h> // added for O_WRONLY, O_CREAT, O_TRUNC
    char *str = "Hello, world!";
    int fd = open("output.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);

    ft_putendl_fd(str, fd);

    close(fd);

    return (0);
}*/
