/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:25:00 by ffidha            #+#    #+#             */
/*   Updated: 2023/12/11 16:08:45 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//variadic functions --> function that can except alot of arguments like the number of arguments can vary.
// one example of using variadic functions is printf.

#include "ft_printf.h"

// checkformat is a function that we are going to use to check for format specifiers.
int checkformat(va_list lst, char format)
{
	int len; // variable to store the total lenght of the printed characters.
	
	len = 0; // initializing it to 0.
    if (format == 'c')
        len += ft_printchar(va_arg(lst, int));
// checks for format c and prints a character.
    else if (format == 's')
        len += ft_printstr(va_arg(lst, char *));
// checks for format s and prints a string.
    else if (format == 'd' || format == 'i')
        len += ft_putdecimal(va_arg(lst, int));
// checks for format i or d and prints the decimal or integer.
    else if (format == 'x' || format == 'X')
        len += ft_printhex(va_arg(lst, unsigned int), format);
// checks for format x or X and prints a hexadecimal lowercase or hexadecimal uppercase.
    else if (format == '%')
        len += ft_printchar('%');
// checks for format % and prints a percentage sign.
    else if (format == 'p')
        len += ft_printptr(va_arg(lst, void *));
// checks for format p and prints pointer address.
    else if (format == 'u')
        len += ft_printuint(va_arg(lst, unsigned int));
// checks for format u and prints the unsigned integer or decimal.
    return (len);
// returns the total length of the printed characters.
}

int ft_printf(const char *format, ...)
{
    va_list lst; //takes a list of arguments.
    int i; // variable for iteration
    int char_print; // variable to count the total characters printed

    va_start(lst, format); //initializes the list, starting after the 'format' parameter so basically whatever ... is
    char_print = 0; // initializing character print count to 0
    i = 0; // initializing iterator to 0

    while (format[i]) //iterate through the format string
    {
        if (format[i] == '%') // Check for the '%' character indicating a format specifier
        {
            i++; // Move to the next character after '%'
            char_print += checkformat(lst, format[i]); // Calls checkformat to handle the format specifier
        }
        else
            char_print += ft_printchar(format[i]); // Call ft_printchar for regular characters
        i++; // Move to the next character in the format string
    }
    va_end(lst); //cleans the list
    return (char_print); //returns the total number of characters printed
}
