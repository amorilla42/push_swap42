/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:46:11 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/19 18:27:04 by amorilla         ###   ########.fr       */
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

int	is_sorted(t_stack *a)
{
	int		sorted;
	t_stack	*aux;

	sorted = 1;
	aux = a;
	while (aux->next && sorted)
	{
		if (aux->idx > aux->next->idx)
			sorted = 0;
		aux = aux->next;
	}
	return (sorted);
}

void	sort_stacks(t_stack **a, t_stack **b, int size)
{
	(void)b;
	asign_indexes(*a, size);
	if (!is_sorted(*a))
	{
		ft_putstr_fd("DESORDENADISIMO \n", 1);
		if (size == 2)
			sa(a);
		if (size == 3)
			order_three_numbers(a);
		if (size > 3)
			order_more_than_three(a, b, size);
	}
	else
	{
		ft_putstr_fd("ORDENADISIMO \n", 1);
	}
	
}
