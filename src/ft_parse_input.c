/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:53:35 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/09 21:05:06 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

static long	atoi_long(char *str)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	res *= sign;
	return (res);
}



static int	*parse_input_to_int(char **input)
{
	int		*list_int;
	char	**list_str;

	list_str = ft_split((char const *)*input, ' ');
	
	free(*input);
	return (list_int);
}



/*
	aux      = is the string with all the args
	temp     = is the string used as a buffer that is "freed" every cycle
	list_int = is the list of integer ready to introduce in the stack "A"
*/
int	*parse_input(int argnum, char **args)
{
	char	*aux;
	char	*temp;
	int		idx;
	int		*list_int;

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
	free(temp);
	list_int = parse_input_to_int(&aux);
}
