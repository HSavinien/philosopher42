/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:11:46 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/10 20:00:47 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	wait_init(t_shared *shared)
{
	pthread_mutex_lock(&(shared->init_lock));
	pthread_mutex_unlock(&(shared->init_lock));
}

//function that compare two time, as returned from get_time_of_day.
//return : 
//	an integer greater than 0 if time 1 is after time 2 ; 
//	an interger smaller than 0 if time 1 is before time 2;
//	zero if the two time are the same;
int	timecmp(const struct timeval time1, const struct timeval time2)
{
	if (time1.tv_sec != time2.tv_sec)
		return (time1.tv_sec - time2.tv_sec);
	return (time1.tv_usec - time2.tv_usec);
}

struct timeval	get_wakeup_date(struct timeval start, int duration)
{
	struct timeval	wakeup;

	duration *= 1000; //convert ms to us
	if (start.tv_usec + duration >= 1000000)
		wakeup.tv_sec = (duration / 1000000);
	wakeup.tv_usec += (duration % 1000000);
	return (wakeup);
}

//this function aim the present a more accurate alternative 
//to the native sleep/usleep function
void	accurate_sleep(int duration)
{
	struct timeval	start_time;
	struct timeval	now_time;
	struct timeval	end_time;
	//get curent time.
	gettimeofday(&start_time, NULL);
	//calculate time to end of sleep
	end_time = get_wakeup_date(start_time, duration);
	//while current time < goal_time (funcion time_comp)
	while (!gettimeofday(&now_time, NULL) && timecmp(now_time, end_time) < 0)
		usleep(TIME_TIC);
}
