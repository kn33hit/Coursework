var=12
ans=$(bc<<< "3.4+7/8-(5.94*3.14)")
echo $ans
ans=`expr $var + 1`
echo $ans