
// Tooltip (fuer Vorschau in Navigation)

/***********************************************
* Cool DHTML tooltip script- © Dynamic Drive DHTML code library (www.dynamicdrive.com)
* This notice MUST stay intact for legal use
* Visit Dynamic Drive at http://www.dynamicdrive.com/ for full source code
***********************************************/

function ietruebody(){
return (document.compatMode && document.compatMode!="BackCompat")? document.documentElement : document.body
}

function ddrivetip(thetext, thecolor, theborder){
if (ns6||ie){
if (typeof thecolor!="undefined" && thecolor!="") tipobj.style.backgroundColor=thecolor
if (typeof theborder!="undefined" && theborder!="") tipobj.style.border=theborder
tipobj.innerHTML=thetext
enabletip=true
return false
}
}

function positiontip(e){
if (enabletip){
var curX=(ns6)?e.pageX : event.clientX+ietruebody().scrollLeft;
var curY=(ns6)?e.pageY : event.clientY+ietruebody().scrollTop;
//Find out how close the mouse is to the corner of the window
var rightedge=ie&&!window.opera? ietruebody().clientWidth-event.clientX-offsetxpoint : window.innerWidth-e.clientX-offsetxpoint-20
var bottomedge=ie&&!window.opera? ietruebody().clientHeight-event.clientY-offsetypoint : window.innerHeight-e.clientY-offsetypoint-20

var leftedge=(offsetxpoint<0)? offsetxpoint*(-1) : -1000

//if the horizontal distance isn't enough to accomodate the width of the context menu
if (rightedge<tipobj.offsetWidth)
//move the horizontal position of the menu to the left by it's width
tipobj.style.left=ie? ietruebody().scrollLeft+event.clientX-tipobj.offsetWidth+"px" : window.pageXOffset+e.clientX-tipobj.offsetWidth+"px"
else if (curX<leftedge)
tipobj.style.left="5px"
else
//position the horizontal position of the menu where the mouse is positioned
tipobj.style.left=curX+offsetxpoint+"px"

//same concept with the vertical position
if (bottomedge<tipobj.offsetHeight)
tipobj.style.top=ie? ietruebody().scrollTop+event.clientY-tipobj.offsetHeight-offsetypoint+"px" : window.pageYOffset+e.clientY-tipobj.offsetHeight-offsetypoint+"px"
else
tipobj.style.top=curY+offsetypoint+"px"
tipobj.style.visibility="visible"
}
}

function hideddrivetip(){
if (ns6||ie){
enabletip=false
tipobj.style.visibility="hidden"
tipobj.style.left="-1000px"
tipobj.style.backgroundColor=''
tipobj.style.width=''
}
}

// a little bit ajax is needed for the rating function
function ajax(url, vars, callbackFunction)
{
  var request = window.XMLHttpRequest ?
      new XMLHttpRequest() : new ActiveXObject("MSXML2.XMLHTTP.3.0");
  request.open("POST", url, true);
  request.setRequestHeader("Content-Type",
                           "application/x-www-form-urlencoded"); 
 
  request.onreadystatechange = function()
  {
    if (request.readyState == 4 && request.status == 200)
    {
      if (request.responseText)
      {
          callbackFunction(request.responseText);
      }
    }
  };
  request.send(vars);
}

function rateresult(result)
{
	// Dummy URL needed for standard javascript functions
	var result2 = 'http://www.dummy.com/index.php?'+result;
	var html_ratingbar = getURLParameters('html_ratingbar',result2);
	var html_ratingvalues = getURLParameters('html_ratingvalues',result2);
	var html_ratingtext = getURLParameters('html_ratingtext',result2);
	// html_rating_thanks = html_rating_thanks.replace(/\+/g,' ');
	var html_ratingbar = decodeURIComponent(html_ratingbar);
	var html_ratingvalues = decodeURIComponent(html_ratingvalues);
	var html_ratingtext = decodeURIComponent(html_ratingtext);

	document.getElementById('ratingbar').innerHTML = html_ratingbar;
	if (html_ratingvalues)
		document.getElementById('ratingvalues').innerHTML = html_ratingvalues;
	document.getElementById('ratingtext').innerHTML = html_ratingtext;
	
	// alert(html_rating_thanks);	
}

// Rate Icon Sets, etc.
var rating_running = 0;
function rate(type,id,rating)
{
	if (type=='iconset' && (rating_running==0))
	{
		// For the double clickers
		rating_running = 1;
		document.getElementById('ratingbar').innerHTML='<img src=/images/rating/bar_progress.gif width=108px height=10px>';
		vars = 'set_id='+id+'&rating='+rating;
		ajax('/inc/applic/ajax_rating.php',vars,rateresult);
		// alert(rating);
	}
}

function getURLParameters(name,url)
{
	name = name.replace(/[\[]/,"\\\[").replace(/[\]]/,"\\\]");
	var regexS = "[\\?&]"+name+"=([^&#]*)";
	var regex = new RegExp( regexS );
	var results = regex.exec( url );
	if( results == null )
		return "";
	else
		return results[1];
}

function track(u) {if(document.images){(new Image()).src="http://www.iconarchive.com/clicklog/_track.php?id="+u;}return true;}
function trackadblock(adblock) {if(document.images){(new Image()).src="http://www.iconarchive.com/inc/trackadblock.php?adblock="+adblock;}return true;}