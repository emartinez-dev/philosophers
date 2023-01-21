/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:46:43 by franmart          #+#    #+#             */
/*   Updated: 2023/01/21 18:12:23 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->args->dead == 0)
	{
		if (philo->args->dead == 1 || philo->stop == 1 || all_ate(philo->args))
			return (NULL);
		take_forks(philo);
		if (philo->args->dead == 1 || philo->stop == 1 || all_ate(philo->args))
			return (NULL);
		eat(philo);
		if (philo->args->dead == 1 || philo->stop == 1 || all_ate(philo->args))
			return (NULL);
		ph_sleep(philo);
		if (philo->args->dead == 1 || philo->stop == 1 || all_ate(philo->args))
			return (NULL);
		think(philo);
		if (philo->args->dead == 1 || philo->stop == 1 || all_ate(philo->args))
			return (NULL);
	}
	philo->stop = 1;
	return (NULL);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	print_action(philo, FORK_STR);
	if (philo->stop == 1)
		pthread_mutex_unlock(&philo->l_fork);
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_action(philo, FORK_STR);
	}
}

void	eat(t_philo *philo)
{
	print_action(philo, EAT_STR);
	pthread_mutex_lock(&philo->eat_check);
	philo->eat_n_times++;
	philo->time_last_meal = ft_now();
	usleep(philo->args->eat_time * 1000);
	pthread_mutex_unlock(&philo->eat_check);
	pthread_mutex_unlock(&philo->l_fork);
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