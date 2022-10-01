/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:37:58 by tmongell          #+#    #+#             */
/*   Updated: 2022/09/30 13:40:37 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int main (int ac, char **av)
{
	t_shared	shared;
	pthread_t	supervisor_id;
	//do parsing
	shared = do_parsing(ac, av);
	if (shared.error_code)
		return (error_args(shared.error_code));
	//initialise other values
	if (init_values(&shared))
		return (-shared.error_code);//error management might change
	//lock initialisation mutex
	pthread_mutex_lock(shared.init_lock);
	//create all philo
	if(create_all_philo(& shared))
		return (-shared.error_code);//error management might change
	//create hunger thread (incremente hunger of philo, kill them when needed)
	//create supervisor
	if(create_supervisor(shared))
		return (-shared.error_code);//error management might change
	//unlock initialisation thread
	pthread_mutex_unlock(shared.init_lock);
	//wait for supervisor (join)
	pthread_join(supervisor_id, NULL);
	return (0);
}

int init_values(t_shared *shared);
int	create_all_philo(t_shared *shared);
int create_supervisor(t_shared *shared);
