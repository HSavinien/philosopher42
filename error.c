/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:15:00 by tmongell          #+#    #+#             */
/*   Updated: 2022/09/21 15:58:46 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

error_arg(char *prgm)
{
	printf("Error : arguments\nusage : %s <nb_philo> <time_to_die> <time_to_eat>
		<time_to_sleep> [number_of_meal_per_philo]", prgm);
	exit (ERR_ARG_COUNT);
}

error(char *msg, int err_code)
{
	printf("Error : %s\n", msg);
	exit(err_code);
}
