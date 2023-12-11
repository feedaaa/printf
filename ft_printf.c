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

#include "ft_printf.h"

int checkformat(va_list lst, char format)
{
	int len;
	
	len = 0;
    if (format == 'c')
        len += ft_printchar(va_arg(lst, int));
    else if (format == 's')
        len += ft_printstr(va_arg(lst, char *));
    else if (format == 'd' || format == 'i')
        len += ft_putdecimal(va_arg(lst, int));
    else if (format == 'x' || format == 'X')
        len += ft_printhex(va_arg(lst, unsigned int), format);
    else if (format == '%')
        len += ft_printchar('%');
    else if (format == 'p')
        len += ft_printptr(va_arg(lst, void *));
    else if (format == 'u')
        len += ft_printuint(va_arg(lst, unsigned int));
    return (len);
}

int ft_printf(const char *format, ...)
{
    va_list lst; 
    int i; 
    int char_print;

    va_start(lst, format);
    char_print = 0;
    i = 0;

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            char_print += checkformat(lst, format[i]);
        }
        else
            char_print += ft_printchar(format[i]);
        i++;
    }
    va_end(lst);
    return (char_print);
}

// int	main(void)
// {
// 	ft_printf("my result: \n\n %c\n %s\n %p\n %d\n %i\n %u\n %x\n %X\n %%\n", 'a', "my name is f@@bdu11&;", NULL, 123, 456, 429497296, 255, 255);
// 	printf("og result: \n\n %c\n %s\n %p\n %d\n %i\n %u\n %x\n %X\n %%\n", 'a', "my name is f@@bdu11&;", NULL, 123, 456, 429497296, 255, 255);
// }

// int main()
// {
//   printf(" %d\n ", -1);
//   ft_printf(" %d\n ", -1);
// }