/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:29:02 by asebrani          #+#    #+#             */
/*   Updated: 2024/11/19 08:43:01 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_params	params;
	int			res;
	int			i;

	res = 0;
	i = 0;
	if (!(ac == 5 || ac == 6))
		return (write(2, "errror number of argements\n", 28), 1);
	if (1 == check_args(&params, av))
		return (write(2, "error in args\n", 15), 1);
	else if (check_args(&params, av) == 2)
		return (1);
	if (init_params(&params) != 8)
		return (clean_nd_exit(&params, res),
			write(2, "somthing bad happened\n", 21), 0);
	while (i < params.number_of_philos)
	{
		res = pthread_create(&params.threads[i],
				NULL, around_the_table, &params.philos[i]);
		if (res != 0)
			return (clean_nd_exit(&params, 0),
				write(2, "error in threads\n", 17), 0);
		i++;
	}
	return (everything_in_here(&params));
}

int	everything_in_here(t_params *params)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	all_eyz_on_dem(params);
	while (i < params->number_of_philos)
	{
		res = pthread_join(params->threads[i], NULL);
		if (res != 0)
			return (write(2, "error in waiting for threads\n", 30)
				, clean_nd_exit(params, 0), 0);
		i++;
	}
	clean_nd_exit(params, 0);
	return (0);
}
