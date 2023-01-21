/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:17:52 by franmart          #+#    #+#             */
/*   Updated: 2023/01/21 15:22:34 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	dead_philo(t_philo *philo, int mute)
{
	int	i;

	i = -1;
	philo->args->dead = 1;
	if (mute == 0)
		print_action(philo, DEAD_STR);
	while (++i < philo->args->n_philos)
		philo->args->philos[i].stop = 1;
}

int	all_ate(t_args *args)
{
	int	i;

	i = -1;
	if (args->eat_limit == -1)
		return (0);
	while (++i < args->n_philos)
	{
		pthread_mutex_lock(&args->philos[i].eat_check);
		if (args->philos[i].eat_n_times < args->eat_limit)
		{
			pthread_mutex_unlock(&args->philos[i].eat_check);
			return (0);
		}
		pthread_mutex_unlock(&args->philos[i].eat_check);
	}
	return (1);
}

void	*philo_waiter(void *arg)
{
	t_philo	*philo;
	t_args	*args;
	int		i;

	args = (t_args *)arg;
	philo = args->philos;
	i = 0;
	while (args->dead == 0)
	{
		i = -1;
		while (++i < args->n_philos)
		{
			if (ft_now() - philo[i].time_last_meal > args->die_time)
			{
				dead_philo(philo, 0);
				return (NULL);
			}
			else if (all_ate(args) == 1)
			{
				dead_philo(philo, 1);
				return (NULL);
			}
		}
	}
	return (NULL);
}
