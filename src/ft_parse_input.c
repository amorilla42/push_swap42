/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:53:35 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/09 20:42:25 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit("EXIT_FAILURE");
}

static char	*calloctemp(int argnum)
{
	char	*temp;

	temp = ft_calloc(sizeof(char), 2);
	if (!temp || argnum < 2)
	{
		if (temp)
			free(temp);
		print_error();
	}
	temp[0] = ' ';
	return (temp);
}

/*
	aux  = is the string with all the args
	temp = is the string used as a buffer that is "freed" every cycle
*/
int	*parse_input(int argnum, char **args)
{
	char	*aux;
	char	*temp;
	int		idx;

	temp = calloctemp(argnum);
	idx = 0;
	while (++idx <= argnum)
	{
		if (aux)
			free(aux);
		aux = ft_strjoin((char const *)temp, (char const *)args[idx]);
		free(temp);
		temp = ft_strdup((const char *)aux);
		
	}
}
