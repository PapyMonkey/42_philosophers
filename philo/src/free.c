/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:27:55 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/02 22:51:06 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_var *var)
{
	int	i;

	i = -1;
	while (++i < var->n_philo)
		pthread_mutex_destroy(var->forks + i);
	pthread_mutex_destroy(&var->m_printing);
	pthread_mutex_destroy(&var->m_diying);
	free(var->phi);
	free(var->forks);
	free(var);
}
