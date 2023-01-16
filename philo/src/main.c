/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:00:25 by franmart          #+#    #+#             */
/*   Updated: 2023/01/16 10:29:26 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc != 5 && argc != 6)
		return (1);
	parse_args(argc, argv, &args);
	init_forks(&args);
	init_philos(&args);
	printf("%d %d %d %d %d\n", args.n_philos, args.die_time, args.eat_time, args.sleep_time, args.eat_limit);
	return (0);
}
