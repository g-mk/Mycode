count=$#
while [ $count -ge 1 ]
 do
 eval echo -e "$count argument is \$$count" 
  count=`expr $count - 1`;
done
