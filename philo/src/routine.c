/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:46:43 by franmart          #+#    #+#             */
/*   Updated: 2023/01/22 14:11:55 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* fix the initial deadlock making odd eating while even are sleeping */
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2)
	{
		while (!check_anyone_finish(philo->args))
		{
			ph_sleep(philo);
			ph_think(philo);
			ph_take_forks(philo);
			ph_eat(philo);
		}
	}
	else
	{
		while (!check_anyone_finish(philo->args))
		{
			ph_take_forks(philo);
			ph_eat(philo);
			ph_sleep(philo);
			ph_think(philo);
		}
	}
	return (NULL);
}

/* add limit case when there is only one fork on the table */
void	ph_take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	print_action(philo, FORK_STR);
	if (philo->args->n_philos == 1)
	{
		pthread_mutex_lock(&philo->args->finish_lock);
		usleep(philo->args->die_time * 1000);
		philo->args->finish = 1;
		pthread_mutex_unlock(&philo->args->finish_lock);
		print_action(philo, DEAD_STR);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_action(philo, FORK_STR);
}

void	ph_eat(t_philo *philo)
{
	if (philo->args->n_philos == 1)
		return ;
	pthread_mutex_lock(&philo->eating);
	print_action(philo, EAT_STR);
	philo->eat_count++;
	philo->time_last_meal = ft_now();
	pthread_mutex_unlock(&philo->eating);
	ft_sleep(philo->args->eat_time, philo->args);
	pthread_mutex_unlock(&philo->l_fork);
	if (philo->args->n_philos != 1)
		pthread_mutex_unlock(philo->r_fork);
}

void	ph_sleep(t_philo *philo)
{
	if (philo->args->n_philos == 1)
		return ;
	print_action(philo, SLEEP_STR);
	ft_sleep(philo->args->sleep_time, philo->args);
}

void	ph_think(t_philo *philo)
{
	print_action(philo, THINK_STR);
}
