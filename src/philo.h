/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:22:33 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/24 14:23:51 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int	philo_amount;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;
}	t_philo;

/*--------PARSE--------*/
int	validate_input(int argc, char **argv, t_philo *philo);

/*-----PARSE_UTILS-----*/
int	ft_isdigit(int c);
int	check_number(char *str);
int	ft_simple_atoi(char *str);

#endif