/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:28:04 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/04 01:31:03 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_args(int argc, char **argv)
{
	int		i;
	char	*tmp;

	if (argc < 5 || 6 < argc)
		error_put_exit_custom("wrong number of arguments");
	if (ft_atoi(argv[1]) < 1)
		error_put_exit_custom("wrong number of philosophers");
	i = 1;
	while (i < argc)
	{
		tmp = argv[i++];
		while (*tmp)
			if (ft_isdigit(*tmp++) == 0)
				error_put_exit_custom("non numeric argument(s)");
	}
}

static int	check_eat(t_var *var)
{
	size_t	i;

	if (var->n_lunch_max == 0)
		return (0);
	i = -1;
	while (++i < var->n_philo)
	{
		if (var->phi[i].n_lunch > var->n_lunch_max)
			return (1);
	}
	return (0);
}

void	check_dead(t_var *var)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < var->n_philo)
		{
			if (var->phi[i].is_eat)
				continue ;
			sem_wait(var->s_diying);
			if (t_get_mil() >= var->t_die + var->phi[i].t_last_meal)
			{
				print_action(&(var->phi[i]), "died");
				var->is_dead = 1;
				return ;
			}
			sem_post(var->s_diying);
		}
		if (check_eat(var))
			break ;
	}
}
