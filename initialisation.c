/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:35:29 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/10 16:22:32 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	create_one_philo(t_shared *shared, int index)
{
	t_philo			*philo;
	t_thread_arg	*args;
	int				error;

	error = 0;
	philo = &shared->philos[index];
	//initialise all values
	philo->id = index;
	philo->hunger = 0;
	philo->nb_meal = 0;
	philo->dead = 0;
	//allocate t_arg struct
	args = malloc(sizeof (t_thread_arg));
	if (!args)
		return (error_msg("malloc failed to allocate", ERR_MALLOC, shared));
	//set correct values in struct
	args->shared = shared;
	args->philo = philo;
	//start thread
	error += pthread_create(&philo->thread_id, NULL, philo_routine, args);
	if (error)
		return (error_msg("failed to create philo thread", ERR_CREATE, shared));
	return (0);
}

int	create_all_philo(t_shared  *shared)
{
	int	i;

	i = 0;
	while (i < shared->nb_philo)
	{
		if (create_one_philo(shared, i))
			return (1);
		i ++;
	}
	return (0);
}

int	init_values(t_shared *shared)
{
	int	error;
	int	i;

	error = 0;
	i = 0;
	//set dead_philo to 0
	//set simul_age to 0
	shared->dead_philo = 0;
	shared->simul_age = 0;
	//init outlock and init_lock
	error += pthread_mutex_init(&(shared->outlock), NULL);
	error += pthread_mutex_init(&(shared->init_lock), NULL);
	//init each fork mutex (from 0 to nb_philo)
	while (i < shared->nb_philo)
		error += pthread_mutex_init((shared->forks + i++), NULL);
	if (error)
		return (error_msg("bad mutex initialisation", ERR_MUTEX_INIT, shared));
	return (0);

}

int	init_supervisor(t_shared *shared)
{
	int error;

	error = 0;
	error += pthread_create(&(shared->hunger), NULL, hunger_routine, shared);
	error += pthread_create(&(shared->death), NULL, death_routine, shared);
	if (error)
		return (error_msg("supervisors creation failed", ERR_CREATE, shared));
	return (0);
}
