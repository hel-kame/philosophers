/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:52:05 by hel-kame          #+#    #+#             */
/*   Updated: 2023/02/10 19:58:25 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_argc(int argc, char **argv)
{
	int		i;
	int		y;

	i = 1;
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

static void	init_struct(int argc, char **argv, t_philo *p)
{
	p->nb_philo = ft_atoi(argv[1]);
	p->time_die = ft_atoi(argv[2]);
	p->time_eat = ft_atoi(argv[3]);
	p->time_sleep = ft_atoi(argv[4]);
	p->must_eat = 0;
	if (argc == 6)
		p->must_eat = ft_atoi(argv[5]);
}

void *create_thread(void *th)
{
	int *id = (int *)th;
	static int s = 0;

	s++;
	printf("Thread ID: %d, Static: %d\n", *id, s);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo		p;
	pthread_t	t_id;
	int i;

	i = 0;
	if (argc != 5 && argc != 6)
	{
		write(2, "Bad usage.\n", 11);
		return (-1);
	}
	if (check_argc(argc, argv) == -1)
		return (-1);
	init_struct(argc, argv, &p);
	while (i < p.nb_philo)
	{
		pthread_create(&t_id, NULL, create_thread, (void *)&t_id);
		i++;
	}
	pthread_exit(NULL);
	return (0);
}
