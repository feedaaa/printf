/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:12:14 by ffidha            #+#    #+#             */
/*   Updated: 2023/12/11 15:24:46 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	int	len;  // Variable to store the total length of printed characters

	len = 0; // initialize variable to 0
	len += ft_printstr("0x"); // put 0x before the address starts
	if (ptr == 0) //if ptr is equal to null then put a 0
		len += ft_printstr("0");
	else
		len += ft_printhex((unsigned long long)ptr, 'x'); // If the pointer is not NULL, print its hexadecimal representation
	return (len);
	// Return the total length of printed characters
}
