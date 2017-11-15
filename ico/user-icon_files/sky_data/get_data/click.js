document.write('<!-- Template Id = 2593 Template Name = Banner Creative (Flash) -  In Page -->\n<!-- Copyright 2006 DoubleClick Inc., All rights reserved. --><script src=\"http://m1.2mdn.net/879366/flashwrite_1_2.js\"><\/script>');document.write('\n');

function DCFlash(id,pVM){
var swf = "http://m1.2mdn.net/1676394/TOEFL_WGT_120x600_25k.swf";
var gif = "http://m1.2mdn.net/1676394/TOEFL_WGT_120x600.gif";
var minV = 8;
var FWH = ' width="120" height="600" ';
var url = escape("http://ad.doubleclick.net/click%3Bh=v8/3729/f/60/%2a/r%3B203884725%3B0-0%3B0%3B27446599%3B933-120/600%3B27831507/27849386/1%3B%3B%7Esscs%3D%3fhttp://media.fastclick.net/w/click.here?cid=109658&mid=245145&sid=21484&m=3&c=7016&forced_click=http%3a%2f%2fwww.toeflgoanywhere.org");
var wmode = "opaque";
var bg = "";
var dcallowscriptaccess = "never";

var openWindow = "false";
var winW = 600;
var winH = 400;
var winL = 0;
var winT = 0;

var fv='"clickTag='+url+'&clickTAG='+url+'&clicktag='+url+'"';
var bgo=(bg=="")?"":'<param name="bgcolor" value="#'+bg+'">';
var bge=(bg=="")?"":' bgcolor="#'+bg+'"';
function FSWin(){if((openWindow=="false")&&(id=="DCF0"))alert('openWindow is wrong.');if((openWindow=="center")&&window.screen){winL=Math.floor((screen.availWidth-winW)/2);winT=Math.floor((screen.availHeight-winH)/2);}window.open(unescape(url),id,"width="+winW+",height="+winH+",top="+winT+",left="+winL+",status=no,toolbar=no,menubar=no,location=no");}this.FSWin = FSWin;
ua=navigator.userAgent;
if(minV<=pVM&&(openWindow=="false"||(ua.indexOf("Mac")<0&&ua.indexOf("Opera")<0))){
	var adcode='<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" id="'+id+'"'+FWH+'>'+
		'<param name="movie" value="'+swf+'"><param name="flashvars" value='+fv+'><param name="quality" value="high"><param name="wmode" value="'+wmode+'"><param name="base" value="'+swf.substring(0,swf.lastIndexOf("/"))+'"><PARAM NAME="AllowScriptAccess" VALUE="'+dcallowscriptaccess+'">'+bgo+
		'<embed src="'+swf+'" flashvars='+fv+bge+FWH+' type="application/x-shockwave-flash" quality="high" swliveconnect="true" wmode="'+wmode+'" name="'+id+'" base="'+swf.substring(0,swf.lastIndexOf("/"))+'" AllowScriptAccess="'+dcallowscriptaccess+'"></embed></object>';
  if(('j'!="j")&&(typeof dclkFlashWrite!="undefined")){dclkFlashWrite(adcode);}else{document.write(adcode);}
}else{
	document.write('<a target="_blank" href="'+unescape(url)+'"><img src="'+gif+'"'+FWH+'border="0" alt="" galleryimg="no"></a>');
}}
var pVM=0;var DCid=(isNaN("203884725"))?"DCF0":"DCF203884725";
if(navigator.plugins && navigator.mimeTypes.length){
  var x=navigator.plugins["Shockwave Flash"];if(x && x.description){var pVF=x.description;var y=pVF.indexOf("Flash ")+6;pVM=pVF.substring(y,pVF.indexOf(".",y));}}
else if (window.ActiveXObject && window.execScript){
  window.execScript('on error resume next\npVM=2\ndo\npVM=pVM+1\nset swControl = CreateObject("ShockwaveFlash.ShockwaveFlash."&pVM)\nloop while Err = 0\nOn Error Resume Next\npVM=pVM-1\nSub '+DCid+'_FSCommand(ByVal command, ByVal args)\nCall '+DCid+'_DoFSCommand(command, args)\nEnd Sub\n',"VBScript");}
eval("function "+DCid+"_DoFSCommand(c,a){if(c=='openWindow')o"+DCid+".FSWin();}o"+DCid+"=new DCFlash('"+DCid+"',pVM);");
//-->

document.write('\n<noscript><a target=\"_blank\" href=\"http://ad.doubleclick.net/click%3Bh=v8/3729/f/60/%2a/r%3B203884725%3B0-0%3B0%3B27446599%3B933-120/600%3B27831507/27849386/1%3B%3B%7Esscs%3D%3fhttp://media.fastclick.net/w/click.here?cid=109658&mid=245145&sid=21484&m=3&c=7016&forced_click=http%3a%2f%2fwww.toeflgoanywhere.org\"><img src=\"http://m1.2mdn.net/1676394/TOEFL_WGT_120x600.gif\" width=\"120\" height=\"600\" border=\"0\" alt=\"\" galleryimg=\"no\"></a></noscript>');
