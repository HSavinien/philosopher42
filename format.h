/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:36:44 by tmongell          #+#    #+#             */
/*   Updated: 2022/10/01 20:22:55 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * this file colect a list of text formating macros.
 * the main intent of this file is to give a specific format to each actions
 */

#ifndef FORMAT_H
# define FORMAT_H

//general
# define CLEAR "\033[0m"

//actions format
# define FORM_FORK "\033[33m"	//yellow
# define FORM_EAT "\033[32m"	//green
# define FORM_SLEEP "\033[1;2m"	//grayish
# define FORM_THINK "\033[1;2m"	//grayish
# define FORM_DIE "\033[31m"	//red
# define FORM_END "\033[1;4;32m"// bald, underlined, green

#define FORMAT_H
