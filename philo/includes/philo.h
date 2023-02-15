/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:46:25 by hel-kame          #+#    #+#             */
/*   Updated: 2023/02/15 18:37:15 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info t_info;
typedef struct s_philo {
	int				id;
	long int		last_eat;
	pthread_t		t_id;
	pthread_mutex_t	fork_r;
	pthread_mutex_t	fork_l;
	} 				t_philo;

typedef struct s_info {
	int				nb_philo;
	long int		time_start;
	long int		time_die;
	long int		time_eat;
	long int		time_sleep;
	long int		must_eat;
}					t_info;

int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
long int	get_time(void);
#endif
