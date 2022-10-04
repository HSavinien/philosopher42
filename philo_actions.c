/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:23:41 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/04 14:27:17 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	action_take_forks(int philo_num, t_shared *shared)
{
	//take first fork
	pthread_mutex_lock(shared->forks[philo_num]);
	//say it
	pthread_mutex_lock(shared.outlock);
	printf("[%d] philo %d has taken a fork\n", shared->simul_age, philo_num);
	pthread_mutex_unlock(shared.outlock);
	//take second fork (if last philo, next fork is fork 0)
	pthread_mutex_lock(shared->forks[(philo_num + 1) % shared->nb_philo]);
	//say it
	pthread_mutex_lock(shared.outlock);
	printf("[%d] philo %d has taken a fork\n", shared->simul_age, philo_num);
	pthread_mutex_unlock(shared.outlock);
}
void	action_eat(int philo_num, t_shared *shared)
{
	//say he's eating
	pthread_mutex_lock(shared.outlock);
	printf("[%d] philo %d is eating\n", shared->simul_age, philo_num);
	pthread_mutex_unlock(shared.outlock);
	shared->philos[philo_num].hunger = 0;
	shared->philos[philo_num].nb_meal++
	//sleep eat_time millisecond
	accurate_sleep(shared->eat_time);
	//unlock first fork
	pthread_mutex_unlock(shared->forks[philo_num]);
	//unlock second fork
	pthread_mutex_unlock(shared->forks[(philo_num + 1) % shared->nb_philo]);
}
void	action_sleep(int philo_num, t_shared *shared)
{
	//say he's sleeping
	pthread_mutex_lock(shared.outlock);
	printf("[%d] philo %d is sleeping\n", shared->simul_age, philo_num);
	pthread_mutex_unlock(shared.outlock);
	//sleep sleep_time second
	accurate_sleep(sleep_time)
}
void	action_think(int philo_num, t_shared *shared)
{
	//say he's thinking
	pthread_mutex_lock(shared.outlock);
	printf("[%d] philo %d is thinking\n", shared->simul_age, philo_num);
	pthread_mutex_unlock(shared.outlock);
}
void	action_die(int philo_num, t_shared *shared)
{
	//increment dead philo counter
	shared->dead_philo ++;
	//set philo->dead as true
	shared->philos[philo_num]->dead = 1;
}


//first fork is nb philo_nb
//second fork is nb (philo_nb + 1) % nb_philo

//in log, first philo is nb1. so use philo.id + 1 rather than philo.id
