/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:46:09 by estoffel          #+#    #+#             */
/*   Updated: 2021/08/03 19:40:39 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putc(char c)
{
	write(1, &c, 1);
}

void	flag_d(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n >= 0 && n <= 9)
		ft_putc('0' + n);
	else if (n < 0)
	{
		ft_putc('-');
		flag_d(-n);
	}
	else
	{
		flag_d(n / 10);
		flag_d(n % 10);
	}
}
