/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_movements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:14:02 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/10 14:01:06 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	absv(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

static void	execdoublemoves(t_stack **a, t_stack **b, int *movsa, int *movsb)
{
	if ((*movsa) > 0 && (*movsb) > 0)
	{
		rr(a, b);
		(*movsa)--;
		(*movsb)--;
	}
	else if ((*movsa) < 0 && (*movsb) < 0)
	{
		rrr(a, b);
		(*movsa)++;
		(*movsb)++;
	}
}

static void	executemovs(t_stack **a, t_stack **b, int movsa, int movsb)
{
	while (movsa != 0 || movsb != 0)
	{
		if ((movsa > 0 && movsb > 0) || (movsa < 0 && movsb < 0))
			execdoublemoves(a, b, &movsa, &movsb);
		else if (movsa < 0)
		{
			reverserot(a, 'a');
			movsa++;
		}
		else if (movsb < 0)
		{
			reverserot(b, 'b');
			movsa++;
		}
		else if (movsa > 0)
		{
			rotate(a, 'a');
			movsa--;
		}
		else if (movsb > 0)
		{
			rotate(b, 'b');
			movsb--;
		}
	}
}

void	exec_optimal_movs(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	t_stack *best_node;
	t_stack *auxb;

	auxb = *b;
	best_node = *b;
	while (auxb)
	{
		if ((absv(best_node->cost_a) + absv(best_node->cost_b))
			> (absv(auxb->cost_a) + absv(auxb->cost_b)))
		{
			best_node = auxb;
		}
		auxb = auxb->next;
	}
	executemovs(a, b, best_node->cost_a, best_node->cost_b);
	push(b, a, 'a');
	(*size_a)++;
	(*size_b)--;
	
}

void	rotate_until_sorted(t_stack **a, int size_a)
{
	t_stack	*auxa;
	int		num_rotates;

	auxa = *a;
	calculate_positions(*a);
	while (auxa)
	{
		if(auxa->idx == 1)
		{
			if ((auxa->pos + 1) <= size_a / 2 + 1)
				num_rotates = auxa->pos;
			else
				num_rotates = auxa->pos - size_a;
		}
		auxa = auxa->next;
	}
	while (num_rotates != 0)
	{
		if (num_rotates < 0)
		{
			reverserot(a, 'a');
			num_rotates++;
		}
		else
		{
			rotate(a, 'a');
			num_rotates--;
		}
	}
}