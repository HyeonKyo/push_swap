#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

int	check_stack(t_deque *deq, int base, int *max, int *min)
{
	int	len;
	t_list	*cur;

	*max = -2147483648;
	*min = 2147483647;
	cur = deq->top;
	len = 1;
	while (cur)
	{
		if (cur->data == base)//기준 값 포함하지 않을 때
			break ;
		if (cur->data > *max)
			*max = cur->data;
		if (cur->data < *min)
			*min = cur->data;
		len++;
		cur = cur->next;
	}
	return (len);
}

t_sort	*make_repo(int len)
{
	t_sort	*repo;

	repo = (t_sort *)malloc(sizeof(t_sort) * 1);
	if (repo == 0)
		merror();
	repo->arr = (long long *)malloc(sizeof(long long) * len);
	if (repo->arr == 0)
		merror();
	repo->size = len;
	return (repo);
}

int		find_digit(t_ll num)
{
	int	digit;

	digit = 0;
	while (num > 0)
	{
		num = num / 10;
		digit++;
	}
	return (digit);
}

int		return_last_num(long long n, int dg)
{
	int	i;

	i = 0;
	while (++i < dg)
		n /= 10;
	return ((int)(n % 10));
}

void	make_queue(t_queue *queue[10], int idx)
{
	queue[idx] = (t_queue *)malloc(sizeof(t_queue));
	queue[idx]->fst = (t_qu_lst *)malloc(sizeof(t_qu_lst));
	queue[idx]->last = queue[idx]->fst;
	queue[idx]->size = 0; 
	ft_memset(queue[idx]->fst, 0, sizeof(t_qu_lst));
}
