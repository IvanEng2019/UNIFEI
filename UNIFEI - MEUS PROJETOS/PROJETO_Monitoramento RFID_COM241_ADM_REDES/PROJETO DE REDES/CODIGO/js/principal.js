(function readyJS(win,doc){
    if(doc.querySelectorAll('.deletar')){
        for(let i=0; i < doc.querySelectorAll('.deletar').length; i++){
            doc.querySelectorAll('.deletar')[i].addEventListener('click',function(event){
                if(confirm("Deseja mesmo apagar?")){
                    return true;
                }else{
                    event.preventDefault();
                }
            });
        }
    }
})(window,document);


/*$(document).ready(function(){
    $("#bt1").click(function cronometro(evento,tempo){
        var atual = new Date();
        var tInicial= tempo;
        var tempoDecorrido= atual-tInicial;
        $("#tabelaControle").append(`<td>${tempoDecorrido}</td>`);
    });
});*/

/*function cronometro(evento, tempo){
    var atual = new Date();
    var tInicial= tempo;
    var tempoDecorrido= atual-tInicial;
    var linha = document.getElementById("#linha");
    var celula = document.createElement("td");
    celula.appendChild(tempoDecorrido);
    linha.appendChild(celula);
    if(evento==1 && tempoDecorrido>1){
        alert("Passou de um hora dentro do local");
    }
}*/

/*
$(document).ready(function () {
    $("#bt1").click(function () {
        var dados = $('input');
        var atual = new Date();
        var tInicial= dados[3];
        var tempoDecorrido= atual - tInicial;
        $("#tabelaControle").append("<tr><td>" + tempoDecorrido+ "</td></tr>");
    });
});*/

function cronometro(evento, tempo){
    var atual = new Date();
    var tInicial= tempo;
    var tempoDecorrido= atual-tInicial;
    var table = document.getElementById("#tabelaControle");
    var linha = document.createElement("tr");
    var celula = document.createElement("td");
    celula.appendChild(tempoDecorrido);
    linha.appendChild(celula);
    table.appendChild(linha);
    if(evento==1 && tempoDecorrido.hours>1){
        alert("Passou de um hora dentro do local");
    }
}