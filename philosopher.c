/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:37:58 by tmongell          #+#    #+#             */
/*   Updated: 2022/09/24 19:27:14 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


int	main(int ac, char **av)
{
	t_param			parameters;
	int				*forks;
	t_philo			*philo_lst;
	pthread_mutex_t	init_lock;

	pthread_mutex_init(&init_lock, NULL);
	pthread_mutex_lock(&init_lock);
	parameters = do_parsing(ac, av);
	if (parameters.dead_philo)
		return (error(parameters.dead_philo));
	forks = malloc(sizeof(int) * parameters.nb_philo);
	if (!forks)
		error("unexpected malloc error on initialisation", ERR_MALLOC);
	memset(forks, 1, parameters.nb_philo);
	//create all philo
	philo_lst = create_all_philo(parameters, forks)

	//end initialisation
	pthread_mutex_unlock(&init_lock);
	//wait for end of simulation
}
