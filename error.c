/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:15:00 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/10 20:10:12 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	error_args(int err_code)
{
	printf("Error \033[1m%d\033[0m : arguments\nusage : "
		"philo <nb_philo> <die_time> <eat_time> <sleep_time> [max_meal]\n",
		-err_code);
	return (-(err_code));
}

int	error_msg(char *msg, int err_code, t_shared *shared)
{
	printf("Error %d\n%s\n", -err_code, msg);
	if (shared)
		shared->error_code = err_code;
	return (-err_code);
}
