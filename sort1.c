#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

void	print_deq(t_deque *deq_A, t_deque *deq_B)
{
	t_list *cur;
	t_list *cur2;
	int		size;
	int		size2;
	int		rest;

	cur = deq_A->top;
	cur2 = deq_B->top;
	size = deq_A->size;
	rest = absol(size - deq_B->size);
	if (deq_A->size > deq_B->size)
		size = deq_B->size;
	printf("----------deq----------\n");
	printf("deq_A size : %d, deq_B size : %d\n", deq_A->size, deq_B->size);
	while (size--)
	{
		printf("data : %-d  %-d\n", cur->data, cur2->data);
		cur = cur->next;
		cur2 = cur2->next;
		if (cur == 0 || cur2 == 0)
			break;
	}
	if (deq_A->size < deq_B->size)
	{
		while (rest--)
		{
			printf("data : ' ' %-d\n", cur2->data);
			cur2 = cur2->next;
		}
	}
	else
	{
		while (rest--)
		{
			printf("data : %-d ' '\n", cur->data);
			cur = cur->next;
		}
	}
}

void	print_base(t_info *info)
{
	t_base_list *cur;

	cur = info->base->top;
	printf("----base----\n");
	while (cur)
	{
		printf("base : %d\n", cur->data);
		cur = cur->prev;
	}
	printf("last base : %d\n", info->base->last);
}

void	except_sort(t_deque *deq_A, int size, t_cmd_deq *cmd_list)
{
	if (size == 1)
		return ;
	if (size == 2)
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

int		check_except_A(t_deque *deq_A, int nbase, t_info *info)
{
	t_list	*cur;
	int		len;
	int		i;

	cur = deq_A->top;
	if (cur == 0)
		return (1);
	len = 0;
	i = -1;
	while (cur->data != nbase)
	{
		len++;
		cur = cur->next;
	}
	if (len > 3)
		return (1);
	else
		except_sort(deq_A, len, info->cmd);
	return (0);
}

int		check_except_B(t_deque *deq_A, t_deque *deq_B, int nbase, t_info *info)
{
	t_list	*cur;
	int		len;
	int		i;

	cur = deq_B->top;
	if (cur == 0)
		return (0);
	len = 0;
	i = -1;
	while (cur->data != nbase)
	{
		len++;
		cur = cur->next;
	}
	if (len > 3)
		return (0);
	else
	{
		while (++i < len)
			pa(deq_A, deq_B, info->cmd);
		except_sort(deq_A, len, info->cmd);
	}
	return (1);
}

void	divide_B(t_deque *deq_A, t_deque *deq_B, t_info *info, int nbase)
{
	int	*cnt;

	if (check_except_B(deq_A, deq_B, info->piv.sml, info))
	{
		push_base(info->base, info->piv.sml);
		return ;
	}
	cnt = (int *)malloc(2 * sizeof(int));
	ft_memset(cnt, 0, 2 * sizeof(int));
	while (deq_B->top->data != nbase)
	{
		if (deq_B->top->data < info->piv.sml)
			cnt[1] += rb(deq_B, info->cmd);
		else
		{
			pa(deq_A, deq_B, info->cmd);
			if (deq_A->top->data >= info->piv.big)
					cnt[0] += ra(deq_A, info->cmd);
		}
	}
	reverse_stack(deq_A, deq_B, info, cnt);
	free(cnt);
}

void	reverse_stack(t_deque *deq_A, t_deque *deq_B, t_info *info, int *cnt)
{
	t_base_list *tmp;
	int	rest;
	int	i;

	i = -1;
	rest = absol(cnt[0] - cnt[1]);
	push_base(info->base, deq_B->top->data);
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
			rrb(deq_B, info->cmd);
	}
	push_base(info->base, deq_B->top->data);
	if (deq_B->case_num == 1)
	{
		tmp = create_base_list();
		tmp->next = info->base->top;
		info->base->top->prev = tmp;
		tmp->data = deq_B->bot->data;
		info->base->last = deq_B->bot->data;
		info->base->top = tmp;
		deq_B->case_num = 3;
	}
}

void	A_to_B(t_deque *deq_A, t_deque *deq_B, t_info *info, int nbase)
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
	int	cnt[2];
	int	rest;

	ft_memset(cnt, 0, sizeof(int) * 2);
	if (check_except_A(deq_A, nbase, info))
	{
		pre_sort(deq_A, nbase, &(info->piv));
		printf("top %d, bot %d\n", deq_A->top->data, nbase);
		printf("big %d, sml %d\n", info->piv.big, info->piv.sml);
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
		//여기서 b의 top을 base에 넣어줘야 하는데
		//그 다음 a to b에서 꼬이게 됨.
		reverse_stack(deq_A, deq_B, info, cnt);
		if (cnt[0] <= 3)
		{
			except_sort(deq_A, cnt[0], info->cmd);
			return ;
		}
		A_to_B(deq_A, deq_B, info, nbase);
	}
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
	int	nbase_A;
	int	*cnt;

	if (deq_B->size <= 0)
		return ;
	nbase = pop_base(info->base);
	if (nbase == deq_B->top->data)
		nbase = pop_base(info->base);
	if (nbase == info->base->last)
		deq_B->case_num = 1;
	printf("nbase : %d\n", nbase);
	if (!check_except_B(deq_A, deq_B, nbase, info))
	{
		//쪼갠 뒤 a로 넘기는 길이가 3 이하인 경우도 처리해야 함.
		pre_sort(deq_B, nbase, &(info->piv));
		nbase_A = deq_A->top->data;
		divide_B(deq_A, deq_B, info, nbase);
		A_to_B(deq_A, deq_B, info, nbase_A);
	}
	//printf("big : %d  sml : %d\n", info->piv.big, info->piv.sml);
	print_base(info);
	print_deq(deq_A, deq_B);
	B_to_A(deq_A, deq_B, info);
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
		if (base->top->data == input)
			return ;
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
	t_base_list	*bot;

	base = info->base;
	bot = 0;
	if (base->top == 0)
	{
		base->top = create_base_list();
		base->top->data = deq_B->top->data;
		bot = create_base_list();
		bot->next = base->top;
		base->top->prev = bot;
	}
	else
		push_base(base, deq_B->top->data);
	while (rb_cnt--)
		rrb(deq_B, info->cmd);
	push_base(base, deq_B->top->data);
	if (bot)
	{
		bot->data = deq_B->bot->data;
		base->last = bot->data;
	}
}
//-------------------------
void	first_sort(t_deque *deq_A, t_deque *deq_B, t_info *info)
{
	//이 A_to_B는 ra후 rra가 필요 없음
	//스택A에 정렬된 블록이 없기 때문
	t_list	*cur;
	int		rb_cnt;
	int		size;
	if (deq_A->size <= 3)
	{
		size = deq_A->size;
		except_sort(deq_A, size, info->cmd);
		deq_A->case_num = 3;
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
	// printf("---first----\n");
	// print_deq(deq_A, deq_B);
	// print_base(info);
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