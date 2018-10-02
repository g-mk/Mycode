 echo -e "\n Content in the Given file is\n";
 cat $1;
 w=`wc -w $1`
 l=`wc -l $1`
 c=`wc -c $1`
 echo -e "\n No of words:$w \n No. of Lines:$l \n No. of Character:$c\n";
