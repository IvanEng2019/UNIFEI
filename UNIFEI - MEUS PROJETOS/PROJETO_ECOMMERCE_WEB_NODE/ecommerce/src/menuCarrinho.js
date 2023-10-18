//contem as funçoes do carrinho

import { catalogo, salvarLocalStorage, lerLocalStorage } from "./utilidades"; //contem os dados do produto

//cria o objeto dicionario que associa o id do produto a quantidade dele no carrinho
//verifica se ha dados salvos no localStorage se não houver (vazio) irá carregar o carrinho posteriormente
const idQtdProdutoCarrinho= lerLocalStorage("carrinho") ?? {};

//função que permite o usuario visualizar o carrinho
// em section id=carrinho do index faz o atributo right da classe 
// remover -360px e começar em 0px para assim ser visualizado pelo usuário
function abrirCarrinho(){ 
    document.getElementById("carrinho").classList.add("right-[0px]");
    document.getElementById("carrinho").classList.remove("right-[-360px]");
}

// função que oculta o carrinho
// em section id=carrinho do index faz o atributo right da classe 
// remover 0px e começar em -360px para assim ser ocultado do usuário
function fecharCarrinho(){
    document.getElementById("carrinho").classList.remove("right-[0px]");
    document.getElementById("carrinho").classList.add("right-[-360px]");
}

//Finalizar as compras do carrinho indo para checkout
function irParaCheckout() {
  //verifica se a lista do carrinho esta vazia
  if (Object.keys(idQtdProdutoCarrinho).length === 0) {
    return;
  }
  //se nao estiver vazia ira para pagina de checkout
  window.location.href = '/checkout.html';
 // window.location.href = window.location.origin + '/pedidos.html';
}

// função que diz quando abrir e fechar o carrinho
export function inicializarCarrinho(){
    const botaoFecharCarrinho = document.getElementById("fechar-carrinho");
    const botaoAbrirCarrinho = document.getElementById("abrir-carrinho");
    const botaoIrParaCheckout = document.getElementById("finalizar-compra-carrinho");

    botaoFecharCarrinho.addEventListener("click", fecharCarrinho); //quando clicar em button id="abrir-carrinho" o carrinho deverá abrir
    botaoAbrirCarrinho.addEventListener("click", abrirCarrinho); //quando clicar em button id="fechar-carrinho"  o carrinho deverá se ocultar
    botaoIrParaCheckout.addEventListener("click", irParaCheckout); //quando clicar em buttom id "finalizar-compra" ira pra pagina de checkout
}

//aumenta a qtd de produto no carrinho
function incrementarQtdProduto(idProduto){
  idQtdProdutoCarrinho[idProduto]++; //aumenta a qtd do produto
  salvarLocalStorage("carrinho",idQtdProdutoCarrinho); //salva os dados do carrinho
  atualizarPrecoCarrinho();//atualiza valor total da compra
  atualizaQtdProduto(idProduto); //atualiza a qtd no carrinho para mostrar
}

//diminui a qtd de produto no carrinho
function decrementarQtdProduto(idProduto){
  //se a quantidade do produto for 1 e ainda quiser diminuir 1 ( irei retirar do carrinho)
  // logica: se esta com um no carinho e quero zerar (clicand em -) quero entao retirar do carrinho
  if(idQtdProdutoCarrinho[idProduto] === 1){
    removerDoCarrinho(idProduto);
    atualizarPrecoCarrinho();
    return 0;
  }

  idQtdProdutoCarrinho[idProduto]--; //diminui a qtd do produto
  salvarLocalStorage("carrinho",idQtdProdutoCarrinho); // salva o carrinho
  atualizarPrecoCarrinho(); //atualiza o valor da compra
  atualizaQtdProduto(idProduto); // recria o carrinho
}

//atualizar a qtd do produto no carrinho
function atualizaQtdProduto(idProduto){
  document.getElementById(`qtd-${idProduto}`).innerText = idQtdProdutoCarrinho[idProduto];
}

//remover cartao-produto do carrinho: remover do html e do dicionario
function removerDoCarrinho(idProduto){
  delete idQtdProdutoCarrinho[idProduto]; //remove o campo (que contem o id) do objeto dicionario
  salvarLocalStorage("carrinho",idQtdProdutoCarrinho); //salva carrinho
  atualizarPrecoCarrinho();//atualiza valor da compra
  //remove o elemento html da tela
  //duas formas:so remove o elemento html ou reconstruir o carinho com o dicionario atualizado
  //Forma escolhida: a segunda
  renderizarProdutoCarrinho();//remonta o carrinho
}

//coloca visualmente o cartao-produto no carrinho
function desenharProdutoNoCarrinho(idProduto){
  const produto = catalogo.find ((p) => p.id === idProduto);// compara o id do produto solicitado com o id do produto existente no catalogo
  const containerProdutoCarrinho = document.getElementById('produtos-carrinho'); //atribui -> section id="produtos-carrinho" do index

  //cria o elemento html do tipo article pois o html ao remontar a extrutura dada como texto deixa de reconhecer as estrutura anterior como html (perde as propriedades)
  const elementoArticle = document.createElement("article");
  const articleClasses = ["flex", "bg-slate-200", "rounded-lg", "p-2", "relative"];
  for(const articleClass of articleClasses){
    elementoArticle.classList.add(articleClass);
  }

  const cartaoProdutoCarrinho = 
  ` 
    <!-- Botão x que remover o card do carrinho independente da qtd --> 
    <button id="remover-item-${produto.id}" class="absolute top-1 right-2" >
      <i class="fa-solid fa-circle-xmark text-slate-500 hover:text-slate-900"></i>
    </button>

    <img src="./assets/img/${produto.imagem}"
      alt="Carrinho:${produto.nome}" 
      class="h-24 rounded-lg"
    />

    <div class="ml-4 flex flex-col justify-between" >
        <p class="text-slate-900 text-sm font-bold"> ${produto.nome} </p>
        <p class="text-slate-700 text-xs"> Tamanho: M </p>
        <div class="py-3">
          <p class="text-slate-700 text-xs">Preço Unitário</p>
          <p class="text-green-900 text-lg font-bold">R$ ${produto.preco}</p>
        <div>
    </div>

    <div class="flex text-slate-950 items-end absolute bottom-8 right-3">
      <p class="text-xs">Quantidade</p>
    </div>

    <div class="flex text-slate-950 items-end absolute bottom-1 right-3 text-lg ">
      <button class="ml-2" id="decrementar-produto-${produto.id}"> 
        <i class="fa-solid fa-circle-minus"></i>
      </button>
      <p id="qtd-${produto.id}" class="ml-2 font-bold">${idQtdProdutoCarrinho[produto.id]}</p>
      <button class="ml-2" id="incrementar-produto-${produto.id}"> 
        <i class="fa-solid fa-circle-plus"></i>
      </button>
    </div>
  `;

  //cria o cartão-produto que ira dentro do carrinho
  elementoArticle.innerHTML=cartaoProdutoCarrinho;
 
  ///acrescenta visualmente o cartão-produto no corrinho com os dados
  containerProdutoCarrinho.appendChild(elementoArticle);

  //descrementa a qtd de produto no carrinho quando clicado em menos no carrinho
  document.getElementById(`decrementar-produto-${produto.id}`).addEventListener("click", ()=> decrementarQtdProduto(produto.id));

  //aumenta a qtd de produto no carrinho quando clicado em mais no carrinho
  document.getElementById(`incrementar-produto-${produto.id}`).addEventListener("click", ()=> incrementarQtdProduto(produto.id));

  //remove o cartao-produto do carrinho quando clicado em x
  document.getElementById(`remover-item-${produto.id}`).addEventListener("click", ()=> removerDoCarrinho(produto.id));

}

//para cada produto atual do dicionario coloca-os no carrinho 
export function renderizarProdutoCarrinho(){
  const containerProdutoCarrinho = document.getElementById('produtos-carrinho'); //atribui -> section id="produtos-carrinho" do index
  containerProdutoCarrinho.innerHTML = "";

  //reconstroi visualmente cada produto no carrinho
  for(const idProduto in idQtdProdutoCarrinho){
    desenharProdutoNoCarrinho(idProduto);
  }
}

//função para adicionar o produto no carrinho
//deverá receber como argumento o id do produto
//caso o id recebido ao clicar no carrinho do card do produto seja o mesmo presente no catalogo
//o produto então será colocado no carrinho
//se o produto ja existir no carrinho bastara aumentar a sua quantidade
//caso contrario só colocar qtd=1 e coloca-lo no carrinho
export function addCarrinho(idProduto){
  //se o produto ja existir no objeto dicionario entao so incrementar a sua quantidade
  if(idProduto in idQtdProdutoCarrinho){
    incrementarQtdProduto(idProduto);
    return;
  }

  //caso o objeto nao exista no dicionario sua qtd inicial será 1
  idQtdProdutoCarrinho[idProduto]=1;

  //salva o carrinho por chave-valor
  salvarLocalStorage("carrinho",idQtdProdutoCarrinho);

  //cria o cartao-produto no carrinho
  desenharProdutoNoCarrinho(idProduto);

  //atualiza o valor final de compra
  atualizarPrecoCarrinho()

}

//recalcula e mostra o valor total da compra
export function atualizarPrecoCarrinho(){
  const precoCarrinho=document.getElementById("preco-total");
  let precoTotal = 0;

  //para cada produto do dicionario pega o valor do preço e multiplique pela qtd somando ao valor anterior de precoTotal
  for(const idProdutoCarrinho in idQtdProdutoCarrinho){
    precoTotal += catalogo.find( (p)=> p.id === idProdutoCarrinho).preco * idQtdProdutoCarrinho[idProdutoCarrinho];
  }
  precoCarrinho.innerText = ` R$ ${precoTotal}`; //apresenta o valor da total da compra
}

