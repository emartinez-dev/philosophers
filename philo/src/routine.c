/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:46:43 by franmart          #+#    #+#             */
/*   Updated: 2023/01/21 20:36:56 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	(void) philo;
	return (NULL);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	print_action(philo, FORK_STR);
	pthread_mutex_lock(philo->r_fork);
	print_action(philo, FORK_STR);
}

void	eat(t_philo *philo)
{
	print_action(philo, EAT_STR);
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