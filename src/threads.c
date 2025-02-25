/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:28:01 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/24 21:41:23 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*function(void *philo_data)
{
	(void)philo_data;
	printf("aaaaaaa\n");  //açoes (comer dormir pensar)
	return (NULL);
}

pthread_t	init_philosopher(void)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, function, NULL);
	pthread_detach(thread);
	return (thread);
}
