/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:00:25 by franmart          #+#    #+#             */
/*   Updated: 2023/01/21 20:35:29 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc != 5 && argc != 6)
		return (1);
	parse_args(argc, argv, &args);
	init_philos(&args);
	init_threads(&args);
	end_threads(&args);
	end_mutex(&args);
	free_philo(&args);
	return (0);
}
