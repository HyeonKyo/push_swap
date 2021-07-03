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
	deq->header = create_list();
	deq->tailer = deq->header;
	deq->size = 1;
	return (deq);
}

void	fillin_deque(t_deque *deq, int num)
{
	t_list	*tmp;
printf("------4------\n");
printf("tailer : %p\n", deq->tailer);
	deq->tailer->data = num;
	printf("------4------\n");
	deq->tailer->next = create_list();
	printf("------4------\n");
	tmp = deq->tailer;
	printf("------4------\n");
	deq->tailer = deq->tailer->next;
	printf("------4------\n");
	deq->tailer->prev = tmp;
	printf("------4------\n");
	deq->size++;
	printf("------4------\n");
}

void	clear_deque(t_deque *deq)
{
	t_list	*cur;
	t_list	*tmp;

	cur = deq->header;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = 0;
	}
	free(deq);
}
