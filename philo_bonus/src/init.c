/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:00:36 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 01:30:28 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
@brief Malloc and initiate a semaphore with a given name and value.

@param name Name of the new semaphore.
@param value Int value to be set.
@return Pointer to the new created semaphore.
*/
static sem_t	*init_semaphore(char *name, unsigned int value)
{
	sem_t	*sem_out;

	sem_unlink(name);
	sem_out = sem_open(name, O_CREAT, 0666, value);
	if (sem_out == SEM_FAILED)
		error_put_exit();
	return (sem_out);
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
	var->s_diying = init_semaphore("s_dying", 1);
	var->s_printing = init_semaphore("s_printing", 1);
	var->s_forks = init_semaphore("s_forks", var->n_philo);
	init_philos(var);
	check_dead(var);
}
