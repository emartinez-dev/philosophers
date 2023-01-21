/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:30:15 by franmart          #+#    #+#             */
/*   Updated: 2023/01/11 10:36:28 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	unsigned int	i;
	char			*str;

	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_intlen(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_lastdigit(int n)
{
	while (n > 9)
		n = n % 10;
	return (n);
}

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	result = nb;
	i = 1;
	if (power == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		n_len;
	char	*str;
	int		stop;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	stop = 0;
	n_len = ft_intlen(n);
	str = malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		stop = 1;
	}
	str[n_len] = '\0';
	while (n_len > stop)
	{
		str[n_len - 1] = ft_lastdigit(n) + '0';
		n /= 10;
		n_len--;
	}
	return (str);
}
