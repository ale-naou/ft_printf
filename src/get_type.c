/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:54:23 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/23 13:54:26 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_type(const char *format, int i, t_a *arg)
{
	if (is_type(format[i]))
	{
		arg->type = format[i];
		return (i + 1);
	}
	return (i);
}
