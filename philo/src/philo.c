/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:58:07 by aguiri            #+#    #+#             */
/*   Updated: 2022/06/22 19:44:16 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*phi_core(void *arg)
{
	t_phi	*phi;

	phi = (t_phi *)arg;
	while (*(phi->i) < 500)
	{
		pthread_mutex_lock(phi->f_left);
		pthread_mutex_lock(phi->f_right);
		printf("Processus : %p\t", phi->thread);
		printf("i : %d\n", *(phi->i));
		(*(phi->i))++;
		pthread_mutex_unlock(phi->f_left);
		pthread_mutex_unlock(phi->f_right);
		printf("cc\n");
	}
	return (NULL);
}
