/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exxiitt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:17:25 by asebrani          #+#    #+#             */
/*   Updated: 2024/11/17 04:59:38 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_nd_exit(t_params *params, int res)
{
	int	i;

	i = 0;
	c_malloc(0, 0);
	if (res == 1)
	{
		while (i < params->number_of_philos)
			pthread_mutex_destroy(&params->forks[i++]);
	}
	else if (res == 2)
	{
		while (i < params->number_of_philos)
			pthread_mutex_destroy(&params->forks[i++]);
		pthread_mutex_destroy(&params->mtx_print);
	}
	else
	{
		while (i < params->number_of_philos)
			pthread_mutex_destroy(&params->forks[i++]);
		pthread_mutex_destroy(&params->mtx_print);
		pthread_mutex_destroy(&params->mtx_death);
	}
	return ;
}

int	check_if_any_died(t_params *params)
{
	int		i;
	int		count;
	t_philo	*philo;

	count = 0;
	i = 0;
	while (i < params->number_of_philos)
	{
		philo = &params->philos[i];
		pthread_mutex_lock(&params->mtx_death);
		if (get_time_stamp() - philo->last_time_eat
			> philo->time_to_die)
		{
			params->dead_flag = 1;
			pthread_mutex_unlock(&params->mtx_death);
			return (print_lock("died", philo), 1);
		}
		if (!philo->number_of_meals)
			return (pthread_mutex_unlock(&params->mtx_death), 1);
		pthread_mutex_unlock(&params->mtx_death);
		i++;
	}
	return (0);
}

long	convert_str_to_num(char **str)
{
	long	ret;

	ret = 0;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			return (-1);
		(*str)++;
	}
	if (**str >= '0' && **str <= '9')
	{
		while (**str >= '0' && **str <= '9')
		{
			ret = ret * 10 + *(*str)++ - '0';
			if (ret > INT_MAX)
				return (-1);
		}
	}
	else
		return (-1);
	return (ret);
}
