/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:23:39 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/02 13:47:23 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <sys/time.h>
# include <pthread.h>

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
	pthread_mutex_t	*f_left;
	pthread_mutex_t	*f_right;
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
	pthread_mutex_t	m_diying;
	pthread_mutex_t	m_printing;

	t_phi			*phi;
	pthread_mutex_t	*forks;

	struct timeval	time;
}					t_var;

#endif	// STRUCTURES_H
