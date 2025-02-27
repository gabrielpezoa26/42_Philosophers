/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:54:11 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/27 17:17:06 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void is_eating(t_philo *bro, t_general_data *enviromment)
{
	struct timeval	current_time;
	long			timestamp_ms;

	gettimeofday(&current_time, NULL);
	timestamp_ms = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	pthread_mutex_lock(bro->left_fork);
	printf("%ld %d has taken a fork", timestamp_ms, bro->philo_id);
	pthread_mutex_lock(bro->right_fork);
	printf("%ld %d has taken a fork", timestamp_ms, bro->philo_id);
	
	printf("%d started eating", bro->philo_id);
	while (gettimeofday(&current_time, NULL) < (enviromment->time_to_eat))
		printf("%d is eating", bro->philo_id);
	pthread_mutex_unlock(bro->left_fork);
	pthread_mutex_unlock(bro->right_fork);
	
}

// 332323 7 has taken a fork
// 332325 7 is eating
// 332328 7 is sleeping
// 332334 7 is thinking
// 332348 7 died

void is_thinking(t_philo *bro, t_general_data *enviromment)
{
	int i;

	(void)bro;
	i = 0;
	while(i < (enviromment->time_to_sleep))
	{
		printf("bro is thinkinggg\n");
		i++;
	}
	usleep(100000);
}

void is_sleeping(t_philo *bro, t_general_data *enviromment)
{
	struct timeval	current_time;
	long			time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	printf("%ld %d is sleeping\n", time, bro->philo_id);
	usleep(enviromment->time_to_sleep * 1000);
}
