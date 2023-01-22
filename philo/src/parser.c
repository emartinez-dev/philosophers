/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:20:58 by franmart          #+#    #+#             */
/*   Updated: 2023/01/22 10:22:04 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	parse_args(int argc, char **argv, t_args *args)
{
	args->n_philos = secure_atoi(argv[1]);
	if (args->n_philos < 1)
		exit(1);
	args->die_time = secure_atoi(argv[2]);
	args->eat_time = secure_atoi(argv[3]);
	args->sleep_time = secure_atoi(argv[4]);
	args->eat_limit = -1;
	args->dead = 0;
	if (argc == 6)
	{
		args->eat_limit = secure_atoi(argv[5]);
		if (args->eat_limit < 1)
			exit(1);
	}
}
