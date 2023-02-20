/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more_than_three.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:18:28 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/19 21:09:22 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	push_and_decrease(t_stack **a, t_stack **b, int *current_size)
{
	push(a, b, 'b');
	(*current_size)--;
}

static void	push_all_except_three(t_stack **a, t_stack **b, int size)
{
	int	half;
	int	current_size;

	half = (size / 2) + 1 ;
	current_size = size;
	while (current_size > half && current_size >= 3)
	{
		if ((*a)->idx <= half)
			push_and_decrease(a, b, &current_size);
		else
			rotate(a, 'a');
	}
	while (current_size > 3)
	{
		if ((*a)->idx == size
			|| (*a)->idx == size - 1
			|| (*a)->idx == size - 2)
			rotate(a, 'a');
		else
			push_and_decrease(a, b, &current_size);
	}
	sort_three_numbers(a);
}

static void	calculate_positions(t_stack *s)
{
	t_stack *aux;
	int	pos;

	pos = 0;
	aux = s;
	while (aux)
	{
		aux->pos = pos;
		pos++;
		aux = aux->next;
	}
}

static void	assing_target_pos(t_stack **a, t_stack **b)
{
	
}

void	sort_more_than_three(t_stack **a, t_stack **b, int size)
{
	push_all_except_three(a, b, size);
	calculate_positions(*a);
	calculate_positions(*b);
}
