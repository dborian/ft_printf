/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:38:01 by dedme             #+#    #+#             */
/*   Updated: 2024/12/02 23:38:01 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_argnumb(const char *str)
{
	int	i;
	int	c;
	int j;
	char *set;

	set = "cspdiuxX";
	j = 0;
	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			while (set[j])
			{
				if (set[j] == str[i+1])
				{
					c++;
					break;
				}
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (c);
}

int	ft_printf(const char *str, ...)
{

	va_list args;
	va_list args_copy;
	int i;

	// Initialize the va_list variable with the number of arguments
	va_start(args, ft_argnumb(str));

	// Make a copy of the va_list
	va_copy(args_copy, args);

	// Loop through the arguments using va_arg
	i = 0;
	while (i < num) {
		int value = va_arg(args, int);
		printf("Original: %d\n", value);
		i++;
	}

	// End the use of the original va_list
	va_end(args);

	// Loop through the copied va_list
	i = 0;
	while (i < num) {
		int value = va_arg(args_copy, int);
		printf("Copy: %d\n", value);
		i++;
	}

	// End the use of the copied va_list
	va_end(args_copy);
}

int main()
{
	ft_printf("%c\n", 'a');
	return 0;
}