const catalogoProdutos = document.getElementById("container-produto");


//exibe todos os produtos da loja
function exibirTodos(){
    //pega todos os produtos com classe hidden e coloca em um array
    const produtosEscondindos=Array.from(catalogoProdutos.getElementsByClassName("hidden"));
    for(const produto of  produtosEscondindos){ //para cada produto escondido faça
        produto.classList.remove("hidden"); //remove a opção de esconder
    }
}

//esconde todos os produtos masculinos
function esconderMasculinos(){
   exibirTodos(); // exibe todos os produtos novamente para depois mostrar apenas os femininos
   const produtosMasculinos =  Array.from(catalogoProdutos.getElementsByClassName('masculino'));

   for(const produto of produtosMasculinos){
        produto.classList.add("hidden");
   }
}

//esconde todos os produtos femininos
function esconderFemininos(){
    exibirTodos(); // exibe todos os produtos novamente para depois mostrar apenas os masculinos
    const produtosFemininos =  Array.from(catalogoProdutos.getElementsByClassName('feminino'));
 
    for(const produto of produtosFemininos){
         produto.classList.add("hidden");
    }
 }
 
// Quando clicar em um dos filtros
// se todos-> exibira todos os produtos da loja;
// se femnino -> exibira todos os femininos, escondendo os masculinos;
// se masculino -> exibira todos os masculinos, escondnedo o feminino;
export function inicializarFiltros(){
    document.getElementById("exibir-todos").addEventListener("click", exibirTodos);
    document.getElementById("exibir-feminino").addEventListener("click", esconderMasculinos);
    document.getElementById("exibir-masculino").addEventListener("click", esconderFemininos);
}