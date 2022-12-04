/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:01:35 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 01:30:53 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(t_phi *phi, char *msg)
{
	if (msg != NULL)
	{
		sem_wait(phi->var->s_printing);
		if (!phi->var->is_dead)
			printf("%zu %d %s\n",
				t_get_mil_start(phi->var),
				phi->serial,
				msg);
		sem_post(phi->var->s_printing);
	}
}
