#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include <stdio.h>

t_list	*create_list(void)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == 0)
		return (0);
	ft_memset(lst, 0, sizeof(t_list));
	return (lst);
}

t_deque	*create_deque(void)
{
	t_deque	*deq;

	deq = (t_deque *)malloc(sizeof(t_deque));
	if (deq == 0)
		return (0);
	ft_memset(deq, 0, sizeof(t_deque));
	deq->top = create_list();
	deq->bot = 0;
	deq->size = 1;
	return (deq);
}

void	fillin_deque(t_deque *deq, int num)
{
	t_list	*tmp;

	if (deq->bot == 0)
	{
		deq->top->data = num;
		deq->bot = deq->top;
		return ;
	}
	tmp = deq->bot;
	deq->bot->next = create_list();
	deq->bot = deq->bot->next;
	deq->bot->prev = tmp;
	deq->bot->data = num;	
	deq->size++;
}

t_deque	*create_deque_B(int size)
{
	//deq_A와 길이는 같고, 데이터는 0이 들어간 덱 생성
	t_deque	*deq_B;

	deq_B = create_deque();
	if (deq_B == 0)
		return (0);
	while (deq_B->size < size)
		fillin_deque(deq_B, 0);
	return (deq_B);
}

void	clear_deque(t_deque *deq)
{
	t_list	*cur;
	t_list	*tmp;

	cur = deq->top;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = 0;
	}
	free(deq);
}

void	del_top_node(t_deque *deq)
{
	t_list	*tmp;

	tmp = deq->top;
	deq->top = deq->top->next;
	free(tmp);
	deq->top->prev = 0;
	return ;
}

void	del_bottom_node(t_deque *deq)
{
	t_list	*tmp;

	tmp = deq->bot;
	deq->bot = deq->bot->prev;
	free(tmp);
	deq->bot->next = 0;
	return ;
}