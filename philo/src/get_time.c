/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:33:39 by hel-kame          #+#    #+#             */
/*   Updated: 2023/02/14 16:51:35 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	struct timeval	time;
	long int		time_in_ms;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	time_in_ms = ((time.tv_sec * 100000) + time.tv_usec);
	return (time_in_ms);
}
