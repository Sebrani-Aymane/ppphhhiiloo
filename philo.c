/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:28:22 by asebrani          #+#    #+#             */
/*   Updated: 2024/11/11 22:49:27 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int current_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void usleep_ms(long ms)
{
	usleep(ms * 1000);
}

int main(int ac, char **av)
{
	t_data    *data;
	int       i;

	i = 0;
	if (ac == 5 || ac == 6)
		parse(av, data, ac);
	else
		write(2,"too many/few arguments\n", 25);
	while (i < data->num_philos)
	{
		pthread_create
	}
	
}





