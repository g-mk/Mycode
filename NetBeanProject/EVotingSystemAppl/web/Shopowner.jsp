<%-- 
    Document   : Shopowner
    Created on : 18 Sep, 2017, 9:24:32 PM
    Author     : Gunalini
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Shop owner Page</title>
        
<script>
    function loadToday()
    {
                  var today = new Date();
var dd = today.getDate();
var mm = today.getMonth()+1; //January is 0!
var yyyy = today.getFullYear();

if(dd<10) {
    dd = '0'+dd;
} 

if(mm<10) {
    mm = '0'+mm;
} 

today =  yyyy+ '-' + mm+ '-' +dd  ;
    document.getElementById('sdate').value = today;
    }
/*function dateDiff(dateform) {
date1 = new Date();
date2 = new Date();
diff  = new Date();

date1temp = new Date(dateform.firstdate.value);
date1.setTime(date1temp.getTime());

date2temp = new Date(dateform.seconddate.value);
date1.setTime(date2temp.getTime());

/*date2temp = new Date(Date.parse(document.getElementById("seconddate").value));
date2.setTime(date2temp.getTime());*/

/*diff.setTime(Math.abs(date1.getTime() - date2.getTime()));

timediff = diff.getTime();
days = Math.floor(timediff / (1000 * 60 * 60 * 24)); 
document.getElementById("difference").value = days;
//year=Math.ceil(days/365);
//location.href="eval.jsp?year="+year;
return false; 

}*/
function dateDiff(dateform) {
date1 = new Date(dateform.firstdate.value);
date2 = new Date(dateform.seconddate.value);
diff  = new Date();
diff.setTime(Math.abs(date1.getTime() - date2.getTime()));

timediff = diff.getTime();
days = Math.floor(timediff / (1000 * 60 * 60 * 24)); 
dateform.difference.value = days;
year=Math.ceil(days/365);
location.href="eval.jsp?year="+year;
return false; 

}
</script>
</head>
<body onload=loadToday()>
<form onSubmit="return dateDiff(this);">
<pre>
First Date(MM/DD/YYYY):     <input type=date name=firstdate>   

Second Date(MM/DD/YYYY):   <input  type=text name=seconddate id=sdate> 
                             <!--<input  type=date name=seconddate id=sdate> -->

Date Difference (in days):  <input type=text id=difference name=difference>

                            <input type=submit value="Calculate Difference!" >

</pre>
</form>
</body>
</html>