/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:58:05 by asebrani          #+#    #+#             */
/*   Updated: 2024/11/19 08:48:08 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_eyz_on_dem(t_params *params)
{
	int		count;

	count = 0;
	while (1)
	{
		if (check_if_any_died(params) == 1)
			return ;
	}
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->mtx_death);
	if (*(philo->dead_flag))
	{
		pthread_mutex_unlock(philo->mtx_death);
		return (1);
	}
	pthread_mutex_unlock(philo->mtx_death);
	return (0);
}

void	print_lock(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->mtx_print);
	printf("%ld %d %s\n", get_time_stamp()
		- philo->start_time, philo->id, str);
	pthread_mutex_unlock(philo->mtx_print);
}

long	get_time_stamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long time, t_philo *philo)
{
	long	start_time;

	start_time = get_time_stamp();
	while (get_time_stamp() - start_time < time
		&& !check_death(philo))
		usleep(100);
}
