/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:17:52 by franmart          #+#    #+#             */
/*   Updated: 2023/01/22 10:04:42 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	dead_philo(t_philo *philo, int mute)
{
	(void) mute;
	print_action(philo, DEAD_STR);
	return ;
}

int	all_ate(t_args *args)
{
	(void) args;
	return (0);
}

int	check_anyone_died(t_args *args)
{
	int	status;

	status = 0;
	pthread_mutex_lock(&args->dead_lock);
	if (args->dead == 1)
		status = 1;
	pthread_mutex_unlock(&args->dead_lock);
	return (status);
}

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
		pthread_mutex_lock(&philo->args->dead_lock);
		philo->args->dead = 1;
		pthread_mutex_unlock(&philo->args->dead_lock);
	}
	return (status);
}

void	*philo_waiter(void *arg)
{
	t_args	*args;
	int		i;

	args = (t_args *)arg;
	while (!check_anyone_died(args))
	{
		i = -1;
		while (++i < args->n_philos)
		{
			if (check_philo_died(&args->philos[i]))
			{
				dead_philo(&args->philos[i], 0);
				return (NULL);
			}
		}
	}
	return (NULL);
}
