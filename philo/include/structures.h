/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:23:39 by aguiri            #+#    #+#             */
/*   Updated: 2022/06/22 19:24:31 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <pthread.h>

// ****************************************************************************
// Structures

/**
 * struct s_phi - Contains all philosophers related variables.
 */
typedef struct s_phi {
	int				n_lunch;
	int				n_lunch_max;
	int				t_die;
	int				t_eat;
	int				t_sle;
	pthread_t		thread;
	pthread_mutex_t	*f_left;
	pthread_mutex_t	*f_right;
	int				*i;
}				t_phi;

/**
 * struct s_var - Contains all the useful variables, used in all functions.
 */
typedef struct s_var {
	int				n_philo;
	int				n_lunch;
	int				t_die;
	int				t_eat;
	int				t_sle;
	t_phi			*phi;
	pthread_mutex_t	*forks;
	int				*test;
}					t_var;

#endif		// ifndef STRUCTURES_H
