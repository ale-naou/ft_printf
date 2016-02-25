/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:56:58 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/23 13:57:00 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_char(t_e *e, t_a *arg, int *i)
{
	wchar_t	c;

	if (arg->mod.l || arg->type == 'C')
	{
		c = va_arg(e->ap, wchar_t);
		arg->width -= nbr_binary(c);
	}
	else
		arg->width--;
	while (!arg->flag.mn && arg->width-- > 0)
	{
		write(1, " ", 1);
		e->plen++;
	}
	if (arg->mod.l || arg->type == 'C')
		*i = print_wchar_t(c);
	else
		*i = print_char(va_arg(e->ap, int));
	while (arg->flag.mn && arg->width-- > 0)
	{
		write(1, " ", 1);
		e->plen++;
	}
}
