/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:17:52 by franmart          #+#    #+#             */
/*   Updated: 2023/01/21 20:37:09 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	dead_philo(t_philo *philo, int mute)
{
	(void) philo;
	(void) mute;
	return ;
}

int	all_ate(t_args *args)
{
	(void) args;
	return (0);
}

void	*philo_waiter(void *arg)
{
	t_philo	*philo;
	t_args	*args;

	args = (t_args *)arg;
	philo = args->philos;
	(void) philo;
	return (NULL);
}
