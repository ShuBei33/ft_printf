/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:07:04 by estoffel          #+#    #+#             */
/*   Updated: 2021/09/07 19:17:31 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putc_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	put_unbr_fd(unsigned int n, int fd)
{
	if (n >= 0 && n <= 9)
		ft_putc_fd('0' + n, fd);
	else
	{
		put_unbr_fd(n / 10, fd);
		put_unbr_fd(n % 10, fd);
	}
}

static int	nb_len(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		++len;
		nb = (-1) * nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		++len;
	}
	return (len);
}

int	conv_u(va_list *args)
{
	int	i;

	i = va_arg(*args, unsigned int);
	put_unbr_fd(i, 1);
	return (nb_len(i));
}
