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

t_deque	*dup_deque(t_deque *deq)
{
	//deq_A와 길이는 같고, 데이터는 0이 들어간 덱 생성
	t_list	*dst;
	t_list	*src;
	t_list	*tmp;
	t_deque	*dup;

	dup = (t_deque *)malloc(sizeof(t_deque));
	if (dup == 0)
		return (0);
	dup->top = create_list();
	dst = dup->top;
	src = deq->top->next;
	dst->data = 0;
	dup->size = 1;
	while (src)
	{
		dst->next = create_list();
		tmp = dst;
		dst = dst->next;
		dst->prev = tmp;
		dst->data = 0;
		dup->size++;
		src = src->next;
	}
	dup->bot = dst;
	return (dup);
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
