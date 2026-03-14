/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-ass <arde-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 04:38:01 by arde-ass          #+#    #+#             */
/*   Updated: 2026/03/14 04:43:48 by arde-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **head)
{
	int	tmp_val;
	int	tmp_idx;

	if (!head || !*head || (*head)->next == *head)
		return ;
	tmp_val = (*head)->value;
	tmp_idx = (*head)->index;
	(*head)->value = (*head)->next->value;
	(*head)->index = (*head)->next->index;
	(*head)->next->value = tmp_val;
	(*head)->next->index = tmp_idx;
}

void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
