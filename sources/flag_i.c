/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:46:16 by estoffel          #+#    #+#             */
/*   Updated: 2021/08/07 18:00:19 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putc(char c)
{
	write(1, &c, 1);
}

void	flag_i(int n)
{
	if (n >= 0 && n <= 9)
		ft_putc('0' + n);
	else if (n < 0)
	{
		ft_putc('-');
		flag_i(-n);
	}
}
