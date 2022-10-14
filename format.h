/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:36:44 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/14 18:15:45 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * this file colect a list of text formating macros.
 * the main intent of this file is to give a specific format to each actions
 */

#ifndef FORMAT_H
# define FORMAT_H


#ifndef STRICT_SYNTAX
//general
#  define CLEAR "\033[0m"

//actions format
#  define FORM_FORK "\033[33m"	//yellow
#  define FORM_EAT "\033[32m"	//green
#  define FORM_SLEEP "\033[1;2m"	//grayish
#  define FORM_THINK "\033[1;2m"	//grayish
#  define FORM_DIE "\033[31m"	//red
#  define FORM_END "\033[1;4;32m"// bald, underlined, green

//log msg
#  define ACT_FORK	"[%d] philo %d has taken a fork\n"
#  define ACT_EAT	"[%d] philo %d is eating\n"
#  define ACT_SLEEP	"[%d] philo %d is sleeping\n"
#  define ACT_THINK	"[%d] philo %d is thinking\n"
#  define ACT_DIE	"[%d] philo %d died\n"

# else
//general
#  define CLEAR

//actions format
#  define FORM_FORK
#  define FORM_EAT
#  define FORM_SLEEP
#  define FORM_THINK
#  define FORM_DIE
#  define FORM_END

//log msg
#  define ACT_FORK	"%d %d has taken a fork\n"
#  define ACT_EAT	"%d %d is eating\n"
#  define ACT_SLEEP	"%d %d is sleeping\n"
#  define ACT_THINK	"%d %d is thinking\n"
#  define ACT_DIE	"%d %d died\n"

# endif
#endif
