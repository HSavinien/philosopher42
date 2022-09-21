/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:37:58 by tmongell          #+#    #+#             */
/*   Updated: 2022/09/21 17:22:34 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av, char **env)
{
	t_param			parameters;
	int				*forks;
	t_philo			*philo_lst;
	pthread_mutex_t	init_lock;

	init_lock = pthread_mutex_init;
	phtread_mutex_lock(&init_lock);
	parameters = do_parsing(ac, av);
	forks = malloc(sizeof(int) * parameters.nb_philo);
	philo_lst = malloc(sizeof(philo_lst) * parameters.nb_philo);
	if (!fork || !philo_lst)
		error("unexpected malloc error on initialisation", ERR_MALLOC);


	phtread_mutex_unlock(&init_lock);
}
