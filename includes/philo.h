/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:22:33 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/28 12:47:08 by gcesar-n         ###   ########.fr       */
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

typedef struct s_philo	t_philo;

typedef struct s_general_data
{
	int				philo_amount;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	pthread_mutex_t	print_mutex;
	long			start_time;
	t_philo			*philosophers;
	pthread_mutex_t	*forks;
}	t_general_data;

typedef struct s_philo
{
	int						philo_id;
	int						eat_count;
	long					last_ate;
	pthread_t				thread;
	pthread_mutex_t			eat_mutex;
	struct s_general_data	*data;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
}	t_philo;

/*--------PARSE--------*/
int			init_environment(int argc, char **argv);

/*-----PARSE_UTILS-----*/
int			ft_isdigit(int c);
int			check_number(char *str);
int			ft_simple_atoi(char *str);

/*-------THREADS-------*/
pthread_t	*init_philosophers(t_general_data *data);

/*-------ACTIONS-------*/
void		thinking(t_philo *bro, t_general_data *enviromment);
void		eating(t_philo *bro);
void		sleeping(t_philo *bro, t_general_data *enviromment);

/*--------UTILS--------*/
void		init_forks(t_general_data *philo, int i);
int	should_continue_eating(t_philo *philo);
int			is_dead(t_philo *philosopher, t_general_data *env);

#endif