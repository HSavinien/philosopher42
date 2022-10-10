/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:23:41 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/10 16:45:44 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	action_take_forks(int philo_num, t_shared *shared)
{
	//take first fork
	pthread_mutex_lock(&(shared->forks[philo_num]));
	//say it
	pthread_mutex_lock(&(shared->outlock));
	printf(FORM_FORK ACT_FORK CLEAR, shared->simul_age, philo_num);
	pthread_mutex_unlock(&shared->outlock);
	//take second fork (if last philo, next fork is fork 0)
	pthread_mutex_lock(&(shared->forks[(philo_num + 1) % shared->nb_philo]));
	//say it
	pthread_mutex_lock(&shared->outlock);
	printf(FORM_FORK ACT_FORK CLEAR, shared->simul_age, philo_num);
	pthread_mutex_unlock(&shared->outlock);
}
void	action_eat(int philo_num, t_shared *shared)
{
	//say he's eating
	pthread_mutex_lock(&(shared->outlock));
	printf(FORM_EAT ACT_EAT CLEAR, shared->simul_age, philo_num);
	pthread_mutex_unlock(&(shared->outlock));
	shared->philos[philo_num].hunger = 0;
	shared->philos[philo_num].nb_meal++;
	//sleep eat_time millisecond
	accurate_sleep(shared->eat_time);
	//unlock first fork
	pthread_mutex_unlock(&(shared->forks[philo_num]));
	//unlock second fork
	pthread_mutex_unlock(&(shared->forks[(philo_num + 1) % shared->nb_philo]));
}
void	action_sleep(int philo_num, t_shared *shared)
{
	//say he's sleeping
	pthread_mutex_lock(&(shared->outlock));
	printf(FORM_SLEEP ACT_SLEEP CLEAR, shared->simul_age, philo_num);
	pthread_mutex_unlock(&(shared->outlock));
	//sleep sleep_time second
	accurate_sleep(shared->sleep_time);
}
void	action_think(int philo_num, t_shared *shared)
{
	//say he's thinking
	pthread_mutex_lock(&(shared->outlock));
	printf(FORM_THINK ACT_THINK CLEAR, shared->simul_age, philo_num);
	pthread_mutex_unlock(&(shared->outlock));
}
void	action_die(int philo_num, t_shared *shared)
{
	//increment dead philo counter
	shared->dead_philo ++;
	//set philo->dead as true
	shared->philos[philo_num].dead = 1;
}
