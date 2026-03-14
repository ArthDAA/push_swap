/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-ass <arde-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 04:44:30 by arde-ass          #+#    #+#             */
/*   Updated: 2026/03/14 05:17:31 by arde-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

static void	push_to_dest(t_stack_node **dest, t_stack_node *node);
void		push(t_stack_node **dest, t_stack_node **src);
void		pa(t_stack_node **a, t_stack_node **b);
void		pb(t_stack_node **a, t_stack_node **b);

void		swap(t_stack_node **head);
void		sa(t_stack_node **a);
void		sb(t_stack_node **b);
void		ss(t_stack_node **a, t_stack_node **b);

void		rotate(t_stack_node **head);
void		ra(t_stack_node **a);
void		rb(t_stack_node **b);
void		rr(t_stack_node **a, t_stack_node **b);

void		rev_rotate(t_stack_node **head);
void		rra(t_stack_node **a);
void		rrb(t_stack_node **b);
void		rrr(t_stack_node **a, t_stack_node **b);

#endif
