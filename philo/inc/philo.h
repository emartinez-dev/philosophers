/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:55:27 by franmart          #+#    #+#             */
/*   Updated: 2023/01/18 13:02:37 by franmart         ###   ########.fr       */
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
# define FORK 3
# define DEAD 4

# define SLEEP_STR "is sleeping\n"
# define THINK_STR "is thinking\n"
# define EAT_STR "is eating\n"
# define FORK_STR "has taken a fork\n"
# define DEAD_STR "died\n"

typedef struct s_args t_args;

typedef struct s_philo
{
	int				philo_id;
	time_t			time_last_meal;
	time_t			start_time;
	int				eat_n_times;
	int				stop;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	t_args			*args;
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
void			init_forks(t_args *args);
void			init_philos(t_args *args);
void			init_threads(t_args *args);
void			end_threads(t_args *args);
void			*philo_routine(void *arg);
void			think(t_philo *philo);
void			eat(t_philo *philo);
void			ph_sleep(t_philo *philo);
void			take_forks(t_philo *philo);
void			print_action(t_philo *philo, char *action);
int				all_ate(t_args *args);
void			dead_philo(t_args *args, t_philo *philo, int mute);
void			*philo_waiter(void *arg);
void			free_philo(t_args *args);
void			end_mutex(t_args *args);

time_t			ft_now(void);
int				ft_atoi(const char *nptr);
char			*ft_itoa(int n);
unsigned int	ft_strlen(const char *s);

#	endif