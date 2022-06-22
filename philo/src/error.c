/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:07:19 by aguiri            #+#    #+#             */
/*   Updated: 2022/06/21 16:16:01 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error_put_exit(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}

void	error_put_exit_custom(char *msg)
{
	printf("Error: %s\n", msg);
	exit(EXIT_FAILURE);
}
