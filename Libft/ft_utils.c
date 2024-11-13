/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte19@student.s19>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:47:43 by ksainte           #+#    #+#             */
/*   Updated: 2024/04/03 22:07:28 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(str, 1);
	while (str[i])
		i++;
	return (i);
}

int	ft_len_print_nbr(int nbr)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(nbr);
	len = ft_write_str(str);
	free(str);
	return (len);
}

int	handle_ptr(unsigned long ptr, int c)
{
	int		len;
	char	*hex;

	hex = "0123456789abcdef";
	len = 0;
	if (!c)
	{
		len += write(1, "0x", 2);
		c++;
	}
	if (ptr > 15)
		len += handle_ptr(ptr / 16, c);
	len += ft_putchar(hex[ptr % 16]);
	return (len);
}

char	ft_hexadecimal(long int n, char c)
{
	char	*hex;
	int		len;

	len = 0;
	hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n > 15)
		len += ft_hexadecimal(n / 16, c);
	len += ft_putchar(hex[n % 16]);
	return (len);
}

int	ft_putnbr_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 9)
		len += ft_putchar(n + '0');
	else
	{
		len += ft_putnbr_u(n / 10);
		len += ft_putnbr_u(n % 10);
	}
	return (len);
}
