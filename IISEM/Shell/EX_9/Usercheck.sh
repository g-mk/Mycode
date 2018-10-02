 user_name=` who | grep -c -w $1 `;
 
 if [ $user_name -ne  0 ]
  then
   echo -e "\n$1 is  Logged in at this time";
 else
   echo -e "\n $1 is not Logged in at this time";
 fi

count=` who | grep 14bcs* |wc -l`;
 echo -e "\n No. of user logged in as 14bcs is $count";


