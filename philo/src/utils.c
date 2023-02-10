/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:08:57 by hel-kame          #+#    #+#             */
/*   Updated: 2023/02/10 16:23:06 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	val;
	int	neg;

	i = 0;
	val = 0;
	neg = 0;
	if (nptr == NULL)
		return (-1);
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
		neg = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while ((nptr[i] != '\0') && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		val *= 10;
		val += nptr[i] - '0';
		i++;
	}
	if (neg == 1)
		return (-val);
	else
		return (val);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
