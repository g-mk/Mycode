f=`w | grep $1  | tr -s " " |cut -d " " -f 4`
f=`echo "$f" | cut -c 1-2`
if [ $f -le 12 ]
  then echo -e "Good Morning "
else 
  echo "Good Afternoon"
fi

