#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

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
	int	n;
	int	ra_cnt;
	int	rb_cnt;

	n = nbase;
	ra_cnt = 0;
	rb_cnt = 0;
	while (deq_B->top->data != nbase)
	{
		if (deq_B->top->data < info->piv.sml)
			rb_cnt = rb(deq_A, info->cmd);
		else
		{
			pa(deq_A, deq_B, info->cmd);
			if (deq_A->top->data >= info->piv.big)
					ra_cnt += ra(deq_B, info->cmd);
		}
	}
	ra_cnt -= rb_cnt;
	while (rb_cnt--)
		rrr(deq_A, deq_B, info->cmd);
	return (ra_cnt);
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

	if (deq_B->size == 0)
		return ;
	nbase = pop_base(info->base);
	if (nbase == deq_B->top->data)
		nbase = pop_base(info->base);
	pre_sort(deq_B, nbase, &(info->piv));
	push_base(info->base, deq_A->top->data);
	ra_cnt = divide_B(deq_A, deq_B, info, nbase);
	while (ra_cnt--)
		rra(deq_A, info->cmd);
	A_to_B();
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
				if (deq_B->top->data >= info->piv.sml)
					rb_cnt += rb(deq_B, info->cmd);
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

	data = base->top->data;
	tmp = base->top;
	base->top = base->top->prev;
	free(tmp);
	base->top->next = 0;
	return (data);
}

void	push_base(t_base *base, int input)
{
	base->top->next = create_base_list();
	base->top->next->data = input;
	base->top->next->prev = base->top;
	base->top = base->top->next;
}

void	add_base(t_deque *deq_B, t_info *info, int rb_cnt)
{
	t_base	*base;

	base = info->base;
	if (base->top == 0)
	{
		base->top = create_base_list();
		base->top->data = deq_B->top->data;
	}
	else
		push_base(base, deq_B->top->data);
	while (rb_cnt--)
		rrb(deq_B, info->cmd);
	push_base(base, deq_B->top->data);
}
//-------------------------
void	sorting(t_deque *deq_A, t_deque *deq_B, t_info *info)
{
	//이 A_to_B는 ra후 rra가 필요 없음
	//스택A에 정렬된 블록이 없기 때문
	t_list	*cur;
	int		rb_cnt;

	if (deq_A->size <= 3)
	{
		except_sort(deq_A, info->cmd);
		deq_A->case_num = 3;
		B_to_A();
		return ;
	}
	pre_sort(deq_A, deq_A->bot->data, &(info->piv));
	rb_cnt = divide_A(deq_A, deq_B, info);
	add_base(deq_B, info->cmd, rb_cnt);
	sorting(deq_A, deq_B, info);
}

void	q_sort(t_deque *deq_A, t_deque *deq_B, t_info *info)
{
	info->base->top = 0;
	sorting(deq_A, deq_B, info);
}

void	sort(t_deque *deq_A, t_deque *deq_B)
{
	t_info	info;

	ft_memset(&info, 0, sizeof(t_info));
	setup_cmd_list(info.cmd);
	q_sort(deq_A, deq_B, &info);
	optimizing_cmd();
	print_cmd(info.cmd);
}