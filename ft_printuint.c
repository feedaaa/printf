/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:08:34 by ffidha            #+#    #+#             */
/*   Updated: 2023/12/11 12:02:57 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuint(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
	{
		len += ft_printuint(nb / 10);
		len += ft_printuint(nb % 10);
	}
	else
		len += ft_printchar(nb + '0');
	return (len);
}
