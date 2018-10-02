ch=0
while [ $ch -ne 5 ]
 do 
  echo -e "Enter the choice:\n1)Create new Directory.\n2)Remove a Directory.\n3)Change working Directory.\n4)Display the content of current Directory.\n5)EXIT.\n"
  read ch
 case $ch in 
  1) echo -e "Enter the name of the Directory:"
     read name
    f=`ls | grep -c $name`
    if [ $f -eq 0 ]
     then
         `mkdir $name`
     echo -e "Directory Created\n"
    else 
     echo -e "Directory already Exist\n"
    fi;;
  2) echo -e "Enter the name of the Directory:"
     read name
     f=`ls | grep -c $name`
      if [ $f -ne 0 ]
       then
          `rmdir $name`
       echo -e "Directory Removed\n"
       else 
       echo -e "Directory does not  Exist\n"
      fi;;
  3) echo -e "Enter Whether to go to \n1)Subdirectory\n2)Previous Directory;\n"
     read m
     case $m in
     1) echo -e "Enter the Directory name to Change the working Directory\n"
        read chng
        f=`ls | grep -c $chng`
        if [ $f -ne 0 ]
          then
       cd $chng
         echo -e "Current Directory changed\n"
        else 
         echo -e "No Such Directory is Found\n"
     fi;;
    2) cd ..
         echo -e "Directory Changed....\n"
     esac;;
  4) echo -e "Content of the Current Directory are:\n"
     c=`pwd | ls`
     echo -e "$c\n";;
  5) echo -e "Thank you\n";;
  *) echo -e "Invalid Option\n"
 esac
done

 
