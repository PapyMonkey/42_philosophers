/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:17:15 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/02 22:46:13 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// ****************************************************************************
// Includes

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# include <pthread.h>

# include "utils.h"
# include "structures.h"

// ****************************************************************************
// Functions - check.c

/**
@brief Checks arguments given in program input.

@param	argc Number of arguments to the main function.
@param	argv Arguments of the main function.
*/
void			check_args(int argc, char **argv);

/**
@brief Checks if one of the philosophers died.

@param var Variable that will contain all the other useful ones.
*/
void			check_dead(t_var *var);

// ****************************************************************************
// Functions - error.c

/**
@brief	Printf "Error\n" and exit the program.

*/
void			error_put_exit(void);

/**
@brief Printf "Error:" followed by a custom message and exit the program.

@param msg Custom message.
*/
void			error_put_exit_custom(char *msg);

// ****************************************************************************
// Functions - free.c

/**
@brief Frees the entire global structure.

@param var Structure containing all the other useful ones.
*/
void			free_all(t_var *var);

// ****************************************************************************
// Functions - init.c

/**
@brief Init the s_var structures and iniate the program.

@param var Variable that will contain all the other useful ones.
@param argc Number of arguments to the main function.
@param argv Arguments of the main function.
*/
void			init_all(t_var *var, int argc, char **argv);

// ****************************************************************************
// Functions - main.c

/**
@brief Stop the simulation and call the free functions.

@param var Variable that will contain all the other useful ones.
*/
void			stop_simulation(t_var *var);

// ****************************************************************************
// Functions - philo.c

/**
@brief [TODO:description]

@param arg [TODO:description]
*/
void			*phi_core(void *arg);

// ****************************************************************************
// Functions - output.c

/**
@brief Print a given message with the corresponding timestamp.

@param phi Philosophers taking the action.
@param msg Message associated.
*/
void			print_action(t_phi *phi, char *msg);

// ****************************************************************************
// Functions - time.c

/**
@brief Get the current time, used as a reference later.

@return Time, from 01/01/1970.
*/
struct timeval	t_get_now(void);

/**
@brief Convert a time in milliseconds.

@param time Time to be converted.
@return Time in milliseconds.
*/
size_t			t_convert_mil(struct timeval time);

/**
@brief Get the current time, in milliseconds.

@return Elapsed time from reference, in milliseconds.
*/
size_t			t_get_mil(void);

/**
@brief Get the elapsed time from reference, in milliseconds.

@param var Variable that will contain all the other useful ones.
@return Elapsed time from reference, in milliseconds.
*/
size_t			t_get_mil_start(t_var *var);

/**
@brief Use the function usleep to freeze the programm for a given time.

@param usec	Time, in milliseconds.
 */
void			t_usleep(t_phi *phi, size_t	usec);

#endif	//PHILOSOPHERS_H
