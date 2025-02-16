echo "Enter the Number : "
read N
x=0
y=1
echo "The Fibonacci Series is : "
for((i=1;i<=N;i++))
do
 echo $x
f=$(($x + $y))
x=$y
y=$f
done
