function showNavigation()
{
    var frm = document.getElementById("frame");
    var showNav = frm.contentWindow.document.getElementById("goTop");
    if(frm.contentWindow.scrollY > 100 )
        showNav.setAttribute("style","opacity:1;");
    else if (frm.contentWindow.scrollY < 100 )
        showNav.setAttribute("style","opacity:0;");
}