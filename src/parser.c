/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:52:26 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/28 12:50:13 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	handle_argc_error(int arg_count)
{
	if (arg_count > 6)
	{
		printf("Error: Too many arguments (expected: 5 or 6).\n");
		return (1);
	}
	if (arg_count < 5)
	{
		printf("Error: Not enough arguments (expected: 5 or 6).\n");
		return (1);
	}
	return (0);
}

static int	is_valid_number(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !arg[0])
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_input(char **argv)
{
	int	word;

	word = 1;
	while (argv[word])
	{
		if (!is_valid_number(argv[word]) || ft_simple_atoi(argv[word]) <= 0)
		{
			printf("Error: Invalid input '%s'.\n", argv[word]);
			return (1);
		}
		word++;
	}
	return (0);
}

// static int	validate_input(int argc, char **argv, t_general_data *philo)
// {
// 	if (handle_argc_error(argc) || check_input(argv))
// 		return (1);
// 	printf("b4 parse: philo_amount = %d\n", philo->philo_amount);//debug
// 	philo->philo_amount = ft_simple_atoi(argv[1]);
// 	philo->time_to_die = ft_simple_atoi(argv[2]);
// 	philo->time_to_eat = ft_simple_atoi(argv[3]);
// 	philo->time_to_sleep = ft_simple_atoi(argv[4]);
// 	if (argc == 6)
// 		philo->times_must_eat = ft_simple_atoi(argv[5]);
// 	printf("Parsed Values: philo_amount: %d, time_to_die: %d, time_to_eat: %d, time_to_sleep: %d\n",
// 			philo->philo_amount, philo->time_to_die, philo->time_to_eat, philo->time_to_sleep); // debug
// 	if (argc == 6)//debug
// 		printf("times must eat: %d\n", philo->times_must_eat);//debug
// 	return (0);
// }

static int	validate_input(int argc, char **argv, t_general_data *philo)
{
	if (handle_argc_error(argc) || check_input(argv))
		return (1);
	printf("b4 parse: philo_amount = %d\n", philo->philo_amount);
	philo->philo_amount = ft_simple_atoi(argv[1]);
	philo->time_to_die = ft_simple_atoi(argv[2]);
	philo->time_to_eat = ft_simple_atoi(argv[3]);
	philo->time_to_sleep = ft_simple_atoi(argv[4]);
	philo->times_must_eat = -1;
	if (argc == 6)
	{
		philo->times_must_eat = ft_simple_atoi(argv[5]);
		if (philo->times_must_eat <= 0)
		{
			printf("Error: Invalid times_must_eat value: %s\n", argv[5]);
			return (1);
		}
	}
	printf("Parsed Values: philo_amount: %d, time_to_die: %d, time_to_eat: %d, time_to_sleep: %d\n",
			philo->philo_amount, philo->time_to_die, philo->time_to_eat, philo->time_to_sleep);//debug
	if (argc == 6) // Debug
		printf("times must eat: %d\n", philo->times_must_eat);//debug
	return (0);
}

int init_environment(int argc, char **argv)
{
	t_general_data philo;

	philo.philo_amount = 0;
	philo.times_must_eat = -1;
	if (validate_input(argc, argv, &philo))
		return (1);
	philo.philosophers = malloc(sizeof(t_philo) * philo.philo_amount);
	if (!philo.philosophers)
	{
		printf("Memory allocation fail (philos) \n");
		return (1);
	}
	philo.forks = malloc(sizeof(pthread_mutex_t) * philo.philo_amount);
	if (!philo.forks)
	{
		printf("Memory allocation fail (forks)\n");
		free(philo.philosophers);
		return (1);
	}
	init_forks(&philo, 0);
	printf("philo_amount after parse: %d\n", philo.philo_amount);
	init_philosophers(&philo);
	return (0);
}
