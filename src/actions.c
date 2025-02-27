/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:54:11 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/27 12:29:22 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void is_sleeping(t_philo *bro, t_general_data *enviromment)
{
    struct timeval	current_time;
    long			time;

    gettimeofday(&current_time, NULL);
    time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
    printf("%ld %d is sleeping\n", time, bro->philo_id);
    usleep(enviromment->time_to_sleep * 1000);
}


void is_eating(t_philo *bro)
{
	(void)bro;
	printf("bro is eatinggg\n");
	usleep(100000);
}

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