/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:17:15 by aguiri            #+#    #+#             */
/*   Updated: 2022/06/22 19:07:16 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <pthread.h>

# include "utils.h"
# include "structures.h"

// ****************************************************************************
// Functions - error.c

/**
 * @brief	Printf "Error\n" and exit the program.
 */
void	error_put_exit(void);

/**
 * @brief	Printf "Error:" followed by a custom message and exit the program.
 *
 * @param	msg Custom message.
 */
void	error_put_exit_custom(char *msg);

// ****************************************************************************
// Functions - init.c

/**
 * @brief	Init the s_var structures and iniate the program.
 *
 * @param	var Variable that will contain all the other useful ones.
 * @param	argc Number of arguments to the main function.
 * @param	argv Arguments of the main function.
 */
void	init_all(t_var *var, int argc, char **argv);

// ****************************************************************************
// Functions - philo.c

/**
 * @brief [TODO:description]
 *
 * @param arg [TODO:description]
 */
void	*phi_core(void *arg);

#endif		// ifndef PHILOSOPHERS_H
