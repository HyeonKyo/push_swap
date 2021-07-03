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

// int	arr_len(char *str)
// {
// 	int		i;
// 	int		len;
// 	char	sp;

// 	i = 0;
// 	len = 0;
// 	sp = ' ';
// 	while (str[i])
// 	{
// 		if (str[i] == sp)
// 			i++;
// 		if (str[i] == 0)
// 			break ;
// 		while (ft_isdigit(str[i]))
// 			i++;
// 		len++;
// 	}
// 	return (len);
// }

t_list	*insert_data(char *str, int *len)
{
	int		i;
	int		num;
	char	sp;
	t_list	*head;
	t_list	*cur;

	i = 0;
	sp = ' ';
	head = create_list();
	cur = head;
	while (str[i])
	{
		if (str[i] == sp)
			i++;
		if (str[i] == 0)
			break ;
		num = 0;
		while (ft_isdigit(str[i]))
			num = num * 10 + (str[i++] - '0');
		cur->data = num;
	}
	return (arr);
}

int	*check_dup_num(char *str, int *len)
{
	int	i;
	int	j;
	int	*arr;

	arr = change_type(str, len);
	free(str);
	if (arr == 0)
		return (0);
	i = -1;
	while (++i + 1 < *len)
	{
		j = i + 1;
		while (j < *len)
		{
			if (arr[i] == arr[j++])
			{
				free(arr);
				return (0);
			}
		}
	}
	return (arr);
}

int	*check_input(int ac, char **av)
{
	char	*str;
	int		len;
	int		*arr;

	if (!check_insert(ac, av))
		return (0);
	str = merge_input(ac, av);
	if (str == 0)
		return (0);
	len = 0;
	arr = check_dup_num(str, &len);
	if (arr == 0)
		return (0);
	return (arr);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac <= 2)//ac = 2 -> 숫자 1개 들어옴 -> 아무 명령도 출력 x
		return (0);
	if (!merge_input(ac, av))
		return (0);
	join();
	sort();
}