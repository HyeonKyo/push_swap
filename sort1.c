#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

void	except_sort()
{
}

void	B_to_A()
{
	//1. A로 base pop한 숫자의 base만큼 넘겨줌
	//2. A_to_B2 실행
}

int	divide_A(t_deque *deq_A, t_deque *deq_B, t_pivot piv, t_cmd_deq *cmd_list)
{
	int	n;
	int	rb_cnt;

	n = deq_A->size;
	rb_cnt = 0;
	while (n--)
	{
		if (deq_A->top->data > piv.big)
			ra(deq_A, cmd_list);
		else
		{
			pb(deq_A, deq_B, cmd_list);
			if (deq_A->top->data > piv.sml)
			{
				rb(deq_B, cmd_list);
				rb_cnt++;
			}
		}
	}
	return (rb_cnt);
}

t_base_list	*create_base_list(void)
{
	t_base_list	*lst;

	lst = (t_base_list *)malloc(sizeof(t_base_list));
	if (lst == 0)
		merror();
	ft_memset(lst, 0, sizeof(t_base_list));
	return (lst);
}

void	add_base(t_base *base, t_deque *deq_B, t_cmd_lst *cmd_list, int rb_cnt)
{
	if (base->top == 0)
		base->top = create_base_list();
	else
	{
		base->top->next = create_base_list();
		base->top = base->top->next;
	}
	
	base->top->data = deq_B->top->data;
	base->top->next = create_base_list();
	base->top = base->top->next;
	while (rb_cnt--)
		rrb(deq_B, cmd_list);
	base->top->data = deq_B->top->data;
}

void	first_A_to_B(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd_list, t_base *base)
{
	//이 A_to_B는 ra후 rra가 필요 없음
	//스택A에 정렬된 블록이 없기 때문
	t_pivot	piv;
	t_list	*cur;
	int		rb_cnt;

	if (deq_A->size <= 3)
	{
		except_sort();
		B_to_A();
		return ;
	}
	pre_sort(deq_A, deq_A->bot->data, &piv);
	if (deq_B->size == 0)
	{
		//약간 다름
	}
	else
	{
		rb_cnt = divide_A(deq_A, deq_B, piv, cmd_list);
	}
	add_base(base, deq_B, rb_cnt);
	first_A_to_B(deq_A, deq_B, cmd_list, base);
}

void	q_sort(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd_list)
{
	t_base	base;
	first_A_to_B(deq_A, deq_B, cmd_list, &base);
}

void	sort(t_deque *deq_A, t_deque *deq_B)
{
	t_cmd_deq	cmd_list;

	setup_cmd_list(&cmd_list);
	q_sort(deq_A, deq_B, &cmd_list);
	optimizing_cmd();
	print_cmd(cmd_list);
}