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
      for(var i = 0; i < accent.length; i++)
	str = str.replace(accent[i], noaccent[i]);
      return str;
}
			 

function Token(type, value) {
    this.type = type;
    this.value = value;
}

function IsVar(ch) {
    return /[a-z]/i.test(ch);
}

function IsNeg(ch) {
    return /\!/.test(ch);
}

function IsAdd(ch) {
    return /\+/.test(ch);
}

function IsLP(ch) {
    return /\(/.test(ch);
}

function IsRP(ch) {
    return /\)/.test(ch);
}

function Token2Str(Token){
    return Token.type + ": "+ Token.value;
}

function Tokens2Str(Tokens){
    var str = "";
	for (var i=0; i < Tokens.length; i++)
	    str += Token2Str(Tokens[i]) + "\n";
    return str;
}

function Tokens2RPN(Tokens){
    var str = "";
	for (var i=0; i < Tokens.length; i++)
	    str += Tokens[i].value + " ";
    return str;
}


function Tokenize(str) {
    var tokens = [];
    var i = 0;
    var nchar = str.length
    for (i = 0; i < nchar; i++){
	var c = str[i];	
	if (IsVar(c)){
	    tokens.push(new Token("VAR", c));
	    if (i < nchar - 1){
		var next = str[i+1];
		if ((IsVar(next)) || (IsNeg(next)) || (IsLP(next)))
		    tokens.push(new Token("BIN", "*"));
	    }
	}
	else if (IsAdd(c))
	    tokens.push(new Token("BIN", "+"));
	else if (IsNeg(c))
	    tokens.push(new Token("UNR", "!"));
	else if (IsLP(c))
	    tokens.push(new Token("LFP", "("));
	else if (IsRP(c)){
	    tokens.push(new Token("RGP", ")"));
	    if (i < nchar - 1){
		var next = str[i+1];
		if ((IsNeg(next)) || (IsLP(next)))
		    tokens.push(new Token("BIN", "*"));
	    }	    
	}
	else return [];
    }    
    return tokens;
}
    
var prec = {
    "!" : 3,
    "*" : 2,
    "+" : 1
};



// Evalue une fonction booléenne sous forme postfixe
// à l'aide d'une pile.  est un tableau associatif
// indiquant la valeur binaire de chaque
// variable de l'expression postfixe
function Evaluate(rpn,assign){
    var stack = [];
    var i = 0
    for (i = 0; i < rpn.length; i++){
	var token = rpn[i];
	if (token.type === "VAR")
	    stack.push(assign[token.value]);
	else if (token.type === "UNR")
	    stack[stack.length - 1] = 1 - stack[stack.length - 1];
	else if (token.type === "BIN"){
	    var right = stack.pop();
	    var left = stack.pop();
	    if (token.value === "+")
		stack.push((left + right > 0) ? 1:0);
	    else
		stack.push((left * right > 0) ? 1:0);
	}	    
    }
    return stack[0];
}

// Renvoie la table de vérité d'une fonction
// booléenne passée sous forme postfixe.
// assign est un tableau associatif qui fixe
// les valeurs booléennes de chaque variable clef
function TruthTable(rpn){
    var assign = new Object();
    var names = [];
    var nbvar = 0;
    var im = [];
    var i = 0;
    // crée la table de vérité des variables
    // logique tout à 0. rpn[i] est un token
    for (i = 0; i < rpn.length; i++){
	var tok = rpn[i];
	if ((tok.type === "VAR") && (!assign.hasOwnProperty(tok.value))){
	    assign[tok.value] = 0;
	    names.push(tok.value);
	    nbvar++;
	}	    
    }
    names.sort();
    var mask = 0;
    // On calcule l'image de la fonction booléenne
    // pour chacune des 2^nbvars variables booléennes
    for (mask = 0; mask < (1 << nbvar); mask++){
	var bit = 0;	
	for (bit = 0; bit < nbvar; bit++) 
	    assign[names[nbvar - (bit + 1)]] = ((1 << bit) & mask) ? 1:0;
	im.push(Evaluate(rpn,assign));
    }
    var out = new Object();
    out.im = im;
    out.names = names;
    return out;
}


// cf. Algorithme "Shunting Yard" de Dijkstra
// simplifié ici
function RPolish(tokens){
    var stack = [];
    var rpn = []
    var i = 0;
    var sl = 0;
    nbtoks = tokens.length;
    for (i = 0; i < nbtoks; i++){
	var token = tokens[i];
	if (token.type === "VAR")
	    rpn.push(token);
	else if ((token.type === "BIN") || (token.type === "UNR")) {
	    while (((sl = stack.length) > 0) &&
		   (stack[sl - 1].type != "LFP") &&
		   ((prec[token.value] <= prec[stack[sl - 1].value]))){
		rpn.push(stack.pop());
	    }
	    stack.push(token);
	}
	else if (token.type == "LFP")
	    stack.push(token);
	else if (token.type == "RGP") {
	    while (((sl = stack.length) > 0) &&
		   (stack[sl - 1].type !== "LFP"))
		rpn.push(stack.pop());
	    stack.pop();
	}
    }
    while (stack.length > 0)
	rpn.push(stack.pop());
    return rpn;
}

function boolean(tokens){
    var i = 0;
    var boolxpr = "";
    for (i = 0; i < tokens.length; i++){
	var c = tokens[i].value;
	if ((c == "!") || (c == "(") || (c == ")")
	    || (c == "*") || (c == "+")){
	    if (c == "!") 
		boolxpr += '<span class="op">&not;&thinsp;</span>';
	    else if (c == "*")
	    	boolxpr += '<span class="op">&thinsp;</span>';
	    else
		boolxpr += '<span class="op">&thinsp;'+c+'&thinsp;</span>';
	}
	else
	    boolxpr += '<span class="var y">'+c+'</span>';
    }
    return boolxpr;

}

function ShowTT(TT,tokens){
    var ch = '<center><table class="boole">';
    var i = 0;
    var mask = 0;
    var im = TT.im;
    var names = TT.names;
    var nbvar = names.length;
    ch += '<tr>';
    for (i = 0; i < nbvar; i++){
	ch += '<td class="it">'+names[i]+'</td>'
    }
    ch +='<td class="n">'+boolean(tokens)+'</td></tr>';
    for (mask = 0; mask < (1 << nbvar); mask++){
	var bit = 0;	
        ch +='<tr>';
	for (bit = 0; bit < nbvar; bit++){
	  var chb = ((1 << (nbvar - (bit + 1))) & mask) ? 1:0;
	  ch +='<td class="b">'+ chb +'</td>';
	}
	ch +='<td class="c">'+im[mask]+'</td>'+'</tr>';
    } 
    ch +="</table></center>";
    return ch;
}

function ShowCanonical(TT){
  var ch = '<center><table class="boole">';
  var mask = 0;   
  var names = TT.names;
  var im = TT.im;
  var nbvar = names.length;
  var fnc = [];
  var fnd = [];
  for (mask = 0; mask < (1 << nbvar); mask++){
    var bit = 0;
    var term = [];
    for (bit = 0; bit < nbvar; bit++){
      if (im[mask])
	var neg = ((1 << (nbvar - (bit + 1))) & mask) ? "" : "neg";
      else
	var neg = ((1 << (nbvar - (bit + 1))) & mask) ? "neg" : "";
    term.push('<span class="var ' + neg + '">'+names[bit]+'</span>');
    }
    if (im[mask])
      fnd.push(term.join("&thinsp;"));
    else
      fnc.push('('+term.join("&thinsp;+&thinsp;")+')');
  }
  ch +='<tr><td><span class="sc">fnd</span>(<i>f</i>)&#8239;:&nbsp;</td><td>' + 
    fnd.join("&thinsp;+&thinsp;") + '</td></tr>';
  ch +='<tr><td><span class="sc">fnc</span>(<i>f</i>)&#8239;:&nbsp;</td><td>' + 
    fnc.join("&thinsp;") + '</td></tr>';
  ch += "</table></center>";
  return ch;
}

function canon(expr){
   console.clear();
   expr = expr.sansAccent();
   expr = expr.toLowerCase();
   expr = expr.replace(new RegExp("[^(a-z)+!)(]", "g"),"");
   expr = expr.replace(new RegExp("!!", "g"),"");
   var tokens = Tokenize(expr);			 
   console.log(Tokens2Str(tokens));
   var rpn = RPolish(tokens);
   console.log("  RPN = "+Tokens2RPN(rpn));
   var TT = (TruthTable(rpn))
   console.log("  VAR = "+(TT.names).join(","));
   console.log("TRUTH = "+(TT.im).join(","));
   elemTT = document.getElementById("truthtable");    
   elemTT.innerHTML = ShowTT(TT,tokens);
   elemcan = document.getElementById("canonical");    
   elemcan.innerHTML = ShowCanonical(TT);
 }     
