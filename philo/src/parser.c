/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:20:58 by franmart          #+#    #+#             */
/*   Updated: 2023/01/22 11:19:18 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	parse_args(int argc, char **argv, t_args *args)
{
	args->n_philos = secure_atoi(argv[1]);
	args->die_time = secure_atoi(argv[2]);
	args->eat_time = secure_atoi(argv[3]);
	args->sleep_time = secure_atoi(argv[4]);
	args->eat_limit = -1;
	if (args->n_philos < 1 || args->die_time < 1 || args->eat_time < 1 \
		|| args->sleep_time < 1)
		return (1);
	if (argc == 6)
	{
		args->eat_limit = secure_atoi(argv[5]);
		if (args->eat_limit < 1)
			return (1);
	}
	return (0);
}
