/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:00:25 by franmart          #+#    #+#             */
/*   Updated: 2023/01/11 10:54:41 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc != 5 && argc != 6)
		return (1);
	parse_args(argc, argv, &philo);
	printf("%d %d %d %d %d\n", philo.n, philo.die_time, philo.eat_time, philo.sleep_time, philo.times);
	return (0);
}
