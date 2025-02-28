/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:28:01 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/28 19:12:45 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*cycle(void *philo_data)
{
	t_philo	*philo;

	philo = (t_philo *)philo_data;
	philo->eat_count = 0;
	while (should_continue_eating(philo))
	{
		eating(philo);
		philo->eat_count++;
		sleeping(philo, philo->data);
		thinking(philo, philo->data);
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
		printf("Creating Philosopher: %d\n", data->philosophers[i].philo_id);
		if (pthread_create(&threads[i], NULL, cycle, &data->philosophers[i]))
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
