/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:42:05 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/10 00:50:05 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

void	printstack(t_stack *s, char nameStack)
{
	if (s != NULL)
	{
		printf("Pila %c : ", nameStack);
		while (s != NULL)
		{
			printf("%d, ", s->value);
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
	int	*lst;
	int	i = 0;

	if (argc > 1)
	{
		lst = parse_input(argc, argv);
		while (i < 5)
			printf("%d, ", lst[i++]);
	}
	exit(EXIT_SUCCESS);



	/*
	int num;
	char *str = "0000006";

	num = ft_atoi(str);
	ft_putnbr_fd(num, 1);
	ft_putendl_fd(" ", 1);
	ft_putnbr_fd(is_valid_number(str), 1);
	ft_putendl_fd(" ", 1);
	*/





	
/*
	t_stack	*a;
	t_stack	*b;


	a = NULL;
	b = NULL;
	a = createnode(2);
	addnode(a, 3);
	addnode(a, 4);
	addnode(a, 5);
	addnode(a, 6);
	printstack(a, 'a');
	rotate(&a, 'a');
	printstack(a, 'a');
	sa(&a);
	printstack(a, 'a');
	reverserot(&a, 'a');
	printstack(a, 'a');
	push(&a, &b, 'a');
	printstack(a, 'a');
	printstack(b, 'b');
	push(&a, &b, 'a');
	printstack(a, 'a');
	printstack(b, 'b');
	rr(&a, &b);
	printstack(a, 'a');
	printstack(b, 'b');
	rrr(&a, &b);
	printstack(a, 'a');
	printstack(b, 'b');
	push(&b, &a, 'b');
	printstack(a, 'a');
	printstack(b, 'b');
	freestack(&a);	
*/
}
