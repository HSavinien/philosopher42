/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:11:46 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/04 18:43:46 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	wait_init(void)
{
	pthread_mutex_lock(shared->init_lock);
	pthread_mutex_unlock(shared->init_lock);
}

//convert the struct we got from gettimeofday into an int.
//this int is the number of us since the start of the simulation.
int	time_to_int(struct timeval basetime)
{

}

//basic sleep (or usleep) function is not accurate :
//usleep(1000) will sleep AT LEAST 1000 micro second, but it can be more
//this function aim to correct that.
//the duration is in ms, not in micro seconds.
void	accurate_sleep(int duration)
{
	int		awakening_time;
	t_time	start_time;
	
	
	//while current time != awakening date
		//sleep (very short time)
}
