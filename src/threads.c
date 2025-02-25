/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:28:01 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/25 11:08:14 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*function(void *philo_data)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo_data;
	printf("%d is thinkingggggg", philosopher->philo_id);
	return (NULL);
}

pthread_t	*init_philosophers(t_general_data *data)
{
	pthread_t	*threads;
	int			i;

	i = 0;
	threads = malloc(sizeof(pthread_t) * data->philo_amount);
	if (threads == NULL)
		return (NULL);
	while (i <= data->philo_amount)
	{
		data->philosophers[i].philo_id = i + 1;
		data->philosophers[i].data = data;
		if (pthread_create(&threads[i], NULL, function,
				(void *)&data->philosophers[i]) != 0)
		{
			printf("errorrrrrrr");
			free(threads);
			return (NULL);
		}
		i++;
	}
	return (threads);
}
