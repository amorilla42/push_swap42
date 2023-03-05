/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_target_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:02:44 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/05 16:08:24 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//mirar si el indice es el mayor de todos
//SI NO ES EL MAYOR mirar el mayor indice mas cercano, y asignarle la pos de ese elemento
//SI ES EL MAYOR miras el menor mas cercano y la pos es la pos de ese mas uno
//MENTIRA GRANDE, SIEMPRE EL MAYOR INEDX VA A ESTAR EN A
/*
int	check_biggest_index(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	int		is_biggest;

	aux_a = *a;
	is_biggest = 1;
	while (aux_a && is_biggest)
	{
		if (aux_a->idx < (*b)->idx)
		{
			is_biggest = 0;
			ft_putstr_fd("es mas picolo\n",1);
		}
		else
			ft_putstr_fd("es extralongo \n",1);
		aux_a = aux_a->next;
	}
	return (is_biggest);
}
*/
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
	int		closer_idx;
	int		target_pos;

	aux_a = *a;
	closer_idx = get_biggest_index(&aux_a);
	ft_putnbr_fd(closer_idx,1);
	
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
/*
	BASURA INFECTA!!!!!!!!!!!!

void	assing_target_pos_biggest_idx(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	int		biggest_idx;
	int		target_pos;

	aux_a = *a;
	biggest_idx = get_biggest_index(&aux_a);
	while (aux_a)
	{
		if (aux_a->idx == biggest_idx)
		{
			target_pos = aux_a->pos+1;
		}
		aux_a = aux_a->next;
	}
	(*b)->target_pos = target_pos;
}
*/