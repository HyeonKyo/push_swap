#include "ft_utils.h"
#include "ft_type.h"
//1. 숫자와 스페이스만 있는지
//2. 숫자가 하나라도 있는지
int	check_insert(int ac, char **argv)
{
	int	i;
	int	j;
	int	fg;

	i = -1;
	while (++i < ac)
	{
		j = 0;
		fg = 0;
		if (argv[i][j] == 0)
			return (0);
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) || ft_isspace(argv[i][j]))
			{
				if (ft_isdigit(argv[i][j]))
					fg = 1;
				j++;
			}
			else
				return (0);
		}
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

	i = 3;
	str = 0;
	str = ft_strjoin(av[1], av[2]);
	while (i <= ac)
	{
		tmp = ft_strdup(str);
		free(str);
		str = strjoin(tmp, av[i + 1]);
		if (tmp)
			free(tmp);
		if (str == 0)
			return (0);
	}
	return (str);
}

t_deque	*insert_data(char *str)
{
	int		i;
	int		num;
	char	sp;
	t_deque	*deq;

	i = 0;
	sp = ' ';
	deq = create_deque();
	if (deq == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == sp)
			i++;
		if (str[i] == 0)
			break ;
		num = 0;
		while (ft_isdigit(str[i]))
			num = num * 10 + (str[i++] - '0');
		fillin_deque(deq, num);
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
	cur = deq->header;
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

int	main(int ac, char **av)
{
	int		i;
	t_deque	*deq;

	if (ac <= 2)//ac = 2 -> 숫자 1개 들어옴 -> 아무 명령도 출력 x
		return (0);
	deq = check_input(ac, av);
	if (deq == 0)
		return (0);
	join();
	sort();
}