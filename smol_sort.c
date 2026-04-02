/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smol_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-ass <arde-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:15:57 by arde-ass          #+#    #+#             */
/*   Updated: 2026/03/25 10:13:47 by arde-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*smol_sort(t_stack_node *head)
{
	t_stack_node	*max_node;

	if (!head || !head->next || head->next->next == head)
		return (head);
	max_node = get_max_node(head);
	if (head == max_node)
	{
		ra(&head);
	}
	else if (head->next == max_node)
	{
		rra(&head);
	}
	if (head->index > head->next->index)
	{
		sa(&head);
	}
	return (head);
}
