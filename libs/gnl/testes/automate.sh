clear; gnl_test() { i=$1; while [ $i -lt "$2" ]; do ./main.sh $i; echo $i; ./a.out; i=`expr $i + 1`; done; }; gnl_test 54 55
while [ true ]; do sleep 1; clear; ./main.sh 20; done
