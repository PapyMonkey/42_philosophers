/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:58:07 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/02 22:59:06 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	phi_eat(t_phi *phi)
{
	pthread_mutex_lock(phi->f_left);
	print_action(phi, "has taken a fork");
	pthread_mutex_lock(phi->f_right);
	print_action(phi, "has taken a fork");
	phi->t_last_meal = t_get_mil();
	phi->is_eat = 1;
	printf("Coucou je mange\n");
	print_action(phi, "is eating");
	t_usleep(phi->var->t_eat);
	phi->n_lunch++;
	phi->is_eat = 0;
	pthread_mutex_unlock(phi->f_left);
	pthread_mutex_unlock(phi->f_right);
}

static void	phi_sle(t_phi *phi)
{
	phi->is_sle = 1;
	print_action(phi, "is sleeping");
	t_usleep(phi->var->t_sle);
	phi->is_sle = 0;
}

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
