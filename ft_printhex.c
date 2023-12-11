/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:02:21 by ffidha            #+#    #+#             */
/*   Updated: 2023/12/11 15:21:38 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long long n, char format)
{
	int	len; // Variable to store the total length of printed characters

	len = 0; // initializing the variable to 0
	if (n >= 16) // If the number is greater than or equal to 16
	{
		len += ft_printhex((n / 16), format); // Recursively print the quotient
		len += ft_printhex((n % 16), format); // Recursively print the reminder
	}
	if (n >= 0 && n <= 9)  // Print the hexadecimal digit corresponding to the current remainder
		len += ft_printchar(n + '0'); // Print digit 0-9
	else if (n >= 10 && n <= 15)  // Print the hexadecimal letter A-F or a-f based on the format specifier
	{
		if (format == 'x')
			len += ft_printchar(n - 10 + 'a');
		else if (format == 'X')
			len += ft_printchar(n - 10 + 'A');
	}
	return (len);
	// Return the total length of printed characters
}

// int main()
// {
// 	unsigned long long	n;

// 	n = 344;
// 	printf("lowercase: \n");
// 	ft_printhex(n, 'x');
// 	printf("og: %llx\n", n);
// 	printf("uppercase: \n");
// 	ft_printhex(n, 'X');
// 	printf("og: %llX\n", n);
// }
