/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:27:11 by franmart          #+#    #+#             */
/*   Updated: 2023/01/17 10:31:48 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_forks(t_args *args)
{
	int				i;
	pthread_mutex_t	*forks;

	i = -1;
	forks = malloc(sizeof(pthread_mutex_t) * args->n_philos);
	while (++i < args->n_philos)
		pthread_mutex_init(&forks[i], NULL);
	pthread_mutex_init(&args->lock_print, NULL);
	args->forks = forks;
}

void	init_philos(t_args *args)
{
	int		i;
	t_philo *philos;

	i = -1;
	philos = malloc(sizeof(t_philo) * args->n_philos);
	while (++i < args->n_philos)
	{
		philos[i].philo_id = i;
		philos[i].start_time = 0;
		philos[i].time_last_meal = 0;
		philos[i].stop = 0;
		philos[i].eat_n_times = 0;
		philos[i].l_fork = &args->forks[i];
		philos[i].r_fork = &args->forks[(i + 1) % args->n_philos];
		philos[i].args = args;
	}
	args->philos = philos;
}

void	init_threads(t_args *args)
{
	int	i;

	i = -1;
	args->thread_ids = malloc(sizeof(int) * args->n_philos);
	while (++i < args->n_philos)
	{
		pthread_create(&args->thread_ids[i], 0, philo_routine, &args->philos[i]);
	}
}