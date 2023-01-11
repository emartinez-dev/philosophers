/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:20:58 by franmart          #+#    #+#             */
/*   Updated: 2023/01/11 10:54:50 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	parse_args(int argc, char **argv, t_philo *philo)
{
	philo->n = secure_atoi(argv[1]);
	philo->die_time = secure_atoi(argv[2]);
	philo->eat_time = secure_atoi(argv[3]);
	philo->sleep_time = secure_atoi(argv[4]);
	philo->times = -1;
	if (argc == 6)
		philo->times = secure_atoi(argv[5]);
	//printf("%d %d %d %d %d\n", philo->n, philo->die_time, philo->eat_time, philo->sleep_time, philo->times);
}
