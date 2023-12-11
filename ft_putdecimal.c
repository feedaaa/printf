/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:11:32 by ffidha            #+#    #+#             */
/*   Updated: 2023/12/11 16:11:02 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdecimal(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_printchar('-');
		len += ft_printchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		len += ft_printchar('-');
		n = n * -1;
	}
	if (n > 9)
	{
		len += ft_putdecimal(n / 10);
		len += ft_putdecimal(n % 10);
	}
	if (n >= 0 && n <= 9)
		len += ft_printchar(n + '0');
	return (len);
}
// int main()
// {
// 	ft_putdecimal(-2147483648);
// 	ft_putdecimal(2147483647);
// 	printf("%d\n", INT_MAX);
// 	printf("%d\n", INT_MIN);
// }