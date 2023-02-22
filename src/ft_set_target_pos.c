/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_target_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:02:44 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/22 20:04:14 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//mirar si el indice es el mayor de todos
//SI NO ES EL MAYOR mirar el mayor indice mas cercano, y asignarle la pos de ese elemento
//SI ES EL MAYOR miras el menor mas cercano y la pos es la pos de ese mas uno

int	check_biggest_index(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	int		is_biggest;

	aux_a = *a;
	is_biggest = 1;
	while (aux_a && is_biggest)
	{
		if (aux_a->idx < *b->idx)
			is_biggest = 0;
		aux_a = aux_a->next;
	}
	return (is_biggest);
}

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

void	assing_target_pos_lower_idx(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;
	int		closer_idx;
	int		target_pos;

	aux_b = *b;
	while (aux_b)
	{
		aux_a = *a;
		closer_idx = get_biggest_index(aux_a);
		while (aux_a)
		{
			if (aux_b->idx < aux_a->idx && closer_idx > aux_a->idx)
				closer_idx = aux_a->idx;
			



			
			aux_a = aux_a->next;
		}
		aux_b = aux_b->next;
	}
}

void	assing_target_pos_biggest_idx(t_stack **a, t_stack **b)
{
	
}