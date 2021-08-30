/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:45:55 by estoffel          #+#    #+#             */
/*   Updated: 2021/08/07 20:21:45 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putc(char c)
{
	write(1, &c, 1);
}

void	flag_u(unsigned int n)
{
	if (n >= 0 && n <= 9)
		ft_putc('0' + n);
	else
	{
		flag_d(n / 10);
		flag_d(n % 10);
	}
}
