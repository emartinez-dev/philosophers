/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:05:33 by franmart          #+#    #+#             */
/*   Updated: 2023/01/21 15:26:24 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	end_mutex(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->n_philos)
	{
		pthread_mutex_destroy(&args->philos[i].l_fork);
		pthread_mutex_destroy(&args->philos[i].eat_check);
	}
	pthread_mutex_destroy(&args->print_lock);
	pthread_mutex_destroy(&args->dead_lock);
}

void	free_philo(t_args *args)
{
	free(args->philos);
	free(args->thread_ids);
}