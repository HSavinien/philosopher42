/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:50:43 by tmongell          #+#    #+#             */
/*   Updated: 2022/09/21 17:00:11 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

/*includes------------------------------------------------------------includes*/

#include "error_code.h"

/*macros----------------------------------------------------------------macros*/

#define TRUE 1
#define	FALSE 0

/*structures--------------------------------------------------------structures*/

//structure to store the user input
typedef struct s_param {
	int	nb_philo;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	nb_meal;
}	t_param;

typedef struct s_philo {
	int			num;
	pthread_t	id;
	bool_t		alive;
}	t_philo

/*prototypes--------------------------------------------------------prototypes*/

//parsing
t_param	do_parsing(int ac, char **av);

//error management :
void	error(char *msg, int err_code);
void	error_arg(char *prgm);
#endif
