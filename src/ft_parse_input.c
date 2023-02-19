/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:53:35 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/19 15:15:58 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static char	*calloctemp(int argnum)
{
	char	*temp;

	temp = (char *)ft_calloc(sizeof(char), 2);
	if (!temp || argnum < 2)
	{
		if (temp)
			free(temp);
		print_error();
	}
	temp[0] = ' ';
	return (temp);
}

//Doesn't check if its valid because is checked in:
//int check_parse_int_conditions(char **lst_of_lst, int size, int *intlst)
long	atoi_long(char *str)
{
	long	res;
	long	sign;

	sign = 1;
	res = 0;
	if (*str == '-')
	{
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

static int	number_of_elements(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	*parse_input_to_int(char **input, int *size)
{
	int		*list_int;
	char	**list_of_lists;
	int		list_size;
	int		list_size_copy;

	list_of_lists = ft_split((char const *)*input, ' ');
	list_size = number_of_elements(*input, ' ');
	list_size_copy = list_size;
	*size = list_size_copy;
	free(*input);
	if (list_size == 0)
		print_error();
	list_int = (int *)ft_calloc(sizeof(int), list_size + 1);
	if (!list_int)
		free_all_list(&list_of_lists, &list_int, 1);
	while (list_size-- > 0)
	{
		if (check_parse_int_conditions(list_of_lists, list_size, list_int,
				list_size_copy))
			list_int[list_size] = (int) atoi_long(list_of_lists[list_size]);
		else
			free_all_list(&list_of_lists, &list_int, 1);
	}
	free_all_list(&list_of_lists, NULL, 0);
	return (list_int);
}

/*
	aux      = is the string with all the args
	temp     = is the string used as a buffer that is "freed" every cycle
	list_int = is the list of integer ready to introduce in the stack "A"
*/
int	*parse_input(int argnum, char **args, int *size)
{
	char	*aux;
	char	*temp;
	int		idx;
	int		*list_int;
	char	*space_temp;

	temp = calloctemp(argnum);
	idx = 0;
	while (++idx < argnum)
	{
		aux = ft_strjoin((char const *)temp, (char const *)args[idx]);
		free(temp);
		space_temp = ft_strjoin((const char *) aux, " ");
		temp = ft_strdup((const char *)space_temp);
		free(space_temp);
		free(aux);
	}
	list_int = parse_input_to_int(&temp, size);
	return (list_int);
}
