/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:05:33 by franmart          #+#    #+#             */
/*   Updated: 2023/01/18 12:06:46 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	end_mutex(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philos)
	{
		pthread_mutex_unlock(&args->forks[i]);
		pthread_mutex_destroy(&args->forks[i]);
	}
	pthread_mutex_unlock(&args->lock_print);
	pthread_mutex_destroy(&args->lock_print);
}

void	free_philo(t_args *args)
{
	free(args->philos);
	free(args->thread_ids);
	if (args->n_philos == 1)
		free(args->forks);
}