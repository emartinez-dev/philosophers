/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:36:32 by franmart          #+#    #+#             */
/*   Updated: 2023/01/22 10:21:45 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* Gets the actual time of the day in ms */
time_t	ft_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (1000 * now.tv_sec + now.tv_usec / 1000);
}

void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->args->print_lock);
	if (!check_anyone_died(philo->args) || \
		ft_strncmp(action, DEAD_STR, ft_strlen(action)) == 0)
	{
		printf("%ld %d %s", \
			ft_now() - philo->args->start_time, philo->philo_id + 1, action);
	}
	pthread_mutex_unlock(&philo->args->print_lock);
}
