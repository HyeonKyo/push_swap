# push_swap 경로 설정해주세요
# CNT : 원소 개수
# LIMIT : 최대 operation 개수

CNT=100
LIMIT=2
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
NUM=`./push_swap $ARG | wc -l`

while [ $NUM -lt $LIMIT ]
do
echo $NUM
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
NUM=`./push_swap $ARG | wc -l`
done
echo $ARG > arr.txt
