/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:09:08 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/23 14:09:10 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	nbr_len_base(long n, const int base)
{
	int	len;

	len = 1;
	if (n == 0)
		return (len);
	if (n < 0)
	{
		n *= -1;
		base == 10 ? len += 1 : 0;
	}
	while ((n /= base) > 0)
		len++;
	return (len);
}
