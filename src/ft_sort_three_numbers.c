/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:26:31 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/19 20:27:48 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_three_numbers(t_stack **a)
{
	t_stack	*first;
	t_stack	*seccond;
	t_stack	*third;

	first = *a;
	seccond = (*a)->next;
	third = (*a)->next->next;
	if (first->idx > seccond->idx && first->idx > third->idx)
		rotate(a, 'a');
	else if (first->idx < seccond->idx && seccond->idx > third->idx)
		reverserot(a, 'a');
	first = *a;
	seccond = (*a)->next;
	if (first->idx > seccond->idx)
		sa(a);
}
