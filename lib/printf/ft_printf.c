/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrawe <agrawe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:13:38 by erigolon          #+#    #+#             */
/*   Updated: 2023/10/04 16:02:01 by agrawe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		ft_printf(char const *str, ...)
{
	int		num_args;
	va_list	args;
	int		i;
	int		count;

	if (write(1, "", 0) == -1)
		return (-1);
	num_args = ft_strlen(str);
	va_start(args, str);
	i = 0;
	count = 0;
	while (i < num_args)
	{
		if (str[i] == '%')
		{
			i++;
			count = ft_check_percentage(str[i], args, count);
		}
		else
			count += ft_putcharf(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int	result;
	int	myresult;

	result = printf("Hola como %d estas\n", 0);
	myresult = ft_printf("Hola como %d estas\n", 0);
	printf("-----\n");
	printf("%d\n", result);
	printf("%d\n", myresult);
	return (0);
}
*/