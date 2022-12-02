/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:18:12 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/02 18:11:18 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

struct timeval	t_get_now(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		error_put_exit();
	return (time);
}

size_t	t_convert_mil(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

size_t	t_get_mil(void)
{
	return (t_convert_mil(t_get_now()));
}

size_t	t_get_mil_start(t_var *var)
{
	return (t_get_mil() - t_convert_mil(var->time));
}

void	t_usleep(t_phi *phi, size_t	t_to_wait)
{
	size_t	t_start;

	t_start = t_get_mil();
	while (t_to_wait + t_start > t_get_mil())
		usleep(t_to_wait * 10);
}
