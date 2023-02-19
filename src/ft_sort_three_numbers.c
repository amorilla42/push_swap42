/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:26:31 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/19 18:51:27 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_three_numbers(t_stack **a)
{
	if (*a->idx > a->next->idx && *a->idx > a->next->next->idx)
        rotate(a, 'a');
    else if (*a->idx < a->next->idx && a->next->idx > a->next->next->idx)
        reverserot(a, 'a');
    if (*a->idx > a->next->idx)
        sa(a);
}