/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:42:03 by kmatias           #+#    #+#             */
/*   Updated: 2024/06/26 23:42:06 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find_highest_index:
*	Retorna o índice mais alto em uma pilha.
*/
static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* tiny_sort:
* Ordena uma pilha de 3 números em 2 ou menos movimentos.
* A ordenação é feita pelo índice
*	em vez do valor. Exemplo:
*		valores:		 0	 9	 2
*		índices:		[1]	[3]	[2]
*	Solução, 2 movimentos:
*	rra:
*		valores:		 2	 0	 9
*		índices:		[2]	[1]	[3]
*	sa:
*		valores:		 0	 2	 9
*		índices:		[1]	[2]	[3]
*/
void	tiny_sort(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
