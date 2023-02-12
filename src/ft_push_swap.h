/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:02:59 by amorilla          #+#    #+#             */
/*   Updated: 2023/02/12 15:24:09 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>

//value: 	  numero que hay que ordenar.

//idx:   	  el indice en la lista de TODOS los valores.

//pos:		  su posicion actual en la pila.

//target_pos: para los elementos en B, la posicion donde 
//			  deberia estar en A cuando este ordenado.

//cost_a:	  cuantas acciones necesito para rotar A para que 
//			  el elemento en la posicion target llegue al 
//			  top del stack A.

//cost_b:	  cuantas acciones necesito para rotar B para que 
//			  el elemento llegue al top del stack B.

//next:		  puntero al elemento siguiente de la pila.

typedef struct s_stack
{
	int				value;
	int				idx;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}t_stack;

void	sa(t_stack **stack);
void	push(t_stack **origin, t_stack **dest, char stackdest);
void	rotate(t_stack **stack, char option);
void	rr(t_stack **a, t_stack **b);
void	reverserot(t_stack **stack, char option);
void	rrr(t_stack **a, t_stack **b);
void	addnode(t_stack *st, int num);
t_stack	*createnode(int num);
void	print_error(void);
int		*parse_input(int argnum, char **args, int *size);
int		is_valid_number(char *str);
int		num_in_range(long num);
int		check_parse_int_conditions(char **lsts, int size, int *intlst, int cpy);
void	free_all_list(char ***splited_str, int **list_int);
int		check_no_dup(long num, int *lst, int current_size, int size);
long	atoi_long(char *str);

#endif
