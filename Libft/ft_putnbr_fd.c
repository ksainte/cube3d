/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:17:24 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/13 10:17:25 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln <= 9)
		ft_putchar_fd(ln + '0', fd);
	else
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putnbr_fd(ln % 10, fd);
	}
}
/*int main()
{
    #include <fcntl.h> // added for O_WRONLY, O_CREAT, O_TRUNC
    int fd = open("output.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);

    ft_putnbr_fd(-0, fd);
    //-2147483648

    close(fd);

    return (0);
}*/
