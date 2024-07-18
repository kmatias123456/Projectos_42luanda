/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiangebeni <kiangebeni@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:39:41 by kmatias           #+#    #+#             */
/*   Updated: 2024/07/17 22:08:44 by kiangebeni       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_position:
* Atribui uma posição a cada elemento de uma pilha de cima para baixo
* em ordem ascendente.
* Exemplo de pilha:
*		valor:		 3	 0	 9	 1
*		índice:		[3]	[1]	[4]	[2]
*		posição:	<0>	<1>	<2>	<3>
* Isto é usado para calcular o custo de mover um determinado número para
* uma determinada posição. Se o exemplo acima for a pilha b, não custaria
* nada (0) empurrar o primeiro elemento para a pilha a.
* No entanto, se quisermos
* empurrar o valor mais alto, 9,
* que está na terceira posição, custaria 2 movimentos
* extra para trazer esse 9 para o topo de b antes de empurrá-lo para a pilha a.
*/
static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* get_lowest_index_position:
*	Obtém a posição atual do elemento com o menor índice
*	dentro de uma pilha.
*/
int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/* get_target:
*	Escolhe a melhor posição alvo na pilha A para o índice dado de
*	um elemento na pilha B. Primeiro verifica se o índice do elemento B pode
*	ser colocado em algum lugar entre os elementos na pilha A, verificando se
*	existe um elemento na pilha A com um índice maior. Se não, encontra o
*	elemento com o menor índice em A e atribui isso como a posição alvo.
*	--- Exemplo:
*		target_pos começa em INT_MAX
*		Índice B: 3
*		A contém índices: 9 4 2 1 0
*		9 > 3 && 9 < INT_MAX 	: target_pos atualizado para 9
*		4 > 3 && 4 < 9 			: target pos atualizado para 4
*		2 < 3 && 2 < 4			: nenhuma atualização!
*	Então, target_pos precisa ser a posição do índice 4, já que é o
*	índice mais próximo.
*	--- Exemplo:
*		target_pos começa em INT_MAX
*		Índice B: 20
*		A contém índices: 16 4 3
*		16 < 20					: nenhuma atualização! target_pos = INT_MAX
*		4  < 20					: nenhuma atualização! target_pos = INT_MAX
*		3  < 20					: nenhuma atualização! target_pos = INT_MAX
*	... target_pos permanece em INT MAX, é necessário mudar de estratégia.
*		16 < 20					: target_pos atualizado para 20
*		4  < 20					: target_pos atualizado para 4
*		3  < 20					: target_pos atualizado para 3
*	Então, target_pos precisa ser a posição do índice 3, já que esse é o
*	"fim" da pilha.
*/
static int	get_target(t_stack **a, int b_idx, int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* get_target_position:
*	Atribui uma posição alvo na pilha A a cada elemento da pilha B.
*	A posição alvo é o local onde o elemento de B precisa
*	chegar para ser ordenado corretamente. Esta posição será
*	usada para calcular o custo de mover cada elemento para
*	sua posição alvo na pilha A.
*/
void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
