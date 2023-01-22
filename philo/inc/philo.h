/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:55:27 by franmart          #+#    #+#             */
/*   Updated: 2023/01/22 11:15:55 by franmart         ###   ########.fr       */
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

# define SLEEP_STR "is sleeping\n"
# define THINK_STR "is thinking\n"
# define EAT_STR "is eating\n"
# define FORK_STR "has taken a fork\n"
# define DEAD_STR "died\n"

typedef struct s_args	t_args;

typedef struct s_philo
{
	int				philo_id;
	time_t			time_last_meal;
	int				eat_count;
	int				stop;
	pthread_mutex_t	eating;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	t_args			*args;
}	t_philo;

typedef struct s_args
{
	int				n_philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				finish;
	int				eat_limit;
	time_t			start_time;
	pthread_t		*thread_ids;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	finish_lock;
	t_philo			*philos;
}	t_args;

/* init.c */
void			init_philos(t_args *args);
void			init_threads(t_args *args);

/* routine.c */
void			*philo_routine(void *arg);
void			ph_take_forks(t_philo *philo);
void			ph_eat(t_philo *philo);
void			ph_sleep(t_philo *philo);
void			ph_think(t_philo *philo);

/* waiter.c */
void			*philo_waiter(void *arg);
int				all_ate(t_args *args);
int				check_anyone_finish(t_args *args);
int				check_philo_died(t_philo *philo);

/* exit.c */
void			end_mutex(t_args *args);
void			end_threads(t_args *args);
void			free_philo(t_args *args);

/* utils.c */
time_t			ft_now(void);
void			print_action(t_philo *philo, char *action);

/* parser.c */
int				parse_args(int argc, char **argv, t_args *philo);
int				secure_atoi(char *atoi_nbr);

/* parser utils */
int				ft_atoi(const char *nptr);
char			*ft_itoa(int n);
unsigned int	ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);

#	endif