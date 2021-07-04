#include "ft_utils.h"
#include "ft_type.h"
#include "list.h"
#include <stdio.h>
//1. 숫자와 스페이스만 있는지
//2. 숫자가 하나라도 있는지
int	vaild_input(char *argv, int *fg)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (ft_isdigit(argv[i]) || argv[i] == ' ')
		{
			if (ft_isdigit(argv[i]))
				*fg = 1;
		}
		else if (argv[i++] == '-')
		{
			if (!ft_isdigit(argv[i]))
				return (0);//에러메시지 출력되면 error로
			else
				*fg = 1;
		}
		else
			error();
	}
	return (1);
}

int	check_insert(int ac, char **argv)
{
	int	i;
	int	j;
	int	fg;

	i = 0;
	while (++i < ac)
	{
		fg = 0;
		if (!vaild_input(argv[i], &fg))
			return (0);//위 함수가 전부 exit종료면 if문 제거
		if (fg == 0)
			return (0);
	}
	return (1);
}

char	*merge_input(int ac, char **av)
{
/*
1. strjoin 반복으로 자동 할당 하면서 합쳐줌
3. 만약 문제가 있으면(말락실패) 리턴 0
4. 문제 없으면 합친 문자열 리턴
*/
	int		i;
	char	*str;
	char	*tmp;

	i = 2;
	str = ft_strjoin(av[1], av[2]);
	while (++i < ac)
	{
		tmp = ft_strdup(str);
		free(str);
		str = ft_strjoin(tmp, av[i]);
		if (tmp)
			free(tmp);
		if (str == 0)//말락에러
			return (0);
	}
	return (str);
}

unsigned int	absol(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	ps_atoi(int *idx, int sign, char *str, t_deque *deq)
{
	long long	num;
	int			len;

	num = 0;
	len = 0;
	if (str[*idx] == 0)
		return (1);
	while (ft_isdigit(str[*idx]))
	{
		len++;
		num = num * 10 + (absol(str[(*idx)++]) - '0');
	}
	num = num * sign;
	if (len > 10 || num < -2147483648 || num > 2147483647)
		error();
	fillin_deque(deq, (int)num);
	return (1);
}

t_deque	*insert_data(char *str)
{
	int		i;
	int		sign;
	t_deque	*deq;

	i = 0;
	deq = create_deque();
	if (deq == 0)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == 0)
			break ;
		sign = 1;
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		ps_atoi(&i, sign, str, deq);
	}
	free(str);
	return (deq);
}

t_deque	*check_dup_num(char *str)
{
	int		ck_num;
	t_list	*cur;
	t_list	*tmp;
	t_deque	*deq;

	deq = insert_data(str);
	if (deq == 0)
		return (0);
	cur = deq->top;
	while (cur)
	{
		ck_num = cur->data;
		tmp = cur->next;
		while (tmp)
		{
			if (tmp->data == ck_num)
			{
				clear_deque(deq);
				return (0);
			}
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return (deq);
}

t_deque	*check_input(int ac, char **av)
{
	char	*str;
	t_deque	*deq;

	if (!check_insert(ac, av))
		return (0);
	str = merge_input(ac, av);
	if (str == 0)
		return (0);
	deq = check_dup_num(str);
	if (deq == 0)
		return (0);
	return (deq);
}

int	make_stack(int ac, char **av, t_deque **deq_A, t_deque **deq_B)
{
	*deq_A = check_input(ac, av);
	if (*deq_A == 0)
		return (0);
	*deq_B = create_deque_B((*deq_A)->size);
	printf("----1---\n");
	if (*deq_B == 0)
	{
		clear_deque(*deq_A);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_deque	*deq_A;
	t_deque	*deq_B;
	t_list	*cur;
	t_list	*cur_B;

	if (ac <= 2)//ac = 2 -> 숫자 1개 들어옴 -> 아무 명령도 출력 x
		return (1);
	if (!make_stack(ac, av, &deq_A, &deq_B))
		return (1);
	//sort(deq_A, deq_B);
	cur = deq_A->top;
	printf("B->size : %d\n", deq_B->size);
	printf("B->top : %p\n", deq_B->top);
	printf("B->bot : %p\n", deq_B->bot);
	cur_B = deq_B->top;
	while (cur)
	{
		printf("----3---\n");
		printf("\nA: %d\n", cur->data);
		printf("B: %d\n", cur_B->data);
		cur = cur->next;
		cur_B = cur_B->next;
	}
	printf("----3---\n");
	printf("\nA_size: %d\n", deq_A->size);
	printf("\nB_size: %d\n", deq_B->size);
	clear_deque(deq_A);
	clear_deque(deq_B);
	return (0);
}