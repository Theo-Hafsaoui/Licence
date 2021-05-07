//-----------------------------------------------------------
// Le codage des mouvements fournissant les 14 3-cycles
// du type (1,2,s). En 0 on a (1,2,5) qui sert de germe
// Les autres sont des conjugaisons de celui-ci
// d'où la liste vide en 5:[]
//------------------------------------------------------------
var MOVES = {
    0:[15,14,10,6,5,1,2,6,10,14,15],
    3:[15,14,13,9,5,1,2,3,4,8,12],
    4:[15,11,7,3,4,8,12,16,15,14,13,9,5,1,2,3,4,8,12],
    5:[],
    6:[15,14,13,9,5,6,7,8,12],
    7:[12,8,4,3,7,11,15,16,15,14,13,9,5,1,2,3,4,8,12],
    8:[15,11,7,3,4,8,12,16,15,11,7,3,4,8,12,16,15,14,13,9,5,1,2,3,4,8,12],
    9:[12,8,7,6,5,9,13,14,15],
    10:[12,8,7,6,5,9,10,14,15,16,12,8,7,6,5,9,10,14,15],
    11:[12,8,4,3,7,11,15,16,12,8,4,3,7,11,15,16,15,14,13,9,5,1,2,3,4,8,12],
    12:[15,11,7,3,4,8,12,16,15,11,7,3,4,8,12,16,15,11,7,3,4,8,12,16,15,14,13,9,5,1,2,3,4,8,12],
    13:[12,8,7,6,5,9,13,14,15,16,12,8,7,6,5,9,13,14,15],
    14:[12,8,7,6,5,9,13,14,15,16,12,8,7,6,5,9,13,14,15,16,12,8,7,6,5,9,13,14,15],
    15:[12,8,4,3,7,11,15,16,12,8,4,3,7,11,15,16,12,8,4,3,7,11,15,16,15,14,13,9,5,1,2,3,4,8,12]
}

function abs(x){
    return (x >= 0) ? x : -x;
}


//-------------------------------------------------------------------
// Mélange le contenu d'une liste.
// Permutation : cf. Knuth.
//-------------------------------------------------------------------
function Shuffle(list) {
  var i = list.length;
  var aux ;
  var irand;
  while (i !== 0) {
    irand = Math.floor(Math.random() * i);
    i = i - 1;
    aux = list[i];
    list[i] = list[irand];
    list[irand] = aux;
  }
  return list;
}


//------------------------------------------------------------------
// Conversion de la chaîne en tableau
//------------------------------------------------------------------
function Chain2Permutation(chain){
    var sigma = chain.split(/[\s,;\/]/).map(function(item){
        return parseInt(item, 10);});
    return sigma;
}

//-------------------------------------------------------------------
// Vérifie qu'un tableau de taille n est bien un élément de S(n)
//------------------------------------------------------------------
function IsPermutation(sigma){
    var magsi = [].concat(sigma);
    magsi.sort(function(a,b){return a - b;});
    var i = 0;
    while ((i < magsi.length) && (magsi[i] == (1 + parseInt(i))))
	i++;
    return (i == sigma.length);
}

//--------------------------------------------------------
// Permet de vérifier les factorisations
// Sortie sur la console.
//-------------------------------------------------------
function LogFactors(infos,factors){
    var i = 0;
    var ch = infos;
    for (i = 0; i < factors.length; i++)	
	ch += '(' + (factors[i]).join(",") + ') ';
    console.log(ch);	    
}


//---------------------------------------------------------------
// Décompose un cycle en produit de transpositions
// Les termes de la transposition sont ordonnés pour repérer
// Les égalité de transpositions. Utilisée dans la fonction suivante
//---------------------------------------------------------------
function CycleToSwaps(cycle){
    var factors = [];
    var i = 0;
    if ((cycle.length) == 2)
	factors.push(cycle);
    else for (i = 0; i < cycle.length - 1; i++){
	var tau = (cycle[i] < cycle[i+1]) ? [cycle[i],cycle[i+1]] :
	    [cycle[i+1],cycle[i]];
	factors.push(tau);
    }
    return factors;
}

//---------------------------------------------------------------
// Décompose une liste de cycles en produit de transpositions
//---------------------------------------------------------------
function CyclesToSwaps(cycles){
    var factors = [];
    var transp = [];
    var i = 0;    
    for (i = 0; i < cycles.length; i++){
	transp = CycleToSwaps(cycles[i]);
	factors = factors.concat(transp);
    }
    return factors;
}


//---------------------------------------------------------------
// Place l'élément le plus petit d'un 3-cycle à gauche
// en faisant une rotation du représentant c du 3-cycle
//---------------------------------------------------------------
function Shift(c){
    var aux = 0;
    if ((c[1] < c[0]) && (c[1] < c[2])){
	aux = c[0]; c[0] = c[1]; c[1] = c[2]; c[2] = aux;
    }
    else if ((c[2] < c[0]) && (c[2] < c[1])){
	aux = c[2]; c[2] = c[1]; c[1] = c[0]; c[0] = aux;
    }
    return c;
}

//------------------------------------------------------------------
// cf. preuve Théorème : le groupe alterné est engendré par
// les 3-cycles. Attention aux différents cas le théorème ne
// suppose pas que les termes des transpositions sont croissants
// Les cas: a < b  et c < d
// 4 valeurs distinctes (a,b)(c,d)
// 3 valeurs distinctes (a,b)(a=c,d) ou (a,b)(c,d=b) ou (a,b)(c=b,d)
// 2 valeurs distinctes: Id
// Renvoie le représentant du cycle avec la plus petite valeur
// à gauche
//-------------------------------------------------------------------
function SwapsTo3Cycles(product){
    var i = 0;
    var factors = [];
    for (i = 0; i < product.length; i +=2){
	var a = product[i][0];
	var b = product[i][1];
	var c = product[i + 1][0];
	var d = product[i + 1][1];
        if ((a == c) && (b != d)) 
	    factors.push(Shift([a,d,b]));
        else if ((a != c) && (b == d)) 
	    factors.push(Shift([a,b,c]));
	else if ((a != c) && (b == c)) 
	    factors.push(Shift([a,b,d]));
        else if ((a != c) && (b != d)){
	    factors.push(Shift([a,b,c]));
	    factors.push(Shift([b,c,d]));
	}
    }
    return factors;
}


//---------------------------------------------------------------
// cf. preuve Théorème : les 3-cycles (i,j,k) sont engendrés par
// les trois cycles de la forme (1,2,s). La sortie ne fournit
// que s ou -s si c'est le 3-cycle inverse.
// Attention à l'étude de cas ! En rangeant le + petit à gauche
// par rotation :
// (1,2,k) > rien à faire   
// (1,j,2) > (1,2,j)^{-1}
// (1,j,k) > (1,2,k)(1,2,j)^{-1}
// (2,j,k) > (1,2,k)^{-1}(1,2,j)   
// (i,j,k) > (1,2,k)(2,i,j)(1,2,k)^{-1}
//---------------------------------------------------------------
function ThreeCyclesTo3Cycles12s(product){
    var r = 0;
    var factors = [];
    for (r = 0; r < product.length; r++){
	var i = product[r][0];
	var j = product[r][1];
	var k = product[r][2];
	if ((i == 1) && (j == 2)){
	    factors.push([k]);
	}
	else if ((i == 1) && (k == 2)) {
    	    factors.push([-j]);
	}
	else if (i == 1)
	{
	    factors.push([k]);
	    factors.push([-j]);
	}
	else if (i == 2) {
    	    factors.push([-k]);
	    factors.push([j]);
	}
	else {	    
	    factors.push([k]);
	    factors.push([-j]);
	    factors.push([i]);
	    factors.push([-k]);
	}
    }
    return factors;  
}

//----------------------------------------
// signature d'une permutation déjà
// décomposée en produit de transpositions
//-----------------------------------------
function sign(transpositions){
    return ((transpositions.length % 2) == 0) ? (1) : (-1);
}

//---------------------------------------------------------
// Cherche le prochain début de cycle. Sert uniquement à
// la fonction de conversion en produit de cycles
//---------------------------------------------------------
function Next(flags,i){
    i++;
    while ((i < 16) && ((flags & (1 << i)) == 0))
	i++;
    return i;  
}

//---------------------------------------------------------
// cf. preuve Théorème : 
// i € [1,15]
//----------------------------------------------------------
function PermutationToCycles(sigma){
    var factors = [];
    var flags = (1 << 16) - 2;
    var i = 0;
    var start = 0;
    var cycle = [];
    while (flags > 0){
	i = Next(flags,i);
	start = i;
	cycle = [start];
	flags ^= 1 << start;
	while (sigma[start - 1] != i){
	    start = sigma[start - 1];
	    cycle.push(start);
	    flags ^= 1 << start;
	}	
	if (cycle.length > 1)
	    factors.push(cycle);
    }
    return factors;
}


//===============================================================
// DOM de la page HTML
//===============================================================
var dom_jeu;
// Le jeu
var piece, taquin, videlig, videcol;

//-------------------------------------------------------
// Déplacement de la pièce vide en (l,c)
// Le glissement de pièces contiguës sur un même axe
// est possible
//-------------------------------------------------------
function MoveTo(l, c) {
  var k, s, dk;
  if ((l === lempty) && (c === cempty)) {
    return;
  } 
  else if (l === lempty) {
    dk = c - cempty;
    s = dk < 0 ? -1 : 1;
      for (k = 0; k < s * dk; k += 1){
	  taquin[l][cempty + s * k] = taquin[l][cempty + s * (k + 1)];
      }
    taquin[l][cempty + dk] = 16;
    cempty = c;
  } 
  else if (c === cempty) {
    dk = l - lempty;
    s = dk < 0 ? -1 : 1;
    for (k = 0; k < s * dk; k += 1)
      taquin[lempty + s * k][c] = taquin[lempty + s * (k + 1)][c];
    taquin[lempty + dk][c] = 16;
    lempty = l;
  } 
}

//---------------------------------------------------------
// Affiche à nouveau le contenu du taquin
// La pièce vide #16 change simplement d'attribut css .oui
// pour devenir invisible. L'attribut css .fix permet de voir
// les pièces en bonne position.
//----------------------------------------------------------
function Refresh() {
  var l, c;
  for (l = 0; l < 4; l++) {
      for (c = 0; c < 4; c++) {
	  piece[l][c].innerHTML = String(taquin[l][c]);
	  var cname = 'piece ';
	  cname += (taquin[l][c] === 16) ? " non" : " oui";
	  cname += (taquin[l][c] === (l*4 + c + 1)) ? " fix" : "";
	  piece[l][c].className = cname;
    }
  }
}


//-------------------------------------------------------------
// Déplacement des pièces suivant un click de souris
// Vérifie avant que le taquin est à l'arrêt
//-------------------------------------------------------------
function ClickTile(l, c) {
    if (typeof interval != "undefined") {   
        clearInterval(interval);
    }    
    MoveTo(l, c);
    sigma = Taquin2Sigma();
    var elemchsigma = document.getElementById("chsigma");
    elemchsigma.value = sigma.join(" ");
    Refresh();
}

//--------------------------------------------------------------
// Rajoute un élément de type <TD> dans la table
// qu définit le taquin
//--------------------------------------------------------------
function ajouterTDcaseA(noeud, l, c) {
    var element, bouton;
    element = document.createElement("td");
    element.setAttribute("class", "boite");
    bouton = document.createElement("button");
    bouton.setAttribute("onclick", 'ClickTile(' + l + ',' + c + ')');
    element.appendChild(bouton);
    noeud.appendChild(element);
    piece[l][c] = bouton;
}


//---------------------------------------------------------------
// Appelée à interval régulier, elle montre les mouvements
// successifs sur le taquin suivant le contenu du tableau
// solution censé remettre les pièces en place.
//----------------------------------------------------------------
function ShowMoves(){
    if (step >= solution.length) {   
        clearInterval(interval);
	return;
    }
    eleminfos.innerHTML = "<br>Cette configuration est résoluble. "
      + (step+1) + "/" + solution.length+".";
    var box = solution[step++];
    var l = 0;
    var c = 0;
    l = Math.trunc((box - 1) / 4);
    c = (box - 1) % 4;
    MoveTo(l,c);
    sigma = Taquin2Sigma();
    Refresh(taquin);
    return;
}

//---------------------------------------------------------
// Initialise le taquin. Si rand > 0, les pièces sont
// placées au hasard.
//---------------------------------------------------------
function InitTaquin(chsigma,rand,erase){
    eleminfos = document.getElementById("infos");
    if (erase)
      eleminfos.innerHTML = "&nbsp;";
    if (typeof interval != "undefined") {   
        clearInterval(interval);
    }
    sigma = Chain2Permutation(chsigma);
    if ((!IsPermutation(sigma)) || (sigma.length < 16)){
	eleminfos.innerHTML = "Vous n'avez pas saisi une permutation&#8239;!";
	return;
    }	
    if (rand){
	sigma = Shuffle([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]);
        var elemchsigma = document.getElementById("chsigma");
	elemchsigma.value = sigma.join(" ");
    }    
    taquin = Sigma2Taquin(sigma);
    Refresh(taquin);    
}

//----------------------------------------------
// Attention à .reverse qui modifie le tableau !!
//-----------------------------------------------
function Conjugate(i){
    var conj = [];
    conj = conj.concat([16]);
    var edge = [].concat(MOVES[abs(i)]);
    conj = conj.concat(edge);
    conj = conj.concat([16]);
    conj = conj.concat(MOVES[0]);
    conj = conj.concat([16]);
    conj = conj.concat(edge.reverse());
    conj = conj.concat([16]);
    return (i > 0)? conj: conj.reverse();
}



//------------------------------------------------
// Elimine les mouvements inutiles dans la séquence
// type (1,2,s)(1,2,s)^{-1}
// 6 16 11 14 3 1 9 4 2 10 5 7 15 8 12 13
//-------------------------------------------------
function Reduce3Cycles(cycles){
    var shorter = [];
    var i = 0;
    var last = 0;
    if (cycles.length > 0)
	shorter.push(cycles[0]);
    for (i = 1; i < cycles.length; i++) {
	last = shorter.length - 1;
	if (cycles[i][0] + shorter[last][0] == 0)
	    shorter.pop();
	else if (cycles[i][0] - shorter[last][0] == 0){
	    shorter.pop();
	    shorter.push([-cycles[i][0]]);
	}
	else
	    shorter.push(cycles[i]);
    }
    return shorter;
}



//------------------------------------------------
// Déplace la pièce vide  dans le coin inférieur
// droit
//-------------------------------------------------
function MoveToCorner(){
    MoveTo(lempty,3);
    MoveTo(3,3);
    Refresh();
    sigma = Taquin2Sigma();
}

//------------------------------------------------
// Déduit la liste des déplacements à réaliser
// sur le taquin pour réaliser les 3-cycles
// du type (1,2,s) de factors qui n contient
// que les valeurs s.
// Le moves.pop() enlève un déplacement inutile
// de la pièce vide en 16.
// Il est remis uniquement en fin de composiition
//------------------------------------------------
function SnakeFrom(factors){
    var snake = [];
    var i = 0;
    var nbsteps = factors.length;
    for (i = 0; i < nbsteps; i++){
	var step = (factors[nbsteps-(i+1)])[0];
	var moves = Conjugate(-step);
	moves.pop();
	snake = snake.concat(moves);
    }
    snake.push(16);
    return snake;
}

//------------------------------------------------------------
// Elimine des déplacements ceux qui sont inutiles:
// a > b > a  <=>  a
//------------------------------------------------------------
function ReduceSnake(snake){
    var shorter = [];
    var i = 0;
    if (snake.length > 0)
	shorter.push(snake[0]);
    for (i = 1; i < snake.length - 1; i++) {
	if (snake[i+1] == shorter[shorter.length-1])
	    shorter.pop();
	else
	    shorter.push(snake[i]);
    }
    shorter.push(snake[i]);	
    return shorter;
}


//-------------------------------------------------------------
// RÉSOLUTION DU TAQUIN.
// On charge la permutation saisie et on ramène au préalable
// la case vide dans le coin inférieur droit.
//-------------------------------------------------------------
function SolveTaquin(chsigma){
    console.clear();
    InitTaquin(chsigma,0);
    MoveToCorner();
    step = 0;
    var factors = PermutationToCycles(sigma);
    LogFactors("        Cycles: ",factors);
    factors = CyclesToSwaps(factors);
    LogFactors("Transpositions: ",factors);
    var prefixe = "<br>Cette con&shy;fi&shy;gu&shy;ra&shy;tion est ";
    if (sign(factors) < 0){
      eleminfos.innerHTML = prefixe + "in&shy;so&shy;lu&shy;ble.";
      return 0;
    }
    else
      eleminfos.innerHTML = prefixe + "résoluble&#8239;:";    
    var factors = SwapsTo3Cycles(factors);
    LogFactors("      3-Cycles: ",factors);
    factors = ThreeCyclesTo3Cycles12s(factors);
    LogFactors("Cycles (1,2,s): ",factors);
    factors = Reduce3Cycles(factors);
    LogFactors("Réduction:      ",factors);
    solution = ReduceSnake(SnakeFrom(factors));
    console.log("Déplacements: > "+solution.join(" > "));
    if (typeof interval != "undefined") {   
        clearInterval(interval);
    }    
    delay = Math.min(Math.trunc(100000 / solution.length),1000);
    interval = window.setInterval(ShowMoves,delay);
}


//------------------------------------------------------------
// Récupère la permutation liée à la positions des pièces
// sur le taquin
//------------------------------------------------------------
function Taquin2Sigma(){
    var sigma = [];
    var l = 0;
    var c = 0;
    for (l = 0; l < 4; l++)
	for (c = 0; c < 4; c++)
	    sigma[l * 4 + c] = taquin[l][c];
    return sigma;
}

//------------------------------------------------------------
// Place les pièces sur le taquin selon la permutation sigma
// et initialise la positions de la pièce vide (lempty,cempty)
//------------------------------------------------------------
function Sigma2Taquin(sigma){
    var taquin = [];
    var line = [];
    var i = 0;
    while (i < 16){
	if (sigma[i] == 16){
	    lempty = Math.trunc(i / 4);
	    cempty = i % 4;
	}
	line.push(sigma[i++]);
	if ((i % 4) == 0){
	    taquin.push(line);
	    line = [];
	}
    }
    taquin.push(line);
    return taquin;
}


//--------------------------------------------------------------
// Construction du taquin
//--------------------------------------------------------------
function BuildTaquin() {
    dom_jeu = document.getElementById("taquin");
    var li, co, dom_table, dom_tody, dom_tr;
    dom_table = document.createElement("table");
    dom_table.setAttribute("class", "anime");
    dom_jeu.appendChild(dom_table);
    dom_tody = document.createElement("tbody");
    dom_table.appendChild(dom_tody);
    piece = [[null, null, null, null], [null, null, null, null],
	     [null, null, null, null], [null, null, null, null]];
    sigma = Chain2Permutation("1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16");
    taquin = Sigma2Taquin(sigma);
    var l = 0;
    var c = 0;
    for (l = 0; l < 4; l++) {
	dom_tr = document.createElement("tr");
	dom_tody.appendChild(dom_tr);
	for (c = 0; c < 4; c++) {
	    ajouterTDcaseA(dom_tr, l, c);
	}
    }
    Refresh(taquin);
}


