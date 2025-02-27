/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:28:01 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/27 12:09:13 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*philo_loop(void *philo_data)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo_data;
	while (1)
	{
		is_thinking(philosopher, philosopher->data);
		is_eating(philosopher);
		is_sleeping(philosopher, philosopher->data);
	}
	return (NULL);
}

static void	union_threads(pthread_t *threads, t_general_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_amount)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

pthread_t	*init_philosophers(t_general_data *data)
{
	pthread_t	*threads;
	int			i;

	i = 0;
	threads = malloc(sizeof(pthread_t) * data->philo_amount);
	if (threads == NULL)
		return (NULL);
	while (i < (data->philo_amount))
	{
		data->philosophers[i].philo_id = i + 1;
		data->philosophers[i].data = data;
		printf("Creating thread for Philosopher %d\n", data->philosophers[i].philo_id);
		if (pthread_create(&threads[i], NULL, philo_loop, (void *)&data->philosophers[i]) != 0)
		{
			printf("error creating the thread");
			free(threads);
			return (NULL);
		}
		i++;
	}
	union_threads(threads, data);
	return (threads);
}
