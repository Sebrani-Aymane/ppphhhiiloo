/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:19:43 by asebrani          #+#    #+#             */
/*   Updated: 2024/11/11 22:46:41 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_values(t_data *data)
{
	if (data->num_philos > 200)
	{
		write(2, "more philos than allowed\n", 27);
		return (0);
	}
	else if (data->time_to_die < 60 || data->time < 60
			|| dat->time_to_sleep < 60)
	{
		write(2, "less time than allowed");
		return (0);
	}
	else
		return(1);
}

int	get_data(t_data *data, char **av)
{
	data->num_philos = atoi(av[1]);
	data->time_to_die = atoi(av[2]);
	data->time_to_eat = atoi(av[3]);
	data->time_to_sleep = atoi(av[4]);
	if (av[5])
		data->num_meals = atoi(av[5])
	else
		data->num_meals = -1;
	if (!check_values(data))
		return (0);
	return (1);
}
void	philo_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos->id = i + 1;
		data->philos->meals_eaten = 0;
		data->philo->left_frk = data->forks[i];
		data->philo->right_frk = data->forks[( i + 1 ) % num_philos];
		data->philo->last_meal = get_time();
		i++; 
	}
	
}
int parse(char **av, t_data *data, int ac)
{
	int i = 0;
	if(get_data(data, av))
	{
		data->philo->philos_thread = malloc(sizeof(pthread_t) * data->num_philos);
		data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
		if (!data->forks || !data->philo->philos_thread)
			return (0);
		while (i < data->num_meals)
			pthread_mutex_init(data->forks[i++],NULL);
		pthread_mutex_init(data->printer, NULL);
		data->start_sim = get_time();
		philo_init(data);
	}
}
