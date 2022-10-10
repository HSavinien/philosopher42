/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:30:10 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/06 21:42:27 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

/*includes------------------------------------------------------------includes*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <pthread.h>
#include <sys/time.h>
#include "error_code.h"
#include "format.h"

#include <stdio.h>//============================================================debug

/*macros----------------------------------------------------------------macros*/

#define TIME_TIC 250
#define MAX_PHILO 200

/*structures--------------------------------------------------------structures*/

typedef struct s_philo {
	pthread_t	thread_id;
	int			id;
	int			dead;
	int			nb_meal;
	int			hunger; //time since last meal
	
}	t_philo;

typedef struct s_shared {
	int				nb_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				nb_meal;
	int				dead_philo;
	int				error_code;
	int				simul_age;
	t_philo			philos[MAX_PHILO];
	pthread_t		hunger;
	pthread_t		death;
	pthread_mutex_t outlock;//locking access to stdout
	pthread_mutex_t	forks[MAX_PHILO];
	pthread_mutex_t init_lock;
}	t_shared;

typedef struct s_thread_arg {
t_shared	*shared;
t_philo		*philo;
}		t_thread_arg;

/*prototypes--------------------------------------------------------prototypes*/

//parsing
t_shared	do_parsing(int ac, char **av);

//initialisation
int		create_all_philo(t_shared *shared);
int		create_one_philo(t_shared *shared, int index);
int		init_values(t_shared *shared);
int		init_supervisor(t_shared *shared);

//utils
void	accurate_sleep(int time);	//time in ms
void	wait_init(void);

//threads routines
void	*philo_routine(void *args);
void	*hunger_routine(void *shared);
void	*death_routine(void *shared);

//actions
void	action_take_forks(int philo_num, t_shared *shared);
void	action_eat(int philo_num, t_shared *shared);
void	action_sleep(int philo_num, t_shared *shared);
void	action_think(int philo_num, t_shared *shared);
void	action_die(int philo_num, t_shared *shared);

//lib function
int		ft_atoi(const char *str);
int 	ft_isdigit(int c);
int		ft_isspace(int c);

//error management
int		error_args(int err_code);
int		error_msg(char *msg, int err_code, t_shared *shared);

#endif
