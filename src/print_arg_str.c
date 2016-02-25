/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:57:58 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/23 13:58:00 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_str(t_e *e, t_a *arg, int *i)
{
	if (arg->prec.pt && arg->prec.prec == 0)
		return ;
	if (arg->mod.l || arg->type == 'S')
		*i = print_str_wchar_t(va_arg(e->ap, wchar_t *), arg);
	else
		*i = print_str(va_arg(e->ap, char *), arg);
}
