/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:01:35 by aguiri            #+#    #+#             */
/*   Updated: 2022/06/23 14:47:28 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(t_phi *phi, char *msg)
{
	if (msg != NULL)
	{
		pthread_mutex_lock(&phi->var->m_printing);
		if (!phi->var->is_dead)
			printf("%zu %d %s\n",
				t_get_mil_start(phi->var),
				phi->serial,
				msg);
		pthread_mutex_unlock(&phi->var->m_printing);
	}
}
