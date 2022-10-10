/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_main_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:46:10 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/10 18:11:10 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo_routine(void *args)
{
	t_shared	*shared;
	t_philo		*philo;
	int			last_meal_eaten;

	shared = ((t_thread_arg*) args)->shared;
	philo = ((t_thread_arg*) args)->philo;
	free (args);
	wait_init(shared);
	last_meal_eaten = 0;
	while (!last_meal_eaten && !shared->dead_philo)
	{
		action_take_forks(philo->id, shared);
		action_eat(philo->id, shared);//eat also drop forks
		action_sleep(philo->id, shared);
		action_think(philo->id, shared);
		if (shared->nb_meal > 0 && philo->nb_meal >= shared->nb_meal)
			last_meal_eaten = 1;
	}
	pthread_mutex_lock(&(shared->outlock));
	if (shared->nb_meal > 0 && philo->nb_meal >= shared->nb_meal)
		printf(FORM_END ACT_END CLEAR, shared->simul_age, philo->id);
	else if (!philo->dead)
		printf(ACT_DISTRESS, shared->simul_age, philo->id);
	pthread_mutex_unlock(&(shared->outlock));
	return (NULL);
}

void	age_all_philo(t_shared *shared)
{
	int	i;
	t_philo *current_philo;

	i = 0;
	while (i < shared->nb_philo)
	{
		current_philo = &(shared->philos[i]);
		if (current_philo->hunger > shared->die_time)
			action_die(i, shared);
		else
			current_philo->hunger ++;
		i ++;
	}
}
void	*hunger_routine(void *arg)
{
	t_shared	*shared;

	shared = arg;
	wait_init(shared);
	while (shared->dead_philo == 0)
	{
		accurate_sleep(1);
		shared->simul_age ++;
		age_all_philo(shared);
	}
	return (NULL);
}

void	*death_routine(void	*arg)
{
	t_shared	*shared;
	int	i;

	shared = arg;
	wait_init(shared);
	while (shared->dead_philo == 0)
		usleep(500);
	pthread_mutex_lock(&(shared->outlock));//volutarily never unlocked
	i = 0;
	while (i < shared->nb_philo)
	{
		if (shared->philos[i].dead)
			printf(FORM_DIE ACT_DIE CLEAR, shared->simul_age, i);
		i ++;
	}
	return (NULL);
}
