/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:41:53 by kmatias           #+#    #+#             */
/*   Updated: 2024/06/26 23:41:57 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_all_save_three:
*	Envia todos os elementos da pilha a para a pilha b, exceto os três últimos.
*	Envia os valores menores primeiro e depois os maiores para ajudar na
*	eficiência da ordenação.
*/
static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

/* shift_stack:
* Depois que a maior parte da pilha está ordenada,
* move a pilha a até que o valor
* mais baixo esteja no topo.
* Se estiver na metade inferior da pilha, o movimento
* é feito em sentido anti-horário até que esteja na posição correta.
* Caso contrário,
* o movimento é feito em sentido horário até que esteja no topo da pilha.
*/
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

/* sort:
*	Algoritmo de ordenação para uma pilha maior que 3.
*		Envia tudo menos 3 números para a pilha B.
*		Ordena os 3 números restantes na pilha A.
*		Calcula a movimentação mais eficiente.
*		Desloca os elementos até que a pilha A esteja ordenada.
*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
