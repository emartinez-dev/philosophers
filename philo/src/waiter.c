/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:17:52 by franmart          #+#    #+#             */
/*   Updated: 2023/01/22 13:08:35 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* A thread that checks if all the philos have eaten or if anyone has died */
void	*philo_waiter(void *arg)
{
	t_args	*args;
	int		i;

	args = (t_args *)arg;
	while (!check_anyone_finish(args))
	{
		i = -1;
		while (++i < args->n_philos)
		{
			if (check_philo_died(&args->philos[i]))
			{
				print_action(&args->philos[i], DEAD_STR);
				return (NULL);
			}
			else if (all_ate(args))
				return (NULL);
		}
	}
	return (NULL);
}

int	all_ate(t_args *args)
{
	int	i;
	int	status;

	i = -1;
	status = 1;
	if (args->eat_limit == -1)
		return (0);
	while (++i < args->n_philos)
	{
		pthread_mutex_lock(&args->philos[i].eating);
		if (args->philos[i].eat_count < args->eat_limit)
			status = 0;
		pthread_mutex_unlock(&args->philos[i].eating);
	}
	if (status)
	{
		pthread_mutex_lock(&args->finish_lock);
		args->finish = 1;
		pthread_mutex_unlock(&args->finish_lock);
	}
	return (status);
}

/* safely read the finish flag */
int	check_anyone_finish(t_args *args)
{
	int	status;

	status = 0;
	pthread_mutex_lock(&args->finish_lock);
	if (args->finish == 1)
		status = 1;
	pthread_mutex_unlock(&args->finish_lock);
	return (status);
}

/* if the given philo has died, sets finish flag as one */
int	check_philo_died(t_philo *philo)
{
	int	status;

	status = 0;
	pthread_mutex_lock(&philo->eating);
	if (ft_now() - philo->time_last_meal > philo->args->die_time)
		status = 1;
	pthread_mutex_unlock(&philo->eating);
	if (status == 1)
	{
		pthread_mutex_lock(&philo->args->finish_lock);
		philo->args->finish = 1;
		pthread_mutex_unlock(&philo->args->finish_lock);
	}
	return (status);
}
