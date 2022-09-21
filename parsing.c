/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:20:51 by tmongell          #+#    #+#             */
/*   Updated: 2022/09/21 15:57:23 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	get_arg(char *arg_str)
{
	int arg_value;
	int	i;

	//check forbiden char
	while (arg_str[i])
	{
		if (!ft_isdigit(arg_str[i]))
			error("all argument must be number", ERR_ARG_NAN);
	}
	arg_value = ft_atoi(arg_str);
	//check negative numbers
	if (arg_value < 0)
		error("all arguments must be positive numbers", ERR_ARG_NEG);
	//check null numbers
	if (arg_value == 0)
		error("0 make no sense... Please think before you type", ERR_ARG_NULL);
	return (arg_value);
}

//this function check that the args are correct, 
//and store them in a struct for easy use.
t_param	do_parsing(int ac, char **av)
{
	t_param	param;

	if (ac < 5 || ac > 6)
		error_arg(av[0]);
	param.nb_philo = get_arg(av[1]);
	param.die_time = get_arg(av[2]);
	param.eat_time = get_arg(av[3]);
	param.sleep_time = get_arg(av[4]);
	if (ac == 6)
		param.nb_meal = get_arg(av[5]);
	else
		param.nb_meal = 0;
	return (param);
}
