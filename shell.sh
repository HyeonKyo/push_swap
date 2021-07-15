
# ruby -e "puts (-50..49).to_a.shuffle.join(' ')"

CNT=100
LIMIT=700
echo "$@"
NUM=`./push_swap $@ | wc -l`

echo $NUM
