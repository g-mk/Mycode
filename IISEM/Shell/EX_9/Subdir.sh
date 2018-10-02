
 subdir=`ls -l | tr -s ' '|grep "^d"| cut -d ' ' -f 9`;
 echo -e "\n Sub directories in the current folder is \n $subdir";
