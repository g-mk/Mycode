echo -e "\n Enter value for a:"
read a
echo -e "\n Enter value for b:"
read b
echo -e "Before Swaping \n $a $b"
a=`expr $a + $b`
b=`expr $a - $b`
a=`expr $a - $b`
echo -e "\n After Swaping \n $a $b"

