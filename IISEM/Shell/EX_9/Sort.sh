 echo -e "Enter the File Name: "
 read f
 echo -e "Enter the field in which the file is to be sorted: \n 1)Name \n 2)Mark 1 \n 3) Mark 2 \n 4) Mark 3 \n 5) Mark 5 \n: "
 read c
 sortlist=`sort -t ' ' -k $c $f`;
 echo -e  "\n Sorted List \n $sortlist ";
 echo -e " \n Enter the word to be searched:"
 read w
 flag=`grep $w $f | wc -l`;
 if [ $flag -eq 1 ]
  then echo -e "\n Found ";
 else echo -e "\n Not found ";
 fi
