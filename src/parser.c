/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:52:26 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/23 13:21:29 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_argc_error(int arg_count)
{
	if (arg_count < 6)
		printf("not enough arguments :(  (expected: 6)\n");
	if (arg_count > 6)
		printf("too many arguments :(  (expected: 6)\n");
}

static int	input_checker(char **argv)
{
	int	word;
	int	letter;

	word = 1;
	while (argv[word])
	{
		letter = 0;
		while (argv[word][letter])
		{
			if (argv[word][letter] == ' ')
			{
				letter++;
			}
			if (!ft_isdigit(argv[word][letter]))
			{
				printf("invalid input\n");
				return (1);
			}
			letter++;
		}
		word++;
	}
	return (0);
}

void	validate_input(int argc, char **argv)
{
	handle_argc_error(argc);
	input_checker(argv);
}
