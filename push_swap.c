/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:55 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:56 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_type.h"
#include "list.h"
#include "push_swap.h"
#include <stdio.h>
//1. 숫자와 스페이스만 있는지
//2. 숫자가 하나라도 있는지

int	main(int ac, char **av)
{
	t_deque	*deq_A;
	t_deque	*deq_B;
	t_list	*cur;

	if (ac <= 2)//ac = 2 -> 숫자 1개 들어옴 -> 아무 명령도 출력 x
		return (1);
	make_stack(ac, av, &deq_A, &deq_B);
	//pre_sort(deq_A, deq_A->bot->data, &piv);
	//printf("sml : %d, big : %d\n", piv.sml, piv.big);
	sort(deq_A, deq_B);
	cur = deq_A->top;
	for (int i = 0; i < deq_A->size; i++)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	clear_deque(deq_A);
	clear_deque(deq_B);
	return (0);
}
