ch=0
while [ $ch -ne 6 ]
do
echo -e "Enter the choice:\n1)Addition.\n2)Subraction.\n3)Multiplication.\n4)Division.\n5)Modulo.\n6)Exit"
 read ch

case $ch in 
 1) echo -e "Enter the value for a:"
     read a
    echo -e "Enter the value for b:"
     read b
    sum=`expr $a + $b`
    echo -e "\nSum of $a and $b is: $sum";;
 2) echo -e "Enter the value for a:"
     read a
    echo -e "Enter the value for b:"
     read b
    diff=`expr $a - $b`
   echo -e "\nDifferance of $a and $b is: $diff";;
 3) echo -e "Enter the value for a:"
     read a
    echo -e "Enter the value for b:"
     read b
    mul=`expr $a \* $b`
    echo -e "\nProduct of $a and $b is: $mul";;
 4) echo -e "Enter the value for a:"
     read a
    echo -e "Enter the value for b:"
     read b
    div=`expr $a / $b`
    echo -e "\nQuotient of $a and $b is: $div";;
 5) echo -e "Enter the value for a:"
     read a
    echo -e "Enter the value for b:"
     read b
    mod=`expr $a % $b`
    echo -e "\nReminder for $a and $b is: $mod";;
 6) echo -e "\nThank you";;
 *) echo -e "\nInvalid Option.."
esac
done
