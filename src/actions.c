/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:54:11 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/26 13:55:34 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void is_sleeping(t_philo *bro)
{
	(void)bro;
	printf("bro is sleepinggg\n");// debug
	usleep(100000);//debug
}

void is_eating(t_philo *bro)
{
	(void)bro;
	printf("bro is eatinggg\n");//debug
	usleep(10);//debug
}

void is_thinking(t_philo *bro)
{
	(void)bro;
	printf("bro is thinkinggg\n");//debug	
	usleep(3000);//debug
}