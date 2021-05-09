function abs(x){
   if (x >=0)
     return x;
   else
     return -x;
}
function Edge(fromx, fromy, tox, toy, slope){
    context.save();
    var angle = Math.atan2(toy-fromy,tox-fromx)-slope/8;
    context.moveTo(fromx, fromy);
    context.quadraticCurveTo((fromx+tox)/2+slope*15,(fromy+toy)/2+slope*15,tox,toy);
    context.strokeStyle = "#FF0";
    context.stroke();
    context.restore();
}


function Arrow(fromx, fromy, tox, toy, slope){
    context.save();
    var headlen = 12;   // length of head in pixels
    var angle = Math.atan2(toy-fromy,tox-fromx)-slope/8;
    context.moveTo(fromx, fromy);
    context.quadraticCurveTo((fromx+tox)/2+slope*15,(fromy+toy)/2+slope*15,tox,toy);
    context.lineTo(tox-headlen*Math.cos(angle-Math.PI/12),toy-headlen*Math.sin(angle-Math.PI/12));
    context.moveTo(tox, toy);
    context.lineTo(tox-headlen*Math.cos(angle+Math.PI/12),toy-headlen*Math.sin(angle+Math.PI/12));
    context.strokeStyle = "#FF0";
    context.stroke();
    context.restore();
}

  function Cross(x,y,text,color,italic){
      context.save();
    context.strokeStyle = color;
    context.moveTo(x-3,y-3);
    context.lineTo(x+3,y+3);
    context.moveTo(x-3,y+3);
    context.lineTo(x+3,y-3);
    context.stroke();
    context.font = (italic > 0) ? "italic 16px teX" : "normal 16px teX";
    context.fillStyle = color;
    var lt = context.measureText(text).width;
    context.fillText(text,x-lt/2,y-10);
    context.restore();
  }

  function NewCross(x,y,text,color,it,pos){
    context.save();
    context.strokeStyle = color;
    context.moveTo(x-3,y-3);
    context.lineTo(x+3,y+3);
    context.moveTo(x-3,y+3);
    context.lineTo(x+3,y-3);
    context.stroke();
    var str = "";
    for (var i = 0; i < text.length; i++){ 
       context.font = (it[i] == "1") ? "italic 16px teX" : "normal 16px teX";
       context.fillStyle = color;       
       var lt = context.measureText(text).width;
       var loclt = context.measureText(str).width;
       if (pos == "S") {
          xshift = 0;
          yshift = 20;
       } else 
       if (pos == "N") {
          xshift = 0;
          yshift = -10;
         } else 
       if (pos == "W") {
          xshift = lt-5;
          yshift = 0;
         }
       else {
          xshift = -lt+5;
          yshift = 0;
       }
      
       context.fillText(text[i],x-lt/2+loclt+xshift,y+yshift);
       str += text[i];
    }
    context.restore();
  }




  function TOval(x,y,r,sc,fillcolor,bordercolor){
  // save state
  context.save();
  
  // scale context horizontally
  context.scale(1, sc);
  
  // draw circle which will be stretched into an oval
  context.beginPath();
  context.arc(x, y, r, 0, 2 * Math.PI, false);
  
  // apply styling
  if (fillcolor != "#000"){
    context.fillStyle = fillcolor;
    context.fill(); 
  }
  context.lineWidth = 1;
  context.strokeStyle = bordercolor;
  context.stroke();
  context.restore();
}

  function Oval(x,y,r){
     TOval(x,y,r,2,'#111111','#FFFFFF');
  }

  function DrawArrows(id,graphe,color){
  canvas = document.getElementById(id); 
  context = canvas.getContext("2d");
  context.save();
  context.setLineDash([0]);
  context.strokeStyle = color;
  context.font = "italic 20px teX";
  for (var i = 0; i < graphe.length; i++) {
     context.beginPath();
     var X = graphe[i][0];
     var Y = graphe[i][3];
     var xx = graphe[i][1];
     var xy = graphe[i][2];
     var yx = graphe[i][4];
     var yy = graphe[i][5];
     var sl = graphe[i][6];
     Cross(xx,xy,X,"#FFFFFF",1);
     Cross(yx,yy,Y,"#FFFFFF",1);
     if (sl != 0)
        Arrow(xx,xy,yx,yy,sl);     
     if ((xx == yx) && (xy == yy))
        TOval(xx,yy-15,15,1,'#000','#FFFFFF');
     context.stroke();
  }
  context.restore();
  }

  function DrawGraph(id,xo1,yo1,xo2,yo2,radius,graphe,EF){
  canvas = document.getElementById(id); 
  context = canvas.getContext("2d");
  context.save();
  context.setLineDash([0]);
  if (xo1 > 0)  
    Oval(xo1,yo1,radius);  
  if (xo2 > 0 ) 
    Oval(xo2,yo2,radius);  
  context.restore();
  for (X in graphe){
     context.beginPath();
     var xx = graphe[X][0] + xo1 - radius;
     var xy = graphe[X][1];
     var yx = graphe[X][2] + xo1 - radius;
     var yy = graphe[X][3];
     var Y = graphe[X][4];
     Cross(xx,xy,X,"#FFFFFF",1);
     Cross(yx,yy,Y,"#FFFFFF",1);
     if (graphe[X][5] > 0)
        Arrow(xx,xy,yx,yy,-1);
  }
  context.font = "italic 20px teX";
  context.fillStyle = "#FFF";
  context.fillText(EF[0],xo1-radius/1.2,25);
  context.fillText(EF[1],xo2+radius/1.7,25);
  context.fillStyle = "#FF0";
  if (xo1 == 0)
     context.fillText(EF[2],(xo2-1.5*radius),35);
  else
     context.fillText(EF[2],(xo1+xo2)/2,35);
  context.restore();
  }

  function DrawCorrespondance(){
  canvas = document.getElementById("jumelage"); 
  context = canvas.getContext("2d");
  context.save();
  context.setLineDash([0]);

  Oval(90,90,85);  
  Oval(360,90,85);
  context.beginPath();
  context.restore();

  Cross(85,60,"La Garde","#FFFFFF",1);
  Cross(65,120,"Toulon","#FFFFFF",1);
  Cross(105,180,"Signes","#FFFFFF",1);
  Cross(65,240,"Mazaugues","#FFFFFF",1);
  Cross(85,300,"Nice","#FFFFFF",1);

  Cross(360,60,"Montesarchio","#FFFFFF",1);
  Cross(315,120,"Spa","#FFFFFF",1);

  Cross(315,170,"Mannheim","#FFFFFF",1);
  Cross(385,240,"Norfolk","#FFFFFF",1);
  Cross(360,310,"Kronstadt","#FFFFFF",1);

  Cross(375,100,"Alicante","#FFFFFF",1);
  Cross(385,150,"Cuneo","#FFFFFF",1);
  Cross(325,215,"Yalta","#FFFFFF",1);

  Cross(315,270,"Vegen","#FFFFFF",1);
  Cross(385,200,"Liski","#FFFFFF",1);
  context.restore();

  Arrow(85,60,360,60,-1);
  Arrow(85,60,315,120,-1);

  Arrow(65,120,315,170,0);
  Arrow(65,120,385,240,0);
  Arrow(65,120,360,310,0);

  Arrow(85,300,375,100,1);
  Arrow(85,300,385,150,1);
  Arrow(85,300,325,215,1);

  context.font = "italic 20px teX";
  context.fillStyle = "#FFF";
  context.fillText("X",25,25);
  context.fillText("Y",405,25);
  context.fillStyle = "#FF0";
  context.fillText("G",210,45);
  context.restore();
  }

  function DrawFunction(id,point,set){
  canvas = document.getElementById(id); 
  context = canvas.getContext("2d");
  context.save();
  context.setLineDash([0]);

  Oval(90,90,85);  
  Oval(360,90,85);
  context.beginPath();
  context.restore();

  Cross(85,60,"glace","#FFFFFF",1);
  Cross(65,120,"alcool","#FFFFFF",1);
  Cross(105,180,"smartphone","#FFFFFF",1);
  Cross(85,300,"livre","#FFFFFF",1);
  Cross(35,170,"cinéma","#FFFFFF",1);
  if (point == 0)  
     Cross(65,240,"carrie","#FFFFFF",1);

  Cross(355,60,"20%","#FFFFFF",0);
  Cross(385,100,"75%","#FFFFFF",0);
  Cross(315,120,"5,5%","#FFFFFF",0);
  Cross(315,180,"30%","#FFFFFF",0);
  Cross(395,200,"10%","#FFFFFF",0);
  Cross(325,270,"2.1%","#FFFFFF",0);
  Cross(360,310,"15%","#FFFFFF",0);

  context.restore();

  Arrow(85,60,395,200,-1);
  Arrow(65,120,355,60,-1);
  Arrow(85,300,315,120,1);
  Arrow(105,180,355,60,1);
  Arrow(35,170,325,270,1);


  context.font = "italic 20px teX";
  context.fillStyle = "#FFF";
  context.fillText(set,25,25);
  context.fillText("Y",405,25);
  context.fillStyle = "#FF0";
  context.fillText("G",210,45);
  context.restore();
  }
