/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:46:43 by franmart          #+#    #+#             */
/*   Updated: 2023/01/22 10:22:16 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!check_anyone_died(philo->args))
	{
		take_forks(philo);
		eat(philo);
		ph_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	print_action(philo, FORK_STR);
	if (philo->args->n_philos == 1)
	{
		pthread_mutex_lock(&philo->args->dead_lock);
		usleep(philo->args->die_time * 1000);
		philo->args->dead = 1;
		pthread_mutex_unlock(&philo->args->dead_lock);
		dead_philo(philo, 0);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_action(philo, FORK_STR);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	print_action(philo, EAT_STR);
	philo->eat_count++;
	philo->time_last_meal = ft_now() + philo->args->eat_time;
	pthread_mutex_unlock(&philo->eating);
	usleep(philo->args->eat_time * 1000);
	pthread_mutex_unlock(&philo->l_fork);
	if (philo->args->n_philos != 1)
		pthread_mutex_unlock(philo->r_fork);
}

void	ph_sleep(t_philo *philo)
{
	print_action(philo, SLEEP_STR);
	usleep(philo->args->sleep_time * 1000);
}

void	think(t_philo *philo)
{
	print_action(philo, THINK_STR);
}
