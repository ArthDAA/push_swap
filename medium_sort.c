/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-ass <arde-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:48:57 by arde-ass          #+#    #+#             */
/*   Updated: 2026/04/03 13:48:59 by arde-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* medium_sort.c                                      :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: arde-ass <arde-ass@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/04/03 13:00:00 by arde-ass          #+#    #+#             */
/* Updated: 2026/04/03 13:00:00 by arde-ass         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Calcule une racine carrée basique pour définir la taille des Chunks.
*/
static int	ft_sqrt(int number)
{
	int	i;

	if (number < 0)
		return (0);
	i = 1;
	while (i * i <= number)
		i++;
	return (i - 1);
}

/*
** L'aller : Envoie les éléments sur B par paquets (fenêtre glissante)
*/
static void	push_chunks_to_b(t_stack_node **a, t_stack_node **b, int size)
{
	int	chunk;
	int	i;

	chunk = ft_sqrt(size) + (size / 100); // Taille du paquet optimisée
	i = 0;
	while (*a) // Tant que A n'est pas vide
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b); // On l'envoie au fond de B (pré-tri)
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			pb(a, b); // On le laisse au sommet de B
			i++;
		}
		else
		{
			ra(a); // Trop grand, on passe au suivant
		}
	}
}

/*
** L'algorithme Medium O(n*sqrt(n)) complet
*/
t_stack_node	*medium_sort(t_stack_node *head)
{
	t_stack_node	*stack_b;
	t_stack_node	*max_node;
	int				size;

	stack_b = NULL;
	size = get_stack_size(head);
	
	// Phase 1 : On vide A vers B avec notre algorithme de paquets
	push_chunks_to_b(&head, &stack_b, size);
	
	// Phase 2 : On rapatrie de B vers A (du plus grand au plus petit)
	while (stack_b)
	{
		size = get_stack_size(stack_b);
		max_node = get_max_node(stack_b); // On cherche l'élément le plus grand de B
		
		// On calcule le chemin le plus court pour le monter
		if (direction(stack_b, max_node->index, size / 2))
			while (stack_b != max_node)
				rb(&stack_b);
		else
			while (stack_b != max_node)
				rrb(&stack_b);
				
		pa(&head, &stack_b); // On le pose sur A
	}
	return (head);
}