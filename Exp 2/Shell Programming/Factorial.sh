echo "Enter the Number : "
read n
fact=1
for((i=n;i>0;i--))
do
 fact=$(($fact*$i))
done
echo "Factorial of " $n " = " $fact
