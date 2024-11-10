#ifndef PHILO_H
#define    PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthreads.h>
#include <stdlib.h>
typedef struct s_data
{
	t_philos	*philos;
	int			num_philos;
	int			num_meals;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
}	t_data;

typedef struct s_philos
{
	t_philos	*philos
	int			id;
	

}	t_philos;
int parse(char **av, t_data *data, int ac);
void get_data(t_data *data, char **av);
#endif

