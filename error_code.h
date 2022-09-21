/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:45:02 by tmongell          #+#    #+#             */
/*   Updated: 2022/09/21 16:39:27 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* list of error code and associated macros.
 * it will clarifie the code, 
 * and you can look into this file in case of problem.
 * I use only power of two, so I can use (ERR_ONE | ERR_TWO) 
 * to pass two error code at once.
 * it's useless here, but let's take good habits...
 */

//args error
#define ERR_ARG_COUNT	1	//to many or not enough arguments
#define ERR_ARG_NAN		2	//one argument contain non digit numbers
#define ERR_ARG_NEG		4	//one argument is a negative number
#define ERR_ARG_NULL	8	//one argument has a value of 0;

//tech error
#define ERR_MALLOC		16	//a malloc call failed to alocate memory
