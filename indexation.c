/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-ass <arde-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 06:10:31 by arde-ass          #+#    #+#             */
/*   Updated: 2026/04/02 10:56:38 by arde-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*val_extract(t_stack_node *head)
{
	int				i;
	int				j;
	int				*extract;
	t_stack_node	*tmp;

	if (!head)
		return (NULL);
	i = 0;
	j = get_stack_size(head);
	extract = malloc(sizeof(int) * j);
	if (!extract)
		return (NULL);
	tmp = head->next;
	while (i != j)
	{
		extract[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	return (extract);
}

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	if (!arr || size <= 1)
		return ;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

t_stack_node	*indexation(t_stack_node *head)
{
	int				i;
	int				*index;
	int				size;
	t_stack_node	*tmp;

	if (!head)
		return (NULL);
	i = 0;
	size = get_stack_size(head);
	index = val_extract(head);
	if (!index)
		return (NULL);
	bubble_sort(index, size);
	tmp = head;
	while (i < size)
	{
		while (index[i] != tmp->value)
			tmp = tmp->next;
		tmp->index = i;
		i++;
		tmp = head;
	}
	free(index);
	return (head);
}
