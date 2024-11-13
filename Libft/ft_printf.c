/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte19@student.s19>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:07:30 by ksainte           #+#    #+#             */
/*   Updated: 2024/04/03 23:14:35 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*You have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign*/

#include "libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	text_read(t_s *s, char str)
{
	s->len += ft_putchar(str);
	return (s->len);
}

int	arg_search(va_list arg, char str, t_s *s)
{
	if (str == 'd' || str == 'i')
		s->len += ft_len_print_nbr(va_arg(arg, int));
	else if (str == 's')
		s->len += ft_write_str(va_arg(arg, char *));
	else if (str == 'x' || str == 'X')
		s->len += ft_hexadecimal(va_arg(arg, unsigned int), str);
	else if (str == 'c')
		s->len += ft_putchar(va_arg(arg, int));
	else if (str == 'p')
		s->len += handle_ptr(va_arg(arg, unsigned long), 0);
	else if (str == 'u')
		s->len += ft_putnbr_u(va_arg(arg, unsigned int));
	else if (str == '%')
		s->len += write(1, "%", 1);
	return (s->len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	t_s		s;

	va_start(arg, str);
	s.len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			arg_search(arg, *(str + 1), &s);
			str++;
		}
		else
			text_read(&s, *(str));
		if (!str)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (6);
		}
		str++;
	}
	va_end(arg);
	return (s.len);
}
