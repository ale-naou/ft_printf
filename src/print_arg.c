/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:56:52 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/04 14:57:01 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_arg(t_e *e, t_a *arg)
{
	int		i;

	i = 0;
	if (arg->type == '%' || arg->type == 'R' || arg->type == 'Z')
		print_arg_percent(e, arg, &i);
	else if (arg->type == 'd' || arg->type == 'i' || arg->type == 'D')
		print_arg_int(e, arg, &i);
	else if (arg->type == 'c' || arg->type == 'C')
		print_arg_char(e, arg, &i);
	else if (arg->type == 's' || arg->type == 'S')
		print_arg_str(e, arg, &i);
	else if (arg->type == 'u' || arg->type == 'U')
		print_arg_unsigned(e, arg, &i);
	else if (arg->type == 'x' || arg->type == 'X')
		print_arg_base(e, arg, &i);
	else if (arg->type == 'o' || arg->type == 'O')
		print_arg_base(e, arg, &i);
	else if (arg->type == 'p')
		print_arg_ptr(e, arg, &i);
	return (i);
}
