/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:45:18 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/05 18:26:17 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	addnode(t_stack *st, int num)
{
	while (st->next != NULL)
	{
		st = st->next;
	}
	st->next = createnode(num);
}

t_stack	*createnode(int num)
{
	t_stack	*st;

	st = (t_stack *) malloc(sizeof(t_stack));
	st->value = num;
	st->next = NULL;
	return (st);
}
