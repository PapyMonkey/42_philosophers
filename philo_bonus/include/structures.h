/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:23:39 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 00:38:28 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

// ****************************************************************************
// Structures

/**
struct s_phi - Contains all philosophers related variables.
*/
typedef struct s_phi {
	struct s_var	*var;

	int				n_lunch;
	int				serial;
	int				is_eat;
	int				is_sle;
	size_t			t_last_meal;

	pthread_t		thread;
}				t_phi;

/**
struct s_var - Contains all the useful variables, used in all functions.
*/
typedef struct s_var {
	int				n_philo;
	int				n_lunch_max;
	int				t_die;
	int				t_eat;
	int				t_sle;

	int				is_dead;
	sem_t			*s_diying;
	sem_t			*s_printing;
	sem_t			*s_forks;

	t_phi			*phi;

	struct timeval	time;
}					t_var;

#endif	// STRUCTURES_H
