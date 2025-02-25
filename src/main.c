/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/25 18:02:37 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_general_data	philo;

	philo.philo_amount = 0;
	if (validate_input(argc, argv, &philo))
		return (1);
	philo.philosophers = malloc(sizeof(t_philo) * philo.philo_amount);
	if (philo.philosophers == NULL)
	{
		printf("Error on memory allocation \n");
		return (1);
	}
	printf("philo_amount b4 parse: %d\n", philo.philo_amount);//debug
	init_philosophers(&philo);
	free(philo.philosophers);
	return (0);
}
