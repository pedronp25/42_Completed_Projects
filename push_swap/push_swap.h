/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromig <pedromig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:36:29 by pedromig          #+#    #+#             */
/*   Updated: 2025/08/26 16:20:32 by pedromig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

typedef struct s_array
{
	char	**str_arr;
	int		*int_arr;
}	t_array;

typedef struct s_stack
{
	t_node	*a; // Top of stack A
	t_node	*b; // Top of stack B
	int		len_a;
	int		len_b;
	t_array	array;
}	t_stack;

char	**ps_args_check(t_stack *stack, int argc, char **argv);
void	ps_dup_argv_strings(t_stack *stack, char **matrix,
			char **argv, int argc);
int		*ps_validate_str_arr(t_stack *stack, char **str_arr, int *int_arr_len);
int		ps_store_int_arr(t_stack *stack, char **str_arr, int *int_arr, int x);
void	ps_check_num(t_stack *stack, int *int_arr, long num);
int		ps_strarr_len(char **str_arr);
long	ps_atol(const char *str);
void	ps_check_duplicates(t_stack *stack, int	*arr, int len);
int		*ps_copy_array(t_stack *stack, int *arr, int len);
void	ps_quicksort_int_arr(int *arr, int low, int high);
int		ps_partition(int *arr, int low, int high);
void	ps_swap(int *a, int *b);
void	ps_init_stacks(t_stack *stack, int *int_arr, int len);
t_node	*ps_new_node(t_stack *stack, int value);
void	ps_node_add_back(t_node **head, t_node *new_node);
int		ps_sorted(t_stack *stack);
void	pa(t_stack *stack, int print);
void	pb(t_stack *stack, int print);
void	sa(t_stack *stack, int print);
void	sb(t_stack *stack, int print);
void	ss(t_stack *stack);
void	ra(t_stack *stack, int print);
void	rb(t_stack *stack, int print);
void	rr(t_stack	*stack);
void	rra(t_stack *stack, int print);
void	rrb(t_stack *stack, int print);
void	rrr(t_stack	*stack);
void	ps_smallstack_sort(t_stack *stack);
int		ps_find_min_pos(t_stack *stack);
void	ps_rotate_to_top(t_stack *stack, int pos);
void	ps_sort_2(t_stack *stack);
void	ps_sort_3(t_stack *stack);
void	ps_sort_4(t_stack *stack);
void	ps_sort_5(t_stack *stack);
void	ps_turk(t_stack *stack);
void	ps_calculate_cost(t_stack *stack);
int		ps_get_cost_b(t_stack *stack, int pos);
int		ps_get_target_pos_a(t_stack *stack, int b_val);
int		ps_find_smallest_value(t_node *current);
t_node	*ps_find_node_pos(t_node *node, int pos);
int		ps_get_cost_a(t_stack *stack, int target_pos);
t_node	*ps_find_cheapest_node(t_node *current);
int		ps_calc_node_cost(t_node *node);
int		ps_max(int a, int b);
int		ps_abs(int value);
void	ps_move_cheapest_node(t_stack *stack, t_node *node);
void	ps_rotate_single_stack(t_stack *stack, int cost, char which_stack);
void	ps_final_rotation(t_stack *stack);
void	ps_ra_or_rra(t_stack *stack, int lowest_value, int pos);
void	ps_error(t_stack *stack);
void	ps_success(t_stack *stack);
void	ps_cleanup(t_stack *stack);
void	ps_free_strarr(char **arr);
void	ps_cleanup_stack(t_node *head);

#endif
