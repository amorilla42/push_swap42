/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:24:28 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/10 13:13:07 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sa(t_stack **stack)
{
	t_stack	*second;

	second = (*stack)->next;
	if (second != NULL)
	{
		(*stack)->next = second->next;
		second->next = (*stack);
		(*stack) = second;
		write(1, "sa\n", 3);
	}
}

void	push(t_stack **origin, t_stack **dest, char stackdest)
{
	t_stack	*aux;

	aux = (*origin);
	(*origin) = aux->next;
	aux->next = (*dest);
	(*dest) = aux;
	if (stackdest == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	rotate(t_stack **stack, char option)
{
	t_stack	*last;
	t_stack	*aux;

	last = (*stack)->next;
	if (last != NULL)
	{
		while (last->next)
			last = last->next;
		aux = (*stack);
		(*stack) = aux->next;
		last->next = aux;
		aux->next = NULL;
		if (option == 'a')
			write(1, "ra\n", 3);
		if (option == 'b')
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 'x');
	rotate(b, 'x');
	write(1, "rr\n", 3);
}
