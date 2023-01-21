/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:27:11 by franmart          #+#    #+#             */
/*   Updated: 2023/01/21 15:25:14 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
		philos[i].time_last_meal = ft_now();
		philos[i].stop = 0;
		philos[i].eat_n_times = 0;
		pthread_mutex_init(&philos[i].l_fork, 0);
		philos[i].r_fork = &philos[(i + 1) % args->n_philos].l_fork;
		philos[i].args = args;
		pthread_mutex_init(&philos[i].eat_check, 0);
	}
	pthread_mutex_init(&args->print_lock, NULL);
	pthread_mutex_init(&args->dead_lock, NULL);
	args->dead = 0;
	args->start_time = ft_now();
	args->philos = philos;
}

void	init_threads(t_args *args)
{
	int			i;
	pthread_t	waiter;

	i = -1;
	args->thread_ids = malloc(sizeof(pthread_t) * args->n_philos);
	while (++i < args->n_philos)
	{
		pthread_create(&args->thread_ids[i], 0, philo_routine, &args->philos[i]);
		usleep(20);
	}
	pthread_create(&waiter, 0, philo_waiter, (void *)args);
	pthread_join(waiter, 0);
}

void	end_threads(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philos)
		pthread_join(args->thread_ids[i], NULL);
}