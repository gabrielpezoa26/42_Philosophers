/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:54:11 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/28 19:06:30 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	pick_forks(t_philo *bro)
{
	struct timeval	current_time;
	long			timestamp;

	gettimeofday(&current_time, NULL);
	timestamp = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	pthread_mutex_lock(bro->left_fork);
	printf("%ld %d has taken a fork\n", timestamp, bro->philo_id);
	gettimeofday(&current_time, NULL);
	timestamp = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	if (pthread_mutex_lock(bro->right_fork) != 0)
	{
		pthread_mutex_unlock(bro->left_fork);
		return ;
	}
	printf("%ld %d has taken a fork\n", timestamp, bro->philo_id);
}

void	eating(t_philo *bro)
{
	pick_forks(bro);
}

// 332323 7 has taken a fork
// 332325 7 is eating
// 332328 7 is sleeping
// 332334 7 is thinking
// 332348 7 died

void	thinking(t_philo *bro, t_general_data *enviromment)
{
	struct timeval	current_time;
	long			time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	printf("%ld %d is thinking\n", time, bro->philo_id);
	usleep(enviromment->time_to_sleep * 1000);
}

void	sleeping(t_philo *bro, t_general_data *enviromment)
{
	struct timeval	current_time;
	long			time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	printf("%ld %d is sleeping\n", time, bro->philo_id);
	usleep(enviromment->time_to_sleep * 1000);
}
