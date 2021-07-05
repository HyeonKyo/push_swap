#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"

/*
가장 큰 pre_sort함수 (덱, 기준값)
{
	변수 : bios, digit, max, min
1. 덱에서 선정렬할 블록 길이 재고, max, min값 측정하는 함수
인자 : 덱, 기준값, max주소, min주소 / 초기min값은 정수 최대, max는 정수 최소값
리턴 : len
변수 : len, cur
cur을 이용해 덱의 top부터 반복문 돌면서
데이터와 min, max를 비교하며 바꿔주고
len++(len 초기값 = 0)
len리턴

2. 구조체 안의 정수형 배열에 len만큼 할당.
			size에 len을 넣어줌.

3. min값이 음수라면 bios = min x -1
				digit = max + bios의 자리수

4. radix_sort(덱, 구조체 배열, bios, digit)
{
	배열에 덱의 data + bios를 넣어줌.
	i = 1부터
	while i <= digit
		sorting(배열, bios, i(현재 자릿수))
}

4.5 n번째 자릿수 리턴 함수(long long n, dg)
{
	i = 1
	while (i < dg)
		n / 10;
	return (n % 10)
}

5. sorting
{
	qu0~9까지 선언
	i선언

	while 배열의 끝까지
	{
		if (str[i] < 3)
			insert_queue(str[i], qu0, qu1, qu2)
		else if (str[i] < 6)
			insert_queue(str[i], qu3, qu4, qu5)
		else if (str[i] < 6)
			insert_queue(str[i], qu3, qu4, qu5)
		else if (str[i] < 6)
			insert_queue(str[i], qu3, qu4, qu5)
	}

}





}
*/