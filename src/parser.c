/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:52:26 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/22 17:07:15 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	handle_argc_error(int arg_count)
{
	if (arg_count > 0 && arg_count < 6)
	{
		printf("not enough arguments :( (expected 6)\n");
		return (1);
	}
	if (arg_count > 6)
	{
		printf("too many arguments :( (expected 6)\n");
		return (1);
	}
}

void	validate_input(int argc, char **argv)
{
	handle_argc_error(argc);
}

//	./philo number_of_philos time_to_die time_to_eat time_to_sleep
//		[number_of_times_must_eat]