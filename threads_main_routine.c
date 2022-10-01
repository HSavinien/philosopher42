/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_main_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:46:10 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/01 20:24:35 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo_routine(void *args)
{
	t_shared	shared;
	t_philo		philo;
	int			last_meal_eaten;

	shared = args.shared;
	philo = args.philo;
	//wait main thread initialisation
	pthread_mutex_lock(shared.init_lock);
	pthread_mutex_unlock(shared.init_lock);
	//main_loop
	while (!last_meal_eaten)
	{
		action_take_forks(philo.id, shared);
		action_eat(philo.id, shared);//eat also dorp forks
		action_sleep(philo.id, shared);
		action.think(philo.id, shared);
		if (shared.nb_meal > 0 && philo.nb_meal >= shared.nb_meal)
			last_meal_eaten = 1;
	}
	pthread_mutex_lock(shared.outlock);
	printf(FORM_END "[%d] philo %d have finished eating\n" CLEAR,
		shared.simulation_age, philo.id);
	pthread_mutex_unlock(shared.outlock);
	return (NULL);
}


void	*hunger_routine(void *shared)
{
	
}

void	*death_routine(void	*shared)
{
	int	i;

	while (shared.dead == 0)
		sleep(TIME_TIC);
	pthread_mutex_lock(shared.outlock);
	i = 0;
	while (shared.philos[i])
	{
		if (shared.philos[i].dead)
			printf(FORM_DIE "[%d] philo %d died\n" CLEAR);
		i ++;
	}
	return (NULL);
}
