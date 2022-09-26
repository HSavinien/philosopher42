/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:30:10 by tmongell          #+#    #+#             */
/*   Updated: 2022/09/26 20:24:33 by tmongell         ###   ########.fr       */
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
#include "error_code.h"

#include <stdio.h>//============================================================debug

/*macros----------------------------------------------------------------macros*/

#define TIME_TIC 250

/*structures--------------------------------------------------------structures*/

//structure to store the user input
typedef struct s_param {
	int	nb_philo;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	nb_meal;
	int	dead_philo;
	int	error_code;
}	t_param;

typedef struct s_philo {
	int			num;
	pthread_t	id;
	int			alive;
	int			last_meal;
	
}	t_philo;

/*prototypes--------------------------------------------------------prototypes*/

//parsing
t_param	do_parsing(int ac, char **av);

//initialisation
t_philo	*create_all_philo(t_param param, int *forks);
t_philo	*create_one_philo(t_param param, int index, int *forks);

//error management
int		error_args(int err_code);
int		error_msg(char *msg, int err_code);

//lib function
int	ft_atoi(const char *str);
int ft_isdigit(int c);
int ft_isspace(int c);

#endif
