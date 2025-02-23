/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:06:27 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/23 00:30:18 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	check_number(char *str)
{
	int	i;

	if (str == NULL || *str == '\0')
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_number(argv[i]) == 0)
		{
			printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	process_single_argument(int *argc, char ***argv)
{
	char	**new_argv;

	if (!(*argv)[1][0])
	{
		printf("Errorrrr\n");
		return (1);
	}
	new_argv = parse_input_string(*argv, argc);
	if (!new_argv)
		return (1);
	*argv = new_argv;
	return (0);
}
