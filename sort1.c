#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

int		check_already_sorted(t_deque *deq)
{
	t_list	*cur;

	if (deq == 0)
		return (0);
	cur = deq->top;
	while (cur->next)
	{
		if (cur->data > cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);//정렬되있는 상태
}

int		check_reverse_sorted(t_deque *deq_A, int len)
{
	int		i;
	int		check_num;
	t_list	*cur;

	if (len < 6)
		return (0);
	cur = deq_A->top;
	check_num = cur->data;
	i = -1;
	while (++i < len - 1)
	{
		if (check_num < cur->next->data)
			return (0);
		check_num = cur->next->data;
		cur = cur->next;
	}
	return (1);
}

int		sorting_reverse(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd, int len)
{
	int		i;
	t_list	*cur;

	if (!check_reverse_sorted(deq_A, len))
		return (0);
	i = -1;
	while (++i < len - 1)
	{
		rra(deq_A, cmd);
		pb(deq_A, deq_B, cmd);
	}
	i = -1;
	while (++i < len - 1)
		pa(deq_A, deq_B, cmd);
	if (deq_A->case_num == 1)
		deq_A->case_num = 3;
	return (1);
}

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

int		find_max(int n1, int n2, int n3)
{
	if (n1 > n2)
	{
		if (n1 > n3)
			return (n1);
		else
			return (n3);
	}
	else
		if (n2 > n3)
			return (n2);
	return (n3);
}

void	real_three_number_sort(t_deque *deq_A, t_cmd_deq *cmd_list)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = deq_A->top->data;
	n2 = deq_A->top->next->data;
	n3 = deq_A->bot->data;
	if (n1 == find_max(n1, n2, n3))
		ra(deq_A, cmd_list);
	else if (n2 == find_max(n1, n2, n3))
		rra(deq_A, cmd_list);
	if (deq_A->top->data > deq_A->top->next->data)
		sa(deq_A, cmd_list);
}

void	except_sort(t_deque *deq_A, int len, t_cmd_deq *cmd_list)
{
	if (check_already_sorted(deq_A))
		return ;
	if (len == 1)
		return ;
	if (len == 2)
	{
		if (deq_A->top->data > deq_A->top->next->data)
			sa(deq_A, cmd_list);
	}
	else
	{
		if (deq_A->size == 3)
			real_three_number_sort(deq_A, cmd_list);
		if (deq_A->top->data > deq_A->top->next->data)
			sa(deq_A, cmd_list);
		ra(deq_A, cmd_list);
		if (deq_A->top->data > deq_A->top->next->data)
			sa(deq_A, cmd_list);
		rra(deq_A, cmd_list);
		if (deq_A->top->data > deq_A->top->next->data)
			sa(deq_A, cmd_list);
	}
}

void	divide_B(t_deque *deq_A, t_deque *deq_B, t_info *info, int len)
{
	ft_memset(info->cnt, 0, sizeof(int) * 4);
	if (len <= 0)
		return ;
	while (len--)
	{
		if (deq_B->top->data < info->piv.sml)
			info->cnt[1] += rb(deq_B, info->cmd);
		else
		{
			info->cnt[2] += pa(deq_A, deq_B, info->cmd);
			if (deq_A->top->data < info->piv.big)
				info->cnt[0] += ra(deq_A, info->cmd);
		}
	}
	reverse_stack(deq_A, deq_B, info);
}

int		small_num(int n1, int n2)
{
	if (n1 <= n2)
		return (n1);
	return (n2);
}

void	reverse_stack(t_deque *deq_A, t_deque *deq_B, t_info *info)
{
	int	rest;
	int	com;
	int	i;

	if (deq_A->case_num == 1)
	{
		i = info->cnt[1];
		while (i--)
			rrb(deq_B, info->cmd);
		return ;
	}
	rest = absol(info->cnt[0] - info->cnt[1]);
	com = small_num(info->cnt[0], info->cnt[1]);
	i = -1;
	while (++i < com)
		rrr(deq_A, deq_B, info->cmd);
	i = -1;
	if (info->cnt[0] >= info->cnt[1])
		while (++i < rest)
			rra(deq_A, info->cmd);
	else
		while (++i < rest)
			rrb(deq_B, info->cmd);
}

void	B_to_A(t_deque *deq_A, t_deque *deq_B, t_info *info, int len)
{
	int	i;
	int	pb_cnt;
	int	rb_cnt;
	int	pa_cnt;

	i = -1;
	if (len <= 3)
	{
		while (++i < len)
			pa(deq_A, deq_B, info->cmd);
		except_sort(deq_A, len, info->cmd);
		return ;
	}
	pre_sort(deq_B, len, &(info->piv));
	divide_B(deq_A, deq_B, info, len);
	rb_cnt = info->cnt[1];
	pa_cnt = info->cnt[2];
	A_to_B(deq_A, deq_B, info, pa_cnt);
	while (++i < rb_cnt)
		pa(deq_A, deq_B, info->cmd);
	A_to_B(deq_A, deq_B, info, rb_cnt);
}

void	divide_A(t_deque *deq_A, t_deque *deq_B, t_info *info, int len)
{
	int	n;

	n = len;
	ft_memset(info->cnt, 0, sizeof(int) * 4);
	while (len--)
	{
		if (deq_A->top->data >= info->piv.big)
			info->cnt[0] += ra(deq_A, info->cmd);
		else
		{
			info->cnt[3] += pb(deq_A, deq_B, info->cmd);
			if (deq_B->top->data >= info->piv.sml && n > 6)
				info->cnt[1] += rb(deq_B, info->cmd);
		}
	}
	reverse_stack(deq_A, deq_B, info);
	//cnt[0] = ra
	//cnt[1] = rb
	//cnt[2] = pa
	//cnt[3] = pb
}

void	A_to_B(t_deque *deq_A, t_deque *deq_B, t_info *info, int len)
{
	//초기 len = deq_A->size, 이후 = ra_cnt
	int	ra_cnt;
	int	rb_cnt;
	int	pb_cnt;

	if (check_already_sorted(deq_A) || sorting_reverse(deq_A, deq_B, info->cmd, len))
		return ;
	if (len <= 3)
	{
		deq_A->case_num = 3;
		except_sort(deq_A, len, info->cmd);
		return ;
	}
	pre_sort(deq_A, len, &(info->piv));
	printf("len big sml : %d %d %d\n", len, info->piv.big, info->piv.sml);
	divide_A(deq_A, deq_B, info, len); //ra rb pb카운트
	ra_cnt = info->cnt[0];
	rb_cnt = info->cnt[1];
	pb_cnt = info->cnt[3];
	A_to_B(deq_A, deq_B, info, ra_cnt);
	if (pb_cnt <= 3)
		B_to_A(deq_A, deq_B, info, pb_cnt);
	else
	{
		B_to_A(deq_A, deq_B, info, rb_cnt);
		B_to_A(deq_A, deq_B, info, pb_cnt - rb_cnt);
	}
}

// A_to_B(stack_A, stack_B, info, base)
// {
// 	pb, rb_cnt, info에 cnt구조체 넣어줌.
// 	A스택 정렬 끝나면 재귀 종료
// 		=>정렬해야 할 숫자 개수가 3개 이하일 때(base_len함수 <= 3)
// 			=> 이거 어떻게?, a_to_b의 인자로 base를 넣음
// 			=> 맨 처음 a_to_b base는 stack_A의 bot값
// 		=>except_sort실행 후 return으로 재귀 종료
// 			=>except_sort는 그냥 a스택에 위의 3개 인자를 정렬
// 	정렬 => pb카운트 rb카운트 ra카운트
// 	rb, ra카운트 이용해서 rrr rra rrb적절히 사용
// 	다시 A_to_B
// 	B_to_A(pb, rb_cnt)
// 	{
// 		base는 A->top
// 		rbcnt만큼 3등분 -> 2블록 a로
// 		다시 a_to_b(pa_cnt, base)
// 		base는 A->top
// 		나머지 1/3 a로
// 		다시 a_to_b
// 	}
// 	B_to_A(pb, pb-rb_cnt);
// }

void	q_sort(t_deque *deq_A, t_deque *deq_B, t_info *info)
{
	A_to_B(deq_A, deq_B, info, deq_A->size);
	//print_deq(deq_A, deq_B);
}

void	sort(t_deque *deq_A, t_deque *deq_B)
{
	t_info	info;

	if (check_already_sorted(deq_A))
		exit(0);
	ft_memset(&info, 0, sizeof(t_info));
	setup_info(&info);
	q_sort(deq_A, deq_B, &info);
	printf("cmd len : %d\n", info.cmd->size);
	print_cmd(&info);
	print_deq(deq_A, deq_B);
	//optimizing_cmd();
	//print_cmd(info.cmd);
}