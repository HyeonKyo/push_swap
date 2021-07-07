#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

void	print_deq(t_deque *deq)
{
	t_list *cur;
	int		size;

	cur = deq->top;
	size = deq->size;
	while (size--)
	{
		//printf("%d\n", cur->data);
		cur = cur->next;
	}
}

void	except_sort(t_deque *deq_A, t_cmd_deq *cmd_list)
{
	if (deq_A->size == 1)
		return ;
	if (deq_A->size == 2)
	{
		if (deq_A->top->data > deq_A->top->next->data)
			sa(deq_A, cmd_list);
	}
	else
	{
		if (deq_A->top->data > deq_A->top->next->data)
			sa(deq_A, cmd_list);
		ra(deq_A, cmd_list);
		if (deq_A->top->data > deq_A->top->next->data)
			sa(deq_A, cmd_list);
		rra(deq_A, cmd_list);
	}
}

int	divide_B(t_deque *deq_A, t_deque *deq_B, t_info *info, int nbase)
{
	int	ra_cnt;
	int	rb_cnt;

	ra_cnt = 0;
	rb_cnt = 0;
	while (deq_B->top->data != nbase)
	{
		if (deq_B->top->data < info->piv.sml)
			rb_cnt = rb(deq_B, info->cmd);
		else
		{
			pa(deq_A, deq_B, info->cmd);
			if (deq_A->top->data >= info->piv.big)
					ra_cnt += ra(deq_A, info->cmd);
		}
	}
	//***여기가 문제임, ra_cnt가 항상 rb_cnt보다 크지 않음
	ra_cnt -= rb_cnt;
	while (rb_cnt--)
		rrr(deq_A, deq_B, info->cmd);
	return (ra_cnt);
}

void	reverse_stack(t_deque *deq_A, t_deque *deq_B, t_info *info, int *cnt)
{
	int	rest;
	int	i;

	i = -1;
	rest = absol(cnt[0] - cnt[1]);
	if (cnt[0] >= cnt[1])
	{
		while (++i < cnt[1])
			rrr(deq_A, deq_B, info->cmd);
		i = -1;
		while (++i < rest)
			rra(deq_A, info->cmd);
	}
	else
	{
		while (++i < cnt[0])
			rrr(deq_A, deq_B, info->cmd);
		i = -1;
		while (++i < rest)
			rrb(deq_A, info->cmd);
	}
}

void	A_to_B(t_deque *deq_A, t_deque *deq_B, t_info *info)
{
	/*
	1. nbase에 basetop pop
	2. case3의 pivot 선정
	3. A의 top ~ nbase까지 퀵소트 진행
	top >= pbig ra c
	top < pbig pb a
	b_top >= psml rb b
	rrr => ra_cnt rb_cnt 대소 비교
	*/
	int	nbase;
	int	cnt[2];
	int	rest;

	ft_memset(cnt, 0, sizeof(int) * 2);
	nbase = pop_base(info->base);
	pre_sort(deq_A, nbase, &(info->piv));
	while (deq_A->top->data != nbase)
	{
		if (deq_A->top->data >= info->piv.big)
			cnt[0] += ra(deq_A, info->cmd);
		else
		{
			pb(deq_A, deq_B, info->cmd);
			if (deq_B->top->data >= info->piv.sml)
				cnt[1] += rb(deq_B, info->cmd);
		}
	}
	reverse_stack(deq_A, deq_B, info, cnt);
	if (cnt[0] <= 3)
	{
		except_sort(deq_A, info->cmd);
		return ;
	}
	push_base(info->base, deq_A->top->data);
	A_to_B(deq_A, deq_B, info);
}

void	B_to_A(t_deque *deq_A, t_deque *deq_B, t_info *info)
{
	//1. top부터 base의 pop데이터 전까지가 쪼갤 블록임
	//		만약 deq_B의 top과 base pop이 같다면 다음 base pop으로
	//2. 그 블록의 최적 피봇 구함
	//3. base에 deq_A의 top값 push
	//3. 가장 큰 블록은 pa, pa_cnt
	//4. 중간 블록은 pa, ra, ra_cnt, pa_cnt
	//5. 가장 작은 블록은 rb, rb_cnt
	int	nbase;
	int	ra_cnt;

	printf("----a----\n");
	if (deq_B->size <= 0)
		return ;
	printf("----b----\n");
	nbase = pop_base(info->base);
	printf("----c----\n");
	if (nbase == deq_B->top->data)
		nbase = pop_base(info->base);
	printf("----d----\n");
	if (nbase == info->base->last)
		deq_B->case_num = 1;
	printf("----1----\n");
	pre_sort(deq_B, nbase, &(info->piv));
	printf("---------\n");
	push_base(info->base, deq_A->top->data);
	printf("---------\n");
	ra_cnt = divide_B(deq_A, deq_B, info, nbase);
	printf("ra_cnt : %d\n", ra_cnt);
	printf("---------\n");
	while (ra_cnt--)
		rra(deq_A, info->cmd);
	printf("---------\n");
	A_to_B(deq_A, deq_B, info);
	printf("---------\n");
	B_to_A(deq_A, deq_B, info);
	printf("-----2---\n");
}

int	divide_A(t_deque *deq_A, t_deque *deq_B, t_info *info)
{
	int	n;
	int	rb_cnt;

	n = deq_A->size;
	rb_cnt = 0;
	while (n--)
	{
		if (deq_A->top->data >= info->piv.big)
			ra(deq_A, info->cmd);
		else
		{
			pb(deq_A, deq_B, info->cmd);
			if (deq_B->size != 0)
			{
				if (deq_B->top->data >= info->piv.sml)
					rb_cnt += rb(deq_B, info->cmd);
			}
			else
				if (deq_B->top->data < info->piv.sml)
					rb(deq_B, info->cmd);
		}
	}
	return (rb_cnt);
}
//----------base----------
t_base_list	*create_base_list(void)
{
	t_base_list	*lst;

	lst = (t_base_list *)malloc(sizeof(t_base_list));
	if (lst == 0)
		merror();
	ft_memset(lst, 0, sizeof(t_base_list));
	return (lst);
}

int		pop_base(t_base *base)
{
	int	data;
	t_base_list	*tmp;
	if (base->top == 0)
		return (0);
	data = base->top->data;
	tmp = base->top;
	base->top = base->top->prev;
	free(tmp);
	if (base->top)
		base->top->next = 0;
	return (data);
}

void	push_base(t_base *base, int input)
{
	if (base->top)
	{
		base->top->next = create_base_list();
		base->top->next->data = input;
		base->top->next->prev = base->top;
		base->top = base->top->next;
	}
	else
	{
		base->top = create_base_list();
		base->top->data = input;
		base->last = input;
	}
	
}

void	add_base(t_deque *deq_B, t_info *info, int rb_cnt)
{
	t_base	*base;

	base = info->base;
	if (base->top == 0)
	{
		base->top = create_base_list();
		base->top->data = deq_B->bot->data;
		base->last = deq_B->bot->data;
		base->top->next = create_base_list();
		base->top = base->top->next;
		base->top->data = deq_B->top->data;
	}
	else
		push_base(base, deq_B->top->data);
	while (rb_cnt--)
		rrb(deq_B, info->cmd);
	push_base(base, deq_B->top->data);
}
//-------------------------
void	first_sort(t_deque *deq_A, t_deque *deq_B, t_info *info)
{
	//이 A_to_B는 ra후 rra가 필요 없음
	//스택A에 정렬된 블록이 없기 때문
	t_list	*cur;
	int		rb_cnt;

	if (deq_A->size <= 3)
	{
		except_sort(deq_A, info->cmd);
		deq_A->case_num = 3;
		//B_to_A(deq_A, deq_B, info);
		return ;
	}
	pre_sort(deq_A, deq_A->bot->data, &(info->piv));
	rb_cnt = divide_A(deq_A, deq_B, info);
	add_base(deq_B, info, rb_cnt);
	first_sort(deq_A, deq_B, info);
}

void	q_sort(t_deque *deq_A, t_deque *deq_B, t_info *info)
{
	t_base_list *cur;

	first_sort(deq_A, deq_B, info);
	cur = info->base->top;
	while (cur)
	{
		printf("base : %d\n", cur->data);
		cur = cur->prev;
	}
	B_to_A(deq_A, deq_B, info);
}

void	sort(t_deque *deq_A, t_deque *deq_B)
{
	t_info	info;

	ft_memset(&info, 0, sizeof(t_info));
	setup_info(&info);
	q_sort(deq_A, deq_B, &info);
	//optimizing_cmd();
	//print_cmd(info.cmd);
}