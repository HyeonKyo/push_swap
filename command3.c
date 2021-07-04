#include "ft_utils.h"
#include "ft_type.h"
#include "list.h"

void	rra(t_deque *deq_A, t_cd_deq *cmd_list)
{
	t_list	*cur;

	cur = create_list();
	deq_A->top->prev = cur;
	cur->next = deq_A->top;
	cur->data = deq_A->bot->data;
	del_bottom_node(deq_A);
	deq_A->top = cur;
	add_command(3, "rra", cmd_list);
}

void	rrb(t_deque *deq_B, t_cd_deq *cmd_list)
{
	t_list	*cur;

	cur = create_list();
	deq_B->top->prev = cur;
	cur->next = deq_B->top;
	cur->data = deq_B->bot->data;
	del_bottom_node(deq_B);
	deq_B->top = cur;
	add_command(3, "rrb", cmd_list);
}

void	rrr(t_deque *deq_A, t_deque *deq_B, t_cd_deq *cmd_list)
{
	t_list	*cur;

	cur = create_list();
	deq_A->top->prev = cur;
	cur->next = deq_A->top;
	cur->data = deq_A->bot->data;
	del_bottom_node(deq_A);
	deq_A->top = cur;
	cur = create_list();
	deq_B->top->prev = cur;
	cur->next = deq_B->top;
	cur->data = deq_B->bot->data;
	del_bottom_node(deq_B);
	deq_B->top = cur;
	add_command(3, "rrr", cmd_list);
}