/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:45:02 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/10 19:52:40 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODE_H
# define ERROR_CODE_H
/* list of error code and associated macros.
 * it will clarifie the code, 
 * and you can look into this file in case of problem.
 * I use only power of two, so I can use (ERR_ONE | ERR_TWO) 
 * to pass two error code at once.
 * it's useless here, but let's take good habits...
 */

//args error
# define ERR_ARG_COUNT	-1	//to many or not enough arguments
# define ERR_ARG_NAN	-2	//one argument contain non digit numbers
# define ERR_ARG_NEG	-4	//one argument is a negative number
# define ERR_ARG_NULL	-8	//one argument has a value of 0
# define ERR_MANY_PHILO	-16	//more than [MAX_PHILO] (=200) philosophers

//tech error
# define ERR_MALLOC		-32	//a malloc call failed to alocate memory
# define ERR_MUTEX_INIT	-64	//a mutex init failed
# define ERR_CREATE		-128 //could not create a thread;

#endif
