/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:00:36 by aguiri            #+#    #+#             */
/*   Updated: 2022/06/22 19:25:05 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	args_check(int argc, char **argv)
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

static void	init_forks(t_var *var)
{
	int	i;

	var->forks = malloc(sizeof(pthread_mutex_t) * var->n_philo);
	if (!var->forks)
		error_put_exit_custom("malloc failed");
	i = -1;
	while (++i < var->n_philo)
		pthread_mutex_init(var->forks + i, NULL);
}

static void	init_philos_ext(t_var *var, t_phi *phi, int i)
{
	phi->n_lunch = 0;
	phi->n_lunch_max = var->n_lunch;
	phi->t_die = var->t_die;
	phi->t_eat = var->t_eat;
	phi->t_sle = var->t_sle;
	phi->i = var->test;
	if (i == 0)
	{
		phi->f_left = var->forks + (var->n_philo - 1);
		phi->f_right = var->forks + i;
	}
	else
	{
		phi->f_left = var->forks + i - 1;
		phi->f_right = var->forks + i;
	}
	pthread_create(&(phi->thread), NULL, phi_core, phi);
}

static void	init_philos(t_var *var)
{
	int	i;

	var->phi = malloc(sizeof(t_phi) * var->n_philo);
	if (!var->phi)
		error_put_exit_custom("malloc failed");
	i = -1;
	while (++i < var->n_philo)
		init_philos_ext(var, var->phi + i, i);
	i = -1;
	while (++i < var->n_philo)
		pthread_join((var->phi + i)->thread, NULL);
}

void	init_all(t_var *var, int argc, char **argv)
{
	int	i;

	args_check(argc, argv);
	var->n_philo = ft_atoi(argv[1]);
	var->t_die = ft_atoi(argv[2]);
	var->t_eat = ft_atoi(argv[3]);
	var->t_sle = ft_atoi(argv[4]);
	if (argc == 6)
		var->n_lunch = ft_atoi(argv[5]);
	else
		var->n_lunch = 0;
	i = 0;
	var->test = &i;
	init_forks(var);
	init_philos(var);
}
