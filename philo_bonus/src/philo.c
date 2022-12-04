/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:58:07 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 00:59:33 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
@brief Routine to make the philosophers eat.

@param phi Philosophers taking the action.
*/
static void	phi_eat(t_phi *phi)
{
	sem_wait(phi->var->s_forks);
	print_action(phi, "has taken a fork");
	sem_wait(phi->var->s_forks);
	print_action(phi, "has taken a fork");
	phi->t_last_meal = t_get_mil();
	phi->is_eat = 1;
	print_action(phi, "is eating");
	t_usleep(phi->var->t_eat);
	phi->n_lunch++;
	phi->is_eat = 0;
	sem_post(phi->var->s_forks);
	sem_post(phi->var->s_forks);
}

/**
@brief Routine to make the philosophers sleep.

@param phi Philosophers taking the action.
*/
static void	phi_sle(t_phi *phi)
{
	phi->is_sle = 1;
	print_action(phi, "is sleeping");
	t_usleep(phi->var->t_sle);
	phi->is_sle = 0;
}

/**
@brief Routine to make the philosophers think.

@param phi Philosophers taking the action.
*/
static void	phi_thi(t_phi *phi)
{
	print_action(phi, "is thinking");
}

void	*phi_core(void *arg)
{
	t_phi	*phi;

	phi = (t_phi *)arg;
	if (!(phi->serial % 2))
		t_usleep(10);
	while (!phi->var->is_dead)
	{
		phi_eat(phi);
		phi_sle(phi);
		phi_thi(phi);
	}
	return (NULL);
}
