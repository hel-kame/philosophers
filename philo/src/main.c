/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:52:05 by hel-kame          #+#    #+#             */
/*   Updated: 2023/02/15 18:37:19 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_argc(int argc, char **argv)
{
	int		i;
	int		y;

	while (i < argc)
	{
		y = 0;
		if (ft_atoi(argv[i]) < 0)
		{
			write(2, "Negative number.\n", 17);
			return (-1);
		}
		while (argv[i][y] != '\0')
		{
			if (ft_isdigit(argv[i][y]) == 0)
			{
				write(2, "Bad input.\n", 11);
				return (-1);
			}
			y++;
		}
		i++;
	}
	return (0);
}

static void	init_struct(int argc, char **argv, t_philo *p, t_info *info)
{
	info->nb_philo = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	info->must_eat = 0;
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	t_philo		*p;
	t_info		*info;

	if (argc != 5 && argc != 6)
	{
		write(2, "Bad usage.\n", 11);
		return (-1);
	}	
	if (check_argc(argc, argv) == -1)
		return (-1);
	p = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!info || !p)
		return (0);
	init_struct(argc, argv, p, info);
	for (i = 1; i <= 5; i++)
	{
		k = pthread_mutex_init(&chopstick[i], NULL);
		if (k == -1)
		{
			printf("Failed to initialize the mutex\n");
			exit(1);
		}
	}
	for (i = 1; i <= 5; i++)
	{
		k = pthread_create(&philosopher[i], NULL, (void *)func, (int *)i);
		if (k != 0)
		{
			printf("Error in thread creation.\n");
			exit(1);
		}
	}
	for (i = 1; i <= 5; i++)
	{
		k = pthread_join(philosopher[i], &message);
		if (k != 0)
		{
			printf("Failed to join the thread.\n");
			exit(1);
		}
	}
	for (i = 1; i <= 5; i++)
	{
		k = pthread_mutex_destroy(&chopstick[i]);
		if (k != 0)
		{
			printf("Mutex destroyed.\n");
			exit(1);
		}
	}
	return (0);
}
