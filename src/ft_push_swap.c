/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:42:05 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/17 14:10:45 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


void	printstack(t_stack *s, char nameStack)
{
	if (s != NULL)
	{
		printf("Pila %c : \n", nameStack);
		while (s != NULL)
		{
			printf("index %d value %d \n", s->idx, s->value);
			s = s->next;
		}
		printf("\n");
	}
	fflush(NULL);
}

void	freestack(t_stack **s)
{
	t_stack	*tmp;

	if (s)
	{
		while (*s)
		{
			tmp = (*s)->next;
			free(*s);
			(*s) = tmp;
		}
	}
}

int	main(int argc, char **argv)
{
	int		*lst;
	int		size;
	int		i;
	t_stack	*a;
	t_stack	*b;
	
	i = 0;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		lst = parse_input(argc, argv, &size);
		a = createnode(lst[i]);
		while (++i < size)
			addnode(a, lst[i]);
		printstack(a, 'a');
		sort_stacks(a, b, size);
		printstack(a, 'a');
	}
	exit(EXIT_SUCCESS);
}
