/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:19:43 by asebrani          #+#    #+#             */
/*   Updated: 2024/11/11 00:36:03 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void get_data(t_data *data, char **av)
{
    data->num_philos = atoi(av[1]);
    data->time_to_die = atoi(av[2]);
    data->time_to_eat = atoi(av[3]);
    data->time_to_sleep = atoi(av[4]);
    if(av[5])
        data->num_meals = atoi(av[5])
    if( !data->num_philos || data->time_to_die
        || data->time_to_eat || data->time_to_sleep 
        || data->num_meals)
    
}
int parse(char **av, t_data *data, int ac)
{
    int i = 0;
    if (ac == 5)
    {
        get_data(data, av);
        while(i < )
    }
}