/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_level.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-ass <arde-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:02:36 by arde-ass          #+#    #+#             */
/*   Updated: 2026/04/03 13:15:16 by arde-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_strategy(size_t mistakes, size_t pairs)
{
	float	disorder;

	if (pairs == 0)
		return (1);
	disorder = (float)mistakes / (float)pairs;
	if (disorder < 0.2f)
		return (1);
	if (disorder >= 0.5f)
		return (3);
	return (2);
}

static int	disorder_level(t_stack_node *head)
{
	size_t			mistakes;
	size_t			pairs;
	t_stack_node	*current;
	t_stack_node	*compare;

	mistakes = 0;
	pairs = 0;
	if (!head || head->next == head)
		return (1);
	current = head;
	while (current->next != head)
	{
		compare = current->next;
		while (compare != head)
		{
			pairs++;
			if (current->value > compare->value)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	return (get_strategy(mistakes, pairs));
}
