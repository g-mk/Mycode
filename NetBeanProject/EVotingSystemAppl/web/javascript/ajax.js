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
function stateUpdate(e)
{
  loadXMLDoc("json/stateCities.json",function()
{
       if (xmlhttp.readyState==4 && xmlhttp.status==200)
       {
        var txt=xmlhttp.responseText;
        var obj=JSON.parse(txt);//convert a JSON text into a JavaScript object
        if(e.length < 2)
            for(i=0;i<obj.state.length;i++)
                e.innerHTML+="<option>"+obj.state[i].name+"</option>";

       }
 });
}
function cityUpdate(e)
{
  loadXMLDoc("json/stateCities.json",function()
{
       if (xmlhttp.readyState==4 && xmlhttp.status==200)
       {
        var txt=xmlhttp.responseText;
        var obj=JSON.parse(txt);//convert a JSON text into a JavaScript object
        var state = document.getElementById("voterState");
        for(i=0;i<obj.state.length;i++)
        {
            if(obj.state[i].name == state.value)
            {
                e.innerHTML ="<option>--Select--</option>";
                for(j=0;j<obj.state[i].city.length;j++)
                    e.innerHTML +="<option>"+obj.state[i].city[j]+
                                "</option>";
            }
        }

       }
 });
}
