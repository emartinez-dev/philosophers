/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:00:25 by franmart          #+#    #+#             */
/*   Updated: 2023/01/22 12:34:20 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc != 5 && argc != 6)
		return (1);
	if (parse_args(argc, argv, &args))
		return (1);
	if (init_philos(&args))
		return (2);
	if (init_threads(&args))
	{
		free(args.philos);
		return (3);
	}
	end_threads(&args);
	end_mutex(&args);
	free_philo(&args);
	return (0);
}
