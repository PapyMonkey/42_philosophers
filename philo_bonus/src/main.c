/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:16:37 by aguiri            #+#    #+#             */
/*   Updated: 2022/12/02 23:19:48 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	if (!var)
		error_put_exit_custom("var malloc failed");
	init_all(var, argc, argv);
	free_all(var);
	return (0);
}
