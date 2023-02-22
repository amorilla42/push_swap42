/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:42:05 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/22 20:32:35 by amorilla         ###   ########.fr       */
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
			printf("index %d value %d pos %d target_pos %d\n", s->idx, s->value, s->pos, s->target_pos);
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

void	freestacks(t_stack **a, t_stack **b)
{
	freestack(a);
	freestack(b);	
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
		a = createnode(&lst, lst[i]);
		while (++i < size)
			addnode(a, &lst, lst[i]);
		printstack(a, 'a');
		sort_stacks(&a, &b, size);
		printstack(a, 'a');
		printstack(b, 'b');
		freestacks(&a, &b);
		free(lst);
	}
	exit(EXIT_SUCCESS);
}
