/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:52:26 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/25 23:02:28 by gcesar-n         ###   ########.fr       */
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

static int	input_checker(char **argv)
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

static int	validate_input(int argc, char **argv, t_general_data *philo)
{
	if (handle_argc_error(argc) || input_checker(argv))
		return (1);
	printf("b4 parse: philo_amount = %d\n", philo->philo_amount);//debug
	philo->philo_amount = ft_simple_atoi(argv[1]);
	philo->time_to_die = ft_simple_atoi(argv[2]);
	philo->time_to_eat = ft_simple_atoi(argv[3]);
	philo->time_to_sleep = ft_simple_atoi(argv[4]);
	printf("Parsed Values -> philo_amount: %d, time_to_die: %d, time_to_eat: %d, time_to_sleep: %d\n",
		philo->philo_amount, philo->time_to_die, philo->time_to_eat, philo->time_to_sleep);//debug 
	return (0);
}

int	setup(int argc, char **argv)
{
	t_general_data	philo;

	philo.philo_amount = 0;
	if (validate_input(argc, argv, &philo))
		return (1);
	philo.philosophers = malloc(sizeof(t_philo) * philo.philo_amount);
	if (philo.philosophers == NULL)
	{
		printf("Error on memory allocation \n");
		return (1);
	}
	printf("philo_amount after parse: %d\n", philo.philo_amount);//debug
	init_philosophers(&philo);
	free(philo.philosophers);
	return (0);
}
