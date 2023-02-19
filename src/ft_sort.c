/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:46:11 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/19 17:03:28 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_stack	*get_min_node(t_stack *a)
{
	t_stack	*minimal_node;
	t_stack	*aux;
	
	aux = a;
	while (aux && aux->idx != 0)
	{
		aux = aux->next;
	}
	minimal_node = aux;
	while (aux)
	{
		if (aux->value < minimal_node->value && aux->idx == 0)
			minimal_node = aux;
		aux = aux->next;
	}
	return (minimal_node);
}

void	asign_indexes(t_stack *a, int size)
{
	int		index;

	index = 1;
	while (index <= size)
	{
		get_min_node(a)->idx = index;
		index++;
	}
}

void	sort_stacks(t_stack *a, t_stack *b, int size)
{
	(void)b;
	asign_indexes(a, size);
}
