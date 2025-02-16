echo "Simple Calculator "

echo "1 : Addition"
echo "2 : Substraction"
echo "3 : Multiplication"
echo "4 : Division"
echo "Choose any Operation : "
read ch
echo "Enter the first Number :"
read a
echo "Enter the Second Number :"
read b
case $ch in 
  1) rs=$(($a+$b))
     echo "Sum = " $rs ;;

  2) rs=$(($a-$b))
     echo "Difference = " $rs ;;

  3) rs=$(($a*$b))
     echo "Muliplication = " $rs ;;

  4) rs=$(($a/$b))
     echo "Division = " $rs ;;

   *)echo "Invalid Choice "
    esac
