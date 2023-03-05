/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:42:05 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/05 19:32:19 by amorilla         ###   ########.fr       */
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
			printf("index %d value %d pos %d target_pos %d cost_b %d\n", s->idx, s->value, s->pos, s->target_pos, s->cost_b);
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
		/*
		//testeos del pos_objetivo cuando     ./push_swap 1 6 2 4 5 3 7
		a = createnode(&lst, lst[i]);
		while (++i < 3)
			addnode(a, &lst, lst[i]);
		b = createnode(&lst, lst[i]);
		while (++i < 7)
			addnode(b, &lst, lst[i]);
		a->idx = 0;
		a->next->idx = 5;
		a->next->next->idx = 1;
		b->idx = 3;
		b->next->idx = 4;
		b->next->next->idx = 2;
		b->next->next->next->idx = 6;
		calculate_positions(a);
		calculate_positions(b);
		assing_target_pos(&a, &b);
		*/
		
		a = createnode(&lst, lst[i]);
		while (++i < size)
			addnode(a, &lst, lst[i]);
		printstack(a, 'a');
		sort_stacks(&a, &b, size);
		printstack(a, 'a');
		printstack(b, 'b');
		/* testeos futurros
		push(&b, &a , 'a');
		calculate_positions(a);
		calculate_positions(b);
		assing_target_pos(&a, &b);
		printstack(a, 'a');
		printstack(b, 'b');
		
		rotate(&a , 'a');
		calculate_positions(a);
		calculate_positions(b);
		assing_target_pos(&a, &b);
		printstack(a, 'a');
		printstack(b, 'b');

		rotate(&b , 'b');
		push(&b, &a , 'a');
		calculate_positions(a);
		calculate_positions(b);
		assing_target_pos(&a, &b);
		printstack(a, 'a');
		printstack(b, 'b');
		//hasta aqui
		*/
		freestacks(&a, &b);
		free(lst);
	}
	exit(EXIT_SUCCESS);
}
