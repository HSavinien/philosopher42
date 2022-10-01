/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:20:51 by tmongell          #+#    #+#             */
/*   Updated: 2022/09/28 15:58:00 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	get_arg(char *arg_str)
{
	int arg_value;
	int	i;

	i = 0;
	if (arg_str[i] == '-' || arg_str[i] == '+')
		i ++;
	while (arg_str[i])
	{
		if (!ft_isdigit(arg_str[i]))
			return (ERR_ARG_NAN);
		i ++;
	}
	arg_value = ft_atoi(arg_str);
	if (arg_value < 0)
		return (ERR_ARG_NEG);
	if (arg_value == 0)
		return (ERR_ARG_NULL);
	return (arg_value);
}

t_shared error_argc(void)
{
	t_shared ret;
	ret.error_code = ERR_ARG_COUNT;
	return (ret);
}

void	check_error_argv(t_shared *param)
{
	if (param->nb_philo < 0)
		param->error_code = param->nb_philo;
	if (param->nb_philo > MAX_PHILO)
		param->error_code = ERR_MANY_PHILO;
	if (param->die_time < 0)
		param->error_code = param->die_time;
	if (param->eat_time < 0)
		param->error_code= param->eat_time;
	if (param->sleep_time < 0)
		param->error_code = param->sleep_time;
	if (param->nb_meal < 0)
		param->error_code = param->nb_meal;
}

//this function check that the args are correct, 
//and store them in a struct for easy use.
t_shared	do_parsing(int ac, char **av)
{
	t_shared	param;

	if (ac < 5 || ac > 6)
		return (error_argc());
	param.nb_philo = get_arg(av[1]);
	param.die_time = get_arg(av[2]);
	param.eat_time = get_arg(av[3]);
	param.sleep_time = get_arg(av[4]);
	if (ac == 6)
		param.nb_meal = get_arg(av[5]);
	else
		param.nb_meal = 0;
	param.dead_philo = 0;
	param.error_code = 0;
		check_error_argv(&param);
	return (param);
}
