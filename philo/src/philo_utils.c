/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:36:32 by franmart          #+#    #+#             */
/*   Updated: 2023/01/22 13:46:57 by franmart         ###   ########.fr       */
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
	int		dead_action;
	time_t	timestamp;

	dead_action = !ft_strncmp(action, DEAD_STR, ft_strlen(action));
	pthread_mutex_lock(&philo->args->print_lock);
	timestamp = ft_now() - philo->args->start_time;
	if (!check_anyone_finish(philo->args) || dead_action)
		printf("%ld %d %s", timestamp, philo->philo_id + 1, action);
	pthread_mutex_unlock(&philo->args->print_lock);
}

/* ft_sleep: an attempt to fix usleep inconsistences */
void	ft_sleep(time_t ms, t_args *args)
{
	time_t	start_time;

	start_time = ft_now();
	while (ft_now() - start_time < ms && !check_anyone_finish(args))
		usleep(1000);
}
