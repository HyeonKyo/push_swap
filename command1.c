/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:15 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:16 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_type.h"
#include "list.h"

void	sa(t_deque *deq_A, t_cd_deq *cmd_list)
{
	int	tmp;

	tmp = deq_A->top->data;
	deq_A->top->data = deq_A->top->next->data;
	deq_A->top->next->data = tmp;
	add_command(2, "sa", cmd_list);
}

void	sb(t_deque *deq_B, t_cd_deq *cmd_list)
{
	int	tmp;

	tmp = deq_B->top->data;
	deq_B->top->data = deq_B->top->next->data;
	deq_B->top->next->data = tmp;
	add_command(2, "sb", cmd_list);
}

void	ss(t_deque *deq_A, t_deque *deq_B, t_cd_deq *cmd_list)
{
	int	tmp;

	tmp = deq_A->top->data;
	deq_A->top->data = deq_A->top->next->data;
	deq_A->top->next->data = tmp;
	tmp = deq_B->top->data;
	deq_B->top->data = deq_B->top->next->data;
	deq_B->top->next->data = tmp;
	add_command(2, "ss", cmd_list);
}

void	pa(t_deque *deq_A, t_deque *deq_B, t_cd_deq *cmd_list)
{
	t_list	*tmp;

	deq_A->top->prev = create_list();
	tmp = deq_A->top;
	deq_A->top = deq_A->top->prev;
	deq_A->top->next = tmp;
	deq_A->top->data = deq_B->top->data;
	del_top_node(deq_B);
	add_command(2, "pa", cmd_list);
}

void	pb(t_deque *deq_A, t_deque *deq_B, t_cd_deq *cmd_list)
{
	t_list	*tmp;

	deq_B->top->prev = create_list();
	tmp = deq_B->top;
	deq_B->top = deq_B->top->prev;
	deq_B->top->next = tmp;
	deq_B->top->data = deq_A->top->data;
	del_top_node(deq_A);
	add_command(2, "pb", cmd_list);
}
