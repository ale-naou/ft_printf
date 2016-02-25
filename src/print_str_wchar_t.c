/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_wchar_t.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:06:54 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/23 14:06:56 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	wchar_t_str_len(const wchar_t *s)
{
	int	len;

	len = 0;
	while (*s != '\0')
		len += nbr_binary(*s++);
	return (len);
}

static int	wstr_len(const wchar_t *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int			print_str_wchar_t(const wchar_t *s, t_a *arg)
{
	int	len_unicode;
	int	len;
	int	i;

	i = arg->prec.prec > wstr_len(s) ? wstr_len(s) : arg->prec.prec;
	len = wchar_t_str_len(s);
	if (arg->prec.pt == 1 && arg->prec.prec == 0)
		return (arg->width);
	arg->prec.prec = (arg->prec.prec == 0 || arg->prec.prec > len ? len :
			arg->prec.prec);
	len_unicode = arg->prec.prec - (arg->prec.prec % nbr_binary(s[i - 1]));
	len = arg->width > arg->prec.prec ? arg->width : len_unicode;
	arg->prec.pt == 0 ? len = wchar_t_str_len(s) : 0;
	arg->width -= len_unicode;
	while (!arg->flag.mn && arg->width-- > 0)
		arg->flag.zr ? write(1, "0", 1) : write(1, " ", 1);
	while (*s != 0 && arg->prec.prec > 1)
	{
		print_wchar_t(*s);
		arg->prec.prec -= nbr_binary(*s);
		s++;
	}
	while (arg->flag.mn && arg->width-- > 0)
		arg->flag.zr ? write(1, "0", 1) : write(1, " ", 1);
	return (len);
}