/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:18:12 by aguiri            #+#    #+#             */
/*   Updated: 2022/06/23 14:01:14 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

struct timeval	t_get_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
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

void	t_usleep(size_t	usec)
{
	size_t	tmp;

	tmp = t_get_mil();
	while (usec > t_get_mil() - tmp)
		usleep(usec * 1000);
}
