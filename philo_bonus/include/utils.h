/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:23:39 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/02 13:47:08 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H 

// ****************************************************************************
// Functions - ft_atoi.c

/**
@brief Converts the initial portion of the string pointed to by str to an 
		int representation.

@param str String to be converted.
@return Int representation of the initial portion of the string. 
*/
int	ft_atoi(const char *str);

// ****************************************************************************
// Functions - ft_atoi.c

/**
@brief Tests for a decimal digit character.

@param c Character to be tested. 
@return 1 if True, 0 if False.
*/
int	ft_isdigit(int c);

#endif	// UTILS_H
