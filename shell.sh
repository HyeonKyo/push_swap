


CNT=100
LIMIT=700
ARG=ruby -e "puts (0..100).to_a.shuffle.join(' ')"
NUM=`./push_swap $ARG | wc -l`
​
while [ $NUM -lt $LIMIT ]
do
echo $NUM
ARG=ruby -e "puts (0..100).to_a.shuffle.join(' ')"
NUM=`./push_swap $ARG | wc -l`
done