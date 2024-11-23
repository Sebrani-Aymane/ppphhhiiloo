/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:54:50 by asebrani          #+#    #+#             */
/*   Updated: 2024/11/17 04:59:26 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	cs_atoi(char *str)
{
	char	*ptr;
	long	result;

	ptr = str;
	result = convert_str_to_num(&ptr);
	if (result == -1)
		return (-1);
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr)
		return (-1);
	return ((int)result);
}

int	check_args(t_params *params, char **av)
{
	params -> number_of_philos = cs_atoi(av[1]);
	params -> time_to_die = cs_atoi(av[2]);
	params -> time_to_eat = cs_atoi(av[3]);
	params -> time_to_sleep = cs_atoi(av[4]);
	if (av[5])
		params -> number_of_meals = cs_atoi(av[5]);
	else
		params -> number_of_meals = -1;
	if (params -> number_of_philos == -1 || params -> time_to_die == -1
		|| params -> time_to_eat == -1 || params -> time_to_sleep == -1
		|| (params ->number_of_meals == -1 && av[5]))
		return (1);
	else if (params->number_of_philos == 0 || params->number_of_meals == 0)
		return (2);
	return (0);
}

void	init_philos(t_params *params, int id)
{
	params->philos[id].id = id + 1;
	params->philos[id].time_to_die = params -> time_to_die;
	params->philos[id].time_to_eat = params -> time_to_eat;
	params->philos[id].time_to_sleep = params -> time_to_sleep;
	params->philos[id].start_time = get_time_stamp();
	params->philos[id].last_time_eat = get_time_stamp();
	params->philos[id].dead_flag = &(params->dead_flag);
	params->philos[id].number_of_meals = params -> number_of_meals;
	params->philos[id].mtx_print = &params->mtx_print;
	params->philos[id].mtx_death = &params->mtx_death;
	params->philos[id].right_fork = &params->forks[id];
	if (id + 1 == params->number_of_philos)
		params->philos[id].left_fork = &params->forks[0];
	else
		params->philos[id].left_fork = &params->forks[id + 1];
}

int	handle_allocations(t_params *params)
{
	params->dead_flag = 0;
	params->philos = c_malloc(sizeof(t_philo) * params -> number_of_philos, 1);
	if (!params ->philos)
		return (0);
	params->forks = c_malloc(sizeof(pthread_mutex_t)
			* params->number_of_philos, 1);
	if (!params -> forks)
		return (0);
	params->threads = c_malloc(sizeof(pthread_t)
			* params -> number_of_philos, 1);
	if (!params->threads)
		return (0);
	return (1);
}

int	init_params(t_params *params)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (!handle_allocations(params))
		return (0);
	while (i < params->number_of_philos)
	{
		res = pthread_mutex_init(&params->forks[i++], NULL);
		if (res != 0)
			return (1);
	}
	res = pthread_mutex_init(&params->mtx_print, NULL);
	if (res != 0)
		return (2);
	res = pthread_mutex_init(&params->mtx_death, NULL);
	if (res != 0)
		return (3);
	while (i--)
		init_philos(params, i);
	return (8);
}
