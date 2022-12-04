/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:27:55 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 01:30:43 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_var *var)
{
	int	i;

	t_usleep(100);
	i = -1;
	sem_unlink("diying");
	sem_close(var->s_diying);
	sem_unlink("printing");
	sem_close(var->s_printing);
	sem_unlink("forks");
	sem_close(var->s_forks);
	free(var->phi);
	free(var);
}
