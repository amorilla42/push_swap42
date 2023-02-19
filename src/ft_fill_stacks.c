/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:45:18 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/19 16:06:10 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*createnode(int** lst ,int num)
{
	t_stack	*st;

	st = (t_stack *) malloc(sizeof(t_stack));
	if (!st)
	{
		free(lst);
		print_error();
	}
	st->value = num;
	st->next = NULL;
	return (st);
}

void	addnode(t_stack *st, int** lst, int num)
{
	t_stack	*aux;
	
	aux = st;
	while (st->next != NULL)
	{
		st = st->next;
	}
	st->next = createnode(lst, num);
	if (!st->next)
	{
		free(lst);
		freestack(&aux);
		print_error();
	}
}