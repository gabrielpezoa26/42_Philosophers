/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:46:28 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/28 16:39:48 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void init_forks(t_general_data *philo, int i)
{
	if (i >= philo->philo_amount)
		return;
	pthread_mutex_init(&philo->forks[i], NULL);
	init_forks(philo, i + 1);
}

int	should_continue_eating(t_philo *philo)
{
	int	max_meals;
	int	is_philo_alive;
	int	has_meals_left;

	max_meals = philo->data->times_must_eat;
	if (is_dead(philo, philo->data))
		is_philo_alive = 0;
	else
		is_philo_alive = 1;
	if (max_meals == -1)
		has_meals_left = 1;
	else if (philo->eat_count < max_meals)
		has_meals_left = 1;
	else
		has_meals_left = 0;
	if (is_philo_alive && has_meals_left)
		return (1);
	else
		return (0);
}

int is_dead(t_philo *philosopher, t_general_data *env)
{
	struct timeval	time;
	long current_time_ms;
	long time_since_last_meal;

	gettimeofday(&time, NULL);
	current_time_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	time_since_last_meal = current_time_ms - philosopher->last_ate;
	if (time_since_last_meal > env->time_to_die)
		return (1);
	return (0);
}