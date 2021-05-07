(function () {
  var summary = document.getElementById("summary");
  var i = 0;
  var j = 0;
  if (summary){
    var contenu = "";
    if (summary.hasAttribute("previous")){
      var previous = summary.getAttribute("previous");
      contenu += '<a class="moves" title="chapitre précédent" href="' + previous + '">⏮</a>';
    }
    if (summary.hasAttribute("top")){
      var top = summary.getAttribute("top");
      contenu += '<a class="moves" title="Sommaire général" href="' + top + '">⏏</a>';
    }
    if (summary.hasAttribute("next")){
      var next = summary.getAttribute("next");
      contenu += '<a class="moves" title="chapitre suivant" href="' + next + '">⏭</a>';
    }

    var sections = document.getElementsByClassName("section");
    var subsections = document.getElementsByClassName("subsection");
    var tree = [];
    for (i = 0; i < sections.length; i++){
       var section = sections[i];
       tree[section.id] = [];
       for (j = 0; j < subsections.length; j++){
  	    var couple = (subsections[j].id).split(":");
            if (couple[0] == section.id)
	      (tree[section.id]).push(j);
       }
    }
    contenu += '<P><ol>\n';
    for (i = 0; i < sections.length; i++){
      var section = sections[i];
      var sectionlink = section.id;
      contenu += '<li>';
      contenu += '<a href=#';
      contenu += sectionlink + '>' + section.innerHTML + '</a></li>';
      if (tree.hasOwnProperty(sectionlink)){
        var subsecidx = tree[sectionlink];
	contenu += '<ol>';
        for (j = 0; j < subsecidx.length; j++){                     
	  var subsectionlink =  subsections[subsecidx[j]].id;
          var subsectiontitle = subsections[subsecidx[j]].innerHTML;
	  contenu += '<li style="list-style-type:none;margin-left:-2em;">'
	    contenu += (i+1)+'.'+(j+1)+'.&nbsp;' + '<a href="#' + subsectionlink +'">';
          contenu += subsectiontitle + '</a></li>';
	}
	contenu += '</ol>';
      }
    }
    contenu = contenu + '</ol></P>\n';
    summary.innerHTML += contenu;
  }
})();

String.prototype.sansAccent = function(){
  var accent = [
		/[\300-\306]/g, /[\340-\346]/g, // A, a
		/[\310-\313]/g, /[\350-\353]/g, // E, e
		/[\314-\317]/g, /[\354-\357]/g, // I, i
		/[\322-\330]/g, /[\362-\370]/g, // O, o
		/[\331-\334]/g, /[\371-\374]/g, // U, u
		/[\321]/g, /[\361]/g, // N, n
		/[\307]/g, /[\347]/g, // C, c
		];
  var noaccent = ['A','a','E','e','I','i','O','o','U','u','N','n','C','c'];
  
  var str = this;
  for(var i = 0; i < accent.length; i++){
    str = str.replace(accent[i], noaccent[i]);
  }
  return str;
}

function Proper(s){
  return s[0].toUpperCase() + s.slice(1).toLowerCase();
  }

function Lettrine(word) {
   return '<span class="first">'+
     Proper(word[0]) + '</span>' + word.slice(1);
}


(function () {
  var elem = document.getElementById("listdef");
  if (elem) {
    var items = document.getElementsByClassName("def");
    if (items.length > 0) {
      var dico = new Array(items.length);
      var anchor = new Array();
      var charpos = new Object();
      var contenu = '<p><ul class="test">';  
      //  alert(items[0].innerHTML);
      for (var i = 0; i < items.length; i++){
	var word = items[i].innerHTML;
        dico[i] = word;
	anchor[word] = items[i].name;
      }
      //localeCompare() indispensable à cause UTF-8
      dico = dico.sort(function(a, b){
	  return (a.toLowerCase()).localeCompare(b.toLowerCase());
	});

      for (var i = 0; i < items.length; i++){
        var word = dico[i];
	if (typeof(charpos[word[0].toLowerCase()]) === 'undefined')
	  charpos[word[0].toLowerCase()] = i;
	}

      contenu += "<li><a href=\"#"+anchor[dico[0]]+"\">";
      if (charpos[dico[0][0].toLowerCase()] == 0)
	contenu += Lettrine(dico[0]);
      else 
	contenu += dico[0];
      contenu += "</a>";
      contenu = (items.length > 1)? contenu + ", " : contenu + ".";
      for (var i = 1; i < items.length - 1; i++) {
        var word = dico[i];
	contenu +=  "<a href=\"#"+anchor[word]+"\">";

        if (charpos[word[0].toLowerCase()] === i)
  	  contenu += '<li>' + Lettrine(word);
        else 
	  contenu += word;

	contenu +=  "</a>, ";
      }
      if (items.length > 1) {    
        word = dico[items.length - 1];
	contenu += "<a href=\"#"+anchor[word]+"\">";
	if (charpos[word[0].toLowerCase()] === items.length - 1)
	  contenu += '<li>' + Lettrine(word);
	else
	  contenu +=  word; 
        contenu += "</a>.</ul></p>";
	}
      elem.innerHTML = contenu;
    }
    else {
      elem.className = "null";
    }
  }  
})();


(function () { 
  var elem = document.getElementById("DM");
  if (elem){
    var update = new Date(document.lastModified);
    var mois = update.getMonth() + 1 ;
    var titredoc = document.getElementById("chapter").innerHTML;
    var jour = update.getDate(); 
    var an = update.getFullYear();
    var maj = 'Version du ' + jour + '/' + mois + '/' + an;
    var author = "&nbsp;&copy; JP. Zanotti";
    elem.innerHTML = maj + " " + '<a href="mailto:zanotti[@]univ-tln.fr?subject=' + titredoc + '" title="Envoyer un mail">'  + author + '</a>';
    //  document.writeln(maj + " " + '<a href="mailto:zanotti[@]univ-tln.fr?subject=' + titredoc + '">' + '</a>')
  }
})();


(function() {
  var rword = ["algorithme","entrée","sortie","tq","tant que","et","ou","non","faire","ftq","si","sinon","alors","fsi","variables","constantes","globales","données","répeter","rpt","jq","renvoyer","retourner","pour","fpour","fp","jusqua","debut","vrai","faux","fin","mod","div"];
    var reg = new RegExp('\\b'+rword.join("\\b|\\b")+'\\b', "gi");    
    var algos = document.getElementsByClassName('algorithme');
    for (var i = 0; i < algos.length; i++) {
        var algo = algos[i];
        var lines = (algo.innerHTML).replace(reg, function(matched){
            return '<span class="motclef">'+matched.toUpperCase()+'</span>';
        });       
        algo.innerHTML = '<span class="line-number"></span>' + lines + '<span class="cl"></span>';
        var nblines = lines.split(/\n/).length;

        for (var j = 1; j < nblines; j++) {
            var numline = algo.getElementsByTagName("span")[0];
            numline.innerHTML += '<span>' + (j) + '</span>';
        }
    }
})();

(function() {
  var rwordC = ["auto","break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "printf", "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void","volatile", "while"];
  var rwordPython = ["and","assert","break","continue","def","del","elif","else","except","exec","finally","float","for","from","global","if","import","in","int","is","lambda","not","or","open","pass","print","range","raise","read","readlines","rstrip","return","split","str","try","while","yield","True","False"];
    var Cregw = new RegExp('\\b' + rwordC.join("\\b|\\b") + '\\b', "gi");    
    var Pythonregw = new RegExp('\\b' + rwordPython.join("\\b|\\b") + '\\b', "gi");    
    var regc = new RegExp('"[^"]+"', "gm");    
    var programs = document.getElementsByClassName('program'); 
    nbprograms = programs.length;
    for (var i = 0; i < nbprograms; i++) {
        var language = programs[i].getAttribute("language");
        var rules = programs[i].innerHTML;
	        rules = rules.replace(regc, function(matched){
	            return '<span class="cchain">'+matched+'</span>';
	         });
                var regw = (language == "C") ? Cregw : Pythonregw;
	        rules = rules.replace(regw, function(matched){
	            return '<span class="ckeyword">'+matched.toLowerCase()+'</span>';
	        });       

        programs[i].innerHTML = '<span class="line-number"></span>' + rules + '<span class="cl"></span>';
        var num = rules.split(/\n/).length;
        for (var j = 1; j < num; j++) {
            var line_num = programs[i].getElementsByTagName('span')[0];
            line_num.innerHTML += '<span>' + (j) + '</span>';
        }
    }
})();




function OpenClose(id){
  if (document.getElementById(id).style.height == "1.35em"){
        document.getElementById(id).style.height = "auto";
        document.getElementById(id).style.color = "#DDD";
        document.getElementById(id).style.borderWidth = "1px";
  }
  else{
        document.getElementById(id).style.height = "1.35em";
        document.getElementById(id).style.overflow = "hidden";
        document.getElementById(id).style.color = "#333";
        document.getElementById(id).style.borderWidth = "0px";  
  }
}


function Spread(what) {
    var boxes = document.getElementsByClassName(what);    
    nbboxes = boxes.length;
    for (var i = 0; i < nbboxes; i++) {
      var box = boxes[i];
      var pid = what + String(i); 
      (box).id = pid;
      var ch = 'OpenClose(' + pid + ')';
      box.setAttribute("onclick", 'OpenClose(this.id)');
      box.style.height = "1.35em";
      box.style.overflow = "hidden";
      box.style.color = "#333";      
      box.style.borderWidth = "0px";
    }
}


(function() {
  Spread('preuve');    
  Spread('solution');
})();
