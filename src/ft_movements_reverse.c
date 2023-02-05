/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:50:04 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/05 18:58:40 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//AQUI PUEDE HABER FALLOS CUANDO HAY SOLO 2 ELEMENTOS POR EL PRELAST Y EL LAST?
void	reverserot(t_stack **stack, char option)
{
	t_stack	*last;
	t_stack	*aux;
	t_stack	*prelast;

	prelast = (*stack);
	last = (*stack)->next;
	if (last != NULL)
	{
		while (last->next)
			last = last->next;
		while (prelast->next->next)
			prelast = prelast->next;
		aux = (*stack);
		(*stack) = last;
		last->next = aux;
		prelast->next = NULL;
		if (option == 'a')
			write(1, "rra\n", 4);
		if (option == 'b')
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	reverserot(a, 'x');
	reverserot(b, 'x');
	write(1, "rrr\n", 4);
}
