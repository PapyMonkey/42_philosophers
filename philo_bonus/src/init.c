/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:00:36 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/02 22:55:48 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
@brief Malloc and initiate all forks mutex related.

@param var Structure containing all the other useful ones.
*/
static void	init_forks(t_var *var)
{
	int	i;

	var->forks = malloc(sizeof(pthread_mutex_t) * var->n_philo);
	if (!var->forks)
		error_put_exit_custom("var.forks malloc failed");
	i = -1;
	while (++i < var->n_philo)
		pthread_mutex_init(var->forks + i, NULL);
}

/**
@brief Extension of philos_ext. Malloc and initiate all the philosophers
		related variables.

@param var Structure containing all the other useful ones.
@param phi Philosophers taking the action.
@param i ID of philosopher.
*/
static void	init_philos_ext(t_var *var, t_phi *phi, int i)
{
	phi->var = var;
	phi->n_lunch = 0;
	phi->serial = i + 1;
	phi->is_eat = 0;
	phi->is_sle = 0;
	phi->t_last_meal = t_convert_mil(var->time);
	if (i == 0)
	{
		phi->f_left = var->forks + (var->n_philo - 1);
		phi->f_right = var->forks + i;
	}
	else
	{
		phi->f_left = var->forks + i - 1;
		phi->f_right = var->forks + i;
	}
	pthread_create(&(phi->thread), NULL, &phi_core, (void *)phi);
}

/**
@brief Malloc and initiate all the philosophers related variables.

@param var Structure containing all the other useful ones.
*/
static void	init_philos(t_var *var)
{
	int	i;

	var->phi = malloc(sizeof(t_phi) * var->n_philo);
	if (!var->phi)
		error_put_exit_custom("var->phi malloc failed");
	i = -1;
	while (++i < var->n_philo)
		init_philos_ext(var, var->phi + i, i);
}

void	init_all(t_var *var, int argc, char **argv)
{
	int	i;

	check_args(argc, argv);
	var->n_philo = ft_atoi(argv[1]);
	var->t_die = ft_atoi(argv[2]);
	var->t_eat = ft_atoi(argv[3]);
	var->t_sle = ft_atoi(argv[4]);
	if (argc == 6)
		var->n_lunch_max = ft_atoi(argv[5]);
	else
		var->n_lunch_max = 0;
	i = 0;
	var->is_dead = 0;
	var->time = t_get_now();
	pthread_mutex_init(&(var->m_diying), NULL);
	pthread_mutex_init(&(var->m_printing), NULL);
	init_forks(var);
	init_philos(var);
	check_dead(var);
}
