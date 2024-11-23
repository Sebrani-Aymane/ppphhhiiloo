/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:10:57 by asebrani          #+#    #+#             */
/*   Updated: 2024/11/20 16:51:46 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*handle_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (check_death(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		return (NULL);
	}
	print_lock("has taken a fork", philo);
	if (philo->left_fork == philo->right_fork)
		return (NULL);
	pthread_mutex_lock(philo->left_fork);
	if (check_death(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	print_lock("has taken a fork", philo);
	return ((void *)1);
}

void	*eating_process(t_philo *philo)
{
	pthread_mutex_lock(philo->mtx_death);
	if (!philo->number_of_meals--)
	{
		pthread_mutex_unlock(philo->mtx_death);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	print_lock("is eating", philo);
	philo->last_time_eat = get_time_stamp();
	pthread_mutex_unlock(philo->mtx_death);
	ft_usleep(philo->time_to_eat, philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return ((void *)1);
}

void	*eating_routine(t_philo *philo)
{
	if (!handle_forks(philo))
		return (NULL);
	if (check_death(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	return (eating_process(philo));
}

void	*around_the_table(void *param)
{
	t_philo	*philo;

	philo = param;
	philo->start_time = get_time_stamp();
	if (philo->id % 2 != 0)
	{
		print_lock("is thinking", philo);
		ft_usleep(philo->time_to_eat, philo);
	}
	while (!check_death(philo))
	{
		if (!eating_routine(philo))
			return (NULL);
		if (check_death(philo))
			return (NULL);
		print_lock("is sleeping", philo);
		ft_usleep(philo->time_to_sleep, philo);
		if (check_death(philo))
			return (NULL);
		print_lock("is thinking", philo);
	}
	return (NULL);
}
