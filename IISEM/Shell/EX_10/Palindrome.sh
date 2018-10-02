 echo "Enter the String:[press Ctrl + D when finished]"
 `cat > Data`
 echo -e "\nContent in File"
 str=`cat Data`
 echo $str
 l=`cat Data | wc -m`
 n=`expr $l / 2`
 i=1
 f=1
 while [ $i -le $n ]
 do
  a=`cat Data |cut -c "$i"`
 #echo -e "\na=$a"
  b=`cat Data |cut -c "$l"`
# echo -e "\nb=$b"
   if [ $a != $b ]
    then
      f=0
   fi
  i=`expr $i + 1`
  l=`expr $l - 1`
  done
 if [ $f -eq 1 ]
  then
   echo -e "\nGiven string is Palindrome"
 else 
   echo -e "\nGiven string is not a Palindorme"
 fi

