/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heuristics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:37:11 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/06 20:46:05 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"

/*
	Optimal number of moves for an element to be in the top of the stack B
*/
static void	calc_cost_b(t_stack **b, int size_b)
{
	t_stack	*aux_b;

	aux_b = *b;
	while (aux_b)
	{
		if ((aux_b->pos + 1) <= size_b / 2 + 1)
			aux_b->cost_b = aux_b->pos;
		else
			aux_b->cost_b = aux_b->pos - size_b;
		aux_b = aux_b->next;
	}
}

/*
	Optimal number of moves for the element in the target_pos 
	to end up at the top of stack A
*/
static void	calc_cost_a(t_stack **b, int size_a)
{
	t_stack	*aux_b;

	aux_b = *b;
	while (aux_b)
	{
		if ((aux_b->target_pos + 1) <= size_a / 2 + 1)
			aux_b->cost_a = aux_b->target_pos;
		else
			aux_b->cost_a = aux_b->target_pos - size_a;
		aux_b = aux_b->next;
	}
}

void	assign_costs(t_stack **b, int size_a, int size_b)
{
	calc_cost_b(b, size_b);
	calc_cost_a(b, size_a);
}