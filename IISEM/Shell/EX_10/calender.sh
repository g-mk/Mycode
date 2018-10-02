echo -e "Enter the Month:"
 read m
echo -e "\nEnter the Year:"
 read y
if [ $m -ge 1 ]
 then
  if [ $m -le 12 ]
   then
     if [ $y -ge 2000 ]
      then
        if [ $y -le 2020 ]
         then
        echo -e "Calander is:\n"
          `cal $m $y`;
     else
     
   echo -e "Entered year is not valid.\nPlease Give In The Range of 2000-2020";
 fi
else
 echo -e "Entered Month is Not Valid.\nPlease Give in the Range of 1-12 ";
fi
