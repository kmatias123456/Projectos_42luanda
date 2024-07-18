/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:37:01 by kmatias           #+#    #+#             */
/*   Updated: 2024/06/26 23:37:03 by kmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* do_rev_rotate_both:
* Reverse rotaciona tanto a pilha A quanto a pilha B até que uma delas
* esteja na posição correta.
* O custo fornecido é negativo, pois ambas as posições estão na metade
* inferior de suas respectivas pilhas. O custo é aumentado à medida que
* as pilhas são rotacionadas reversamente. Quando um dos custos atinge 0,
* a pilha foi rotacionada o máximo possível e a posição do topo está correta.
*/
static void	do_rev_rotate_both(
t_stack **a, t_stack **b, int *cost_a, int *cost_b
)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

/* do_rotate_both:
* Rotaciona tanto a pilha A quanto a pilha B até que uma delas esteja
* na posição correta.
* O custo fornecido é positivo, pois ambas as posições estão na metade
* superior de suas respectivas pilhas. O custo é diminuído à medida que
* as pilhas são rotacionadas. Quando um dos custos atinge 0, a pilha foi
* rotacionada o máximo possível e a posição do topo está correta.
*/
static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

/* do_rotate_a:
* Rotaciona a pilha A até que ela esteja na posição correta. Se o custo
* for negativo, a pilha será rotacionada reversamente. Se for positivo,
* ela será rotacionada.
*/
static void	do_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

/* do_rotate_b:
* Rotaciona a pilha B até que ela esteja na posição correta. Se o custo
* for negativo, a pilha será rotacionada reversamente. Se for positivo,
* ela será rotacionada.
*/
static void	do_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

/* do_move:
* Escolhe qual movimento fazer para colocar o elemento da pilha B na
* posição correta na pilha A.
* Se os custos de mover as pilhas A e B para a posição coincidirem
* (ou seja, ambos negativos ou ambos positivos), ambas serão rotacionadas
* ou rotacionadas reversamente ao mesmo tempo.
* Elas também podem ser rotacionadas separadamente, antes de finalmente
* empurrar o elemento do topo da pilha B para o topo da pilha A.
*/
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	do_pa(a, b);
}
