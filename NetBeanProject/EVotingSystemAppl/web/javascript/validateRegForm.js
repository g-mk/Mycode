var flag = 0;
window.onload = function attachEvent()
{
   document.getElementById("confirm").addEventListener("click",toggleSubmit);
   document.getElementById("regForm").reset();
};

function toggleSubmit()
{
   var sbmt = document.getElementById("submit");
   var confirmBox = document.getElementById("confirm");
   if(flag)
       sbmt.disabled = !(confirmBox.checked);
}
function checkPassword()
{
   var passwd = document.getElementById("passwd");
   var cpasswd = document.getElementById("cpasswd");
   if(passwd.value === "")
       flag=0;
   else if(passwd.value.length < 6 )
   {
       flag =0;
       document.getElementById("errorPasswd").innerHTML=
           "Give atleast 6 character";
       document.getElementById("errorPasswd").setAttribute("style","opacity:1");
       document.getElementById("Checkpasswd").
               setAttribute("style","color:green;font-size:20px;opacity:0");
       
   }
   else
   {
       flag=1;
       document.getElementById("errorPasswd").setAttribute("style","opacity:0");
       document.getElementById("Checkpasswd").
               setAttribute("style","color:green;font-size:20px;opacity:1");
   }
   if(passwd.value!=cpasswd.value)
   {
       flag=0;
      cpasswd.setCustomValidity("Password Mismatch");
      document.getElementById("errorCPasswd").innerHTML="Password Mismatch";
      document.getElementById("errorCPasswd").setAttribute("style","opacity:1");
      document.getElementById("Checkcpasswd").
               setAttribute("style","color:green;font-size:20px;opacity:0");
      
   }   
   else
   {
       flag=1;
      cpasswd.setCustomValidity("");
      document.getElementById("errorCPasswd").setAttribute("style","opacity:0");
      if(cpasswd.value!=="")
          document.getElementById("Checkcpasswd").
               setAttribute("style","color:green;font-size:20px;opacity:1");
   }   
      
}
function checkText(e)
{
   var pattn = /^[a-zA-Z .]+$/;
   if(e.value==="")
   {
       flag=0;
       document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:0");
   }
   else if(!pattn.test(e.value) && e.value !=="")
   {
       flag=0;
      e.setCustomValidity("Name Should not contain numeric"+
                                 " or other character"); 
      document.getElementById("error"+e.id).innerHTML=
              "Should contain only alphabets";
      document.getElementById("error"+e.id).setAttribute("style","opacity:1");
      document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:0");
   }   
   else
   {
       flag=1;
      e.setCustomValidity("");
      document.getElementById("error"+e.id).setAttribute("style","opacity:0");
      document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:1");
   }
}

function checkMail(e)
{
   var pattn = /^[a-z0-9]+\@[a-z]+\.[a-z.]+$/;
   if(e.value==="")
       flag=0;
   else if(!pattn.test(e.value))
   {
      flag=0; 
      e.setCustomValidity("Not a Valid Email Id");
      document.getElementById("errorMail").innerHTML="Invalid Email Id";
      document.getElementById("errorMail").setAttribute("style","opacity:1");
      document.getElementById("Checkemail").
               setAttribute("style","color:green;font-size:20px;opacity:0");
   }   
   else
   {
      flag=1;
      e.setCustomValidity("");
      document.getElementById("errorMail").setAttribute("style","opacity:0");
      document.getElementById("Checkemail").
               setAttribute("style","color:green;font-size:20px;opacity:1");
   }
}
function checkMobile(e)
{
    var pattn = /^(\+\d{1,3}[- ]?)?\d{10}$/;
    if(e.value==="")
       flag=0;
   else if(!pattn.test(e.value))
    {
       flag=0;
       e.setCustomValidity("Invalid Mobile Format");
       document.getElementById("errorMobile").innerHTML = "Invalid Mobile Format";
       document.getElementById("errorMobile").setAttribute("style","opacity:1");
       document.getElementById("Checkmobile").
               setAttribute("style","color:green;font-size:20px;opacity:0");
    }
    else
    {
       flag=1; 
       e.setCustomValidity("");
       document.getElementById("errorMobile").setAttribute("style","opacity:0");
       document.getElementById("Checkmobile").
               setAttribute("style","color:green;font-size:20px;opacity:1");
    }
}
function appendDOB(e,event)
{
    var yPattn = /^\d{4}$/;
    var ymPattn = /^\d{4}\-\d{2}$/;
    if((event.which || event.keyCode)!=8)
    {
        if(yPattn.test(e.value) )
        {
            e.value += "-";
        }
        else if(ymPattn.test(e.value))
        {
            e.value += "-";
        }
    }
}
function checkDOB(e)
{
   var pattn = /^\d{4}\-([0][0-9]|[1][0-2])\-([0-2][0-9]|[3][0-1])$/;
   if(e.value==="")
       flag=0;
   else if(!pattn.test(e.value))
   {
       flag=0;
       e.setCustomValidity("Invalid Date Format");
       document.getElementById("errorDOB").innerHTML = "Invalid Date Format";
       document.getElementById("errorDOB").setAttribute("style","opacity:1");
       document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:0");
   }
   else
   {
       flag=1;
       var date = new Date();
       var dob = new Date(e.value);
       var age = date.getFullYear() - dob.getFullYear();
       if(date.getMonth() < dob.getMonth())
           age = age - 1;
       if(age.toString() === "NaN")
       {
           document.getElementById("errorDOB").innerHTML = "Not a Leap Year";
           document.getElementById("errorDOB").setAttribute("style","opacity:1");
           document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:0");
       }
       else
       {
           document.getElementById("errorDOB").setAttribute("style","opacity:0");
           document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:1");
           e.setCustomValidity("");
       }
       if(age>=18)
           document.getElementById("age").value=age;
       else
           document.getElementById("age").value="";
   }
}

function checkAge(e)
{
   var pattn = /^\d+$/;
   if(e.value==="")
       flag=0;
   else if((!pattn.test(e.value)) || (e.value < 18) || (e.value > 150))
   {
      flag=0;
      e.setCustomValidity("Age Should be Greate than or equal to 18");
      document.getElementById("errorAge").innerHTML = 
              "Age >= 18 or Age <= 150";
      document.getElementById("errorAge").setAttribute("style","opacity:1");
      document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:0");
   }
   else
   {
      flag=1;
      e.setCustomValidity("");
      document.getElementById("errorAge").setAttribute("style","opacity:0");
      document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:1");
      
   }
}
function checkSelect(e)
{
    if(e.value == "--Select--")
    {
        flag=0
        e.setCustomValidity("Select a valid Option");
        if(e.id=="voterState")
        {
            document.getElementById("errorState").innerHTML="Choose Your State";
            document.getElementById("voterCity").innerHTML=
                    "<option>--Select--</option>";
            document.getElementById("errorState").setAttribute("style","opacity:1");
            document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:0");
        }
        else
        {
            document.getElementById("errorCity").innerHTML="Choose Your City";
            document.getElementById("errorCity").setAttribute("style","opacity:1");
            document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:0");
        }
    }
    else
    {
        flag=1;
        e.setCustomValidity("");
        if(e.id=="voterState")
        {
            document.getElementById("errorState").setAttribute("style","opacity:0");
            document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:1");
        }
        else
        {
            document.getElementById("errorCity").setAttribute("style","opacity:0");
            document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:1");
        }
    }
        
}

function checkGender()
{
    var male= document.getElementById("gMale");
    var female = document.getElementById("gFemale");
    var othr = document.getElementById("gOther");
    if(!male.checked && !female.checked && !othr.checked)
    {
        flag=0;
        male.setCustomValidity("Choose Your Gender");
        female.setCustomValidity("Choose Your Gender");
        othr.setCustomValidity("Choose Your Gender");
        document.getElementById("errorGender").innerHTML="Choose Your Gender";
        document.getElementById("errorGender").setAttribute("style","opacity:1");
        document.getElementById("CheckGender").
               setAttribute("style","color:green;font-size:20px;opacity:0");
    }
    else
    {
        flag=1;
        male.setCustomValidity("");
        female.setCustomValidity("");
        othr.setCustomValidity("");
        document.getElementById("errorGender").setAttribute("style","opacity:0");
        document.getElementById("CheckGender").
               setAttribute("style","color:green;font-size:20px;opacity:1");
    }
        
}

function checkFile(e)
{
    if(e.value==="")
    {
        document.getElementById("error"+e.id).innerHTML="Choose a file";
        document.getElementById("error"+e.id).setAttribute("style","opacity:1");
        document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:0");
    }
    else
    {
        document.getElementById("error"+e.id).setAttribute("style","opacity:0");
        document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:1");
    }
}

function checkUser(e)
{
   var pattn = /^[a-zA-Z0-9_]+$/;
   if(e.value==="")
       flag=0;
   else if(!pattn.test(e.value) && e.value !=="")
   {
       flag=0;
      e.setCustomValidity("User Name Should contain"+
                                 "only alphanumeric charachter and '_'"); 
      document.getElementById("error"+e.id).innerHTML=
              "Should contain only alphanumeric charachter and '_'";
      document.getElementById("error"+e.id).setAttribute("style","opacity:1");
      document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:0");
   }   
   else
   {
       flag=1;
      e.setCustomValidity("");
      document.getElementById("error"+e.id).setAttribute("style","opacity:0");
      document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:1");
   }
}
function checkDoorNo(e)
{
    var pattn = /^[a-zA-Z0-9 /]+$/;
   if(e.value==="")
       flag=0;
   else if(!pattn.test(e.value) && e.value !=="")
   {
       flag=0;
      e.setCustomValidity("Door Number Should no contain special character "+
              "other than space and /"); 
      document.getElementById("error"+e.id).innerHTML=
              "Should contain only alphanumeric and /";
      document.getElementById("error"+e.id).setAttribute("style","opacity:1");
      document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:0");
   }   
   else
   {
       flag=1;
      e.setCustomValidity("");
      document.getElementById("error"+e.id).setAttribute("style","opacity:0");
      document.getElementById("Check"+e.id).
               setAttribute("style","color:green;font-size:20px;opacity:1");
   }
}