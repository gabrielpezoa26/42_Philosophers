/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/23 13:16:22 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	validate_input(argc, argv);
	return (0);
}

//	./philo number_of_philos time_to_die time_to_eat time_to_sleep
//		[number_of_times_must_eat]