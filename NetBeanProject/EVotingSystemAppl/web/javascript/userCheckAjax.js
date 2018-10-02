var xmlhttp;
function loadXMLDoc(url,cfunc)
{
  if (window.XMLHttpRequest)
  {// code for IE7+, Firefox, Chrome, Opera, Safari
   xmlhttp=new XMLHttpRequest();
  }
  else
  {// code for IE6, IE5
    xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
  }
  xmlhttp.onreadystatechange=cfunc;
  xmlhttp.open("GET",url,true);
  xmlhttp.send();
}
function userNameCheck(e)
{
  loadXMLDoc("http://localhost:44865/EVotingSystemAppl/UserCheckServlet?usr="
          +e.value,function()
    {
       if (xmlhttp.readyState === 4 && xmlhttp.status === 200)
       {
            var txt=xmlhttp.responseText;
            e.setCustomValidity(txt);
            if(txt!=="")
            {
                document.getElementById("error"+e.id).innerHTML=txt;
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
 });
}


