/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-ass <arde-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:13:25 by arde-ass          #+#    #+#             */
/*   Updated: 2026/03/24 07:22:01 by arde-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *get_min_node(t_stack_node *head)
{
	t_stack_node *min_node;
	t_stack_node *tmp;

	if (!head)
		return (NULL);
	min_node = head;
	tmp = head->next;
	while (tmp != head)
	{
		if (tmp->value < min_node->value)
			min_node = tmp;
		tmp = tmp->next;
	}
	return (min_node);
}

t_stack_node *get_max_node(t_stack_node *head)

{
	t_stack_node *max_node;
	t_stack_node *tmp;

	if (!head)
		return (NULL);
	max_node = head;
	tmp = head->next;
	while (tmp != head)
	{
		if (tmp->value > max_node->value)
			max_node = tmp;
		tmp = tmp->next;
	}
	return (max_node);
}

int	get_stack_size (t_stack_node *head)
{
	t_stack_node	*tmp;
	int				i;

	if (!head)
		return (0);
	
	tmp = head->next;
	i = 1;
	while (tmp != head)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}