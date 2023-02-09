/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:04:39 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/09 23:37:39 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && ft_strlen(str) > 1)
		i++;
	else if ((str[i] == '-' && ft_strlen(str) == 1)
		|| (str[i] == '-' && str[i + 1] == '-'))
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	num_in_range(long num)
{
	return (num > INT_MAX || num < INT_MIN);
}

void	free_all_list(char ***splited_str, int **list_int)
{
	int	i;

	i = 0;
	while ((*splited_str)[i])
	{
		free((*splited_str)[i]);
		i++;
	}
	free(*splited_str);
	free(*list_int);
	print_error();
}

int	check_parse_int_conditions(char **lst_of_lst, int size, int *intlst)
{
	long	num;

	num = atoi_long(lst_of_lst[size]);
	return (is_valid_number(lst_of_lst[size]) && num_in_range(num)
		&& check_dup(num, intlst));
}
