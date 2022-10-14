/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:37:58 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/14 18:20:00 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_shared	shared;

	shared = do_parsing(ac, av);
	if (shared.error_code)
		return (error_args(shared.error_code));
	if (init_values(&shared))
		return (-shared.error_code);
	pthread_mutex_lock(&(shared.init_lock));
	if (create_all_philo(& shared))
		return (-shared.error_code);
	if (init_supervisor(&shared))
		return (-shared.error_code);
	pthread_mutex_unlock(&(shared.init_lock));
	pthread_join(shared.death, NULL);
	return (0);
}
