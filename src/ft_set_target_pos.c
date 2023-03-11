/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_target_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:02:44 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/11 18:34:00 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static	int	get_biggest_index(t_stack **a)
{
	t_stack	*aux_a;
	int		biggest;

	aux_a = *a;
	biggest = aux_a->idx;
	while (aux_a)
	{
		if (aux_a->idx > biggest)
			biggest = aux_a->idx;
		aux_a = aux_a->next;
	}
	return (biggest);
}

void	assign_target_pos_lower_idx(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	int		closer_idx;
	int		target_pos;

	aux_a = *a;
	closer_idx = get_biggest_index(&aux_a);
	while (aux_a)
	{
		if ((*b)->idx < aux_a->idx && closer_idx > aux_a->idx)
		{
			closer_idx = aux_a->idx;
			target_pos = aux_a->pos;
		}
		aux_a = aux_a->next;
	}
	(*b)->target_pos = target_pos;
}
