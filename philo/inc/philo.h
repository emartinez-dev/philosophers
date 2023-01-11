/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:55:27 by franmart          #+#    #+#             */
/*   Updated: 2023/01/11 10:38:33 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# define SLEEP 0
# define THINK 1
# define EAT 2

typedef struct s_philo
{
	int	n;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	eat_limit;
	int	times;
}	t_philo;

int				secure_atoi(char *atoi_nbr);
void			parse_args(int argc, char **argv, t_philo *philo);

int				ft_atoi(const char *nptr);
char			*ft_itoa(int n);
unsigned int	ft_strlen(const char *s);

#	endif