/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:04:36 by tmongell          #+#    #+#             */
/*   Updated: 2022/09/24 15:31:28 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_philo create_one_philo(t_param param, int index, int *forks)
{

}

t_philo	*create_all_philo(t_param param, int *forks)
{
	t_philo	*philo_lst;
	int		i;

	i = 0;
	philo_lst = malloc(sizeof(t_philo) * parameters.nb_philo);
	if (!philo_lst)
		error("unexpected malloc error on initialisation", ERR_MALLOC);
	while (i < param.nb_philo)
	{
		philo_lst[i] = create_one_philo(param, i, forks);
		i ++;
	}
	return (philo_lst)
}
