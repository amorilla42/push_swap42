/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:49:52 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/10 00:48:20 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_no_dup(long num, int *lst, int current_size, int size)
{
	if (current_size == size)
		return (1);
	while (size > current_size)
	{
		if (lst[size] == num)
			return (0);
		size--;
	}
	return (1);
}
