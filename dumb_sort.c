/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-ass <arde-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:02:42 by arde-ass          #+#    #+#             */
/*   Updated: 2026/04/01 17:23:08 by arde-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	direction(t_stack_node *tmp, int val, int max)
{
	while (max > 0)
	{
		if (tmp->index == val)
			return (1);
		max--;
		tmp = tmp->next;
	}
	return (0);
}

static void	push_min_to_b(t_stack_node **head, t_stack_node **b, int t, int s)
{
	if (direction(*head, t, s / 2))
	{
		while ((*head)->index != t)
			ra(head);
	}
	else
	{
		while ((*head)->index != t)
			rra(head);
	}
	pb(head, b);
}

t_stack_node	*dumb_sort(t_stack_node *head)
{
	t_stack_node	*stack_b;
	int				size;
	int				target_idx;

	stack_b = NULL;
	target_idx = 0;
	size = get_stack_size(head);
	while (size > 3)
	{
		push_min_to_b(&head, &stack_b, target_idx, size);
		target_idx++;
		size--;
	}
	head = smol_sort(head);
	while (stack_b)
		pa(&head, &stack_b);
	return (head);
}
