/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:55:27 by franmart          #+#    #+#             */
/*   Updated: 2023/01/16 09:59:04 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# define SLEEP 0
# define THINK 1
# define EAT 2

typedef struct s_philo
{
	int				philo_id;
	time_t			time_last_meal;
	time_t			start_time;
	int				stop;
	pthread_mutex_t lock_print;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
}	t_philo;


typedef struct s_args
{
	int				n_philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				dead;
	int				eat_limit;
	time_t			start_time;
	pthread_mutex_t	*forks;
	pthread_t		*thread_ids;
	pthread_mutex_t	lock_print;
	t_philo			*philos;
}	t_args;

int				secure_atoi(char *atoi_nbr);
void			parse_args(int argc, char **argv, t_args *philo);

int				ft_atoi(const char *nptr);
char			*ft_itoa(int n);
unsigned int	ft_strlen(const char *s);

#	endif