#ifndef PHILO_H
#define    PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>


typedef struct s_philos
{
	pthread_t	*philos_thread;
	int			id;
	pthread_mutex_t *left_frk;
	pthread_mutex_t *right_frk;
	int meals_eaten;
	int last_meal;

}	t_philos;

typedef struct s_data
{
	t_philos	*philos;
	int			num_philos;
	int			num_meals;
	int			start_sim;
	int			time_to_die;
	int			time_to_eat;
	long			time_to_sleep;
	pthread_mutex_t *forks;
	pthread_mutex_t *printer;
}	t_data;
int parse(char **av, t_data *data, int ac);
int get_data(t_data *data, char **av);
int current_time(void);
#endif

