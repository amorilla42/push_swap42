/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:02:59 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/11 18:43:10 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

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
void	addnode(t_stack *st, int **lst, int num);
t_stack	*createnode(int **lst, int num);
void	print_error(void);
int		*parse_input(int argnum, char **args, int *size);
int		is_valid_number(char *str);
int		num_in_range(long num);
int		check_parse_int_conditions(char **lsts, int size, int *intlst, int cpy);
void	free_all_list(char ***splited_str, int **list_int, int iserror);
int		check_no_dup(long num, int *lst, int current_size, int size);
long	atoi_long(char *str);
void	sort_stacks(t_stack **a, t_stack **b, int size);
void	freestacks(t_stack **a, t_stack **b);
void	freestack(t_stack **s);
void	sort_three_numbers(t_stack **a);
void	sort_more_than_three(t_stack **a, t_stack **b, int size);
void	assign_target_pos_lower_idx(t_stack **a, t_stack **b);
void	calculate_positions(t_stack *s);
void	assign_target_pos(t_stack **a, t_stack **b);
void	assign_costs(t_stack **b, int size_a, int size_b);
void	exec_optimal_movs(t_stack **a, t_stack **b, int *size_a, int *size_b);
void	rotate_until_sorted(t_stack **a, int size_a);
int		absv(int num);
#endif
