/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_main_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:46:10 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/04 15:11:34 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo_routine(void *args)
{
	t_shared	*shared;
	t_philo		*philo;
	int			last_meal_eaten;

	shared = args.shared;
	philo = args.philo;
	wait_init();
	while (!last_meal_eaten && !shared->dead_philo)
	{
		action_take_forks(philo->id, shared);
		action_eat(philo->id, shared);//eat also drop forks
		action_sleep(philo->id, shared);
		action_think(philo->id, shared);
		if (shared->nb_meal > 0 && philo->nb_meal >= shared->nb_meal)
			last_meal_eaten = 1;
	}
	pthread_mutex_lock(shared->outlock);
	if (shared->nb_meal > 0 && philo->nb_meal >= shared.nb_meal)
		printf(FORM_END "[%d] philo %d have finished eating.\n" CLEAR,
			shared->simulation_age, philo->id);
	else
		printf("[%d] someone died! Philo %d is too distressed to eat.\n",
			shared->simulation_age, philo->id);
	pthread_mutex_unlock(shared.outlock);
	return (NULL);
}

void	age_all_philo(t_shared *shared)
{
	int	i;
	t_philo *curent_philo;

	i = 0;
	while (i < nb_philo)
	{
		current_philo = shared->philos[i];
		if (current_philo->hunger > shared->die_time)
			action_die(i, shared);
		else
			curent_philo->hunger ++;
		i ++;
	}
}
void	*hunger_routine(void *shared)
{
	int	i;
	
	wait_init();
	while (shared.dead_philo == 0)
	{
		accurate_sleep(1);
		shared.simulation_age ++;
		age_all_philo(shared);
	}
	return (NULL);
}

void	*death_routine(void	*shared)
{
	int	i;

	wait_init();
	while (shared.dead == 0)
		sleep(TIME_TIC);
	pthread_mutex_lock(shared.outlock);
	i = 0;
	while (shared.philos[i])
	{
		if (shared.philos[i].dead)
			printf(FORM_DIE "[%d] philo %d died.\n" CLEAR);
		i ++;
	}
	return (NULL);
}
