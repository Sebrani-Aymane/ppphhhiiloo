/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:09:53 by asebrani          #+#    #+#             */
/*   Updated: 2024/11/20 22:26:28 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>

struct	s_params;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
	long			last_time_eat;
	long			number_of_meals;
	int				*dead_flag;
	pthread_mutex_t	*mtx_print;
	pthread_mutex_t	*mtx_death;
	struct s_params	*param;
}	t_philo;

typedef struct s_params
{
	pthread_t		*threads;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				number_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_meals;
	int				dead_flag;
	pthread_mutex_t	mtx_print;
	pthread_mutex_t	mtx_death;
	pthread_mutex_t	meals;
}	t_params;

typedef struct s_coll
{
	void			*ptr;
	struct s_coll	*next;
}	t_coll;

void	print_lock(char *str, t_philo *philo);
int		check_death(t_philo *philo);
void	all_eyz_on_dem(t_params *params);
void	*around_the_table(void *param);
void	init_philos(t_params *params, int id);
int		init_params(t_params *params);
int		check_args(t_params *params, char **av);
long	get_time_stamp(void);
int		cs_atoi(char *str);
void	ft_usleep(long time, t_philo *philo);
void	*c_malloc(size_t size, int flag);
void	clean_nd_exit(t_params *params, int ret);
long	convert_str_to_num(char **str);
int		everything_in_here(t_params *params);
int		check_if_any_died(t_params *params);
