/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:10:07 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/23 14:13:10 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_arg_ptr(t_e *e, t_a *arg, int *i)
{
	*i = print_mem(va_arg(e->ap, void *), arg);
}
