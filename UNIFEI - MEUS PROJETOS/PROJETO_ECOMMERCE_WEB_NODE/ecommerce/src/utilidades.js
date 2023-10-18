//contem os dados de todos os produtos

export const catalogo = [
    {
      id: "1",
      marca: "Zara",
      nome: "Camisa Larga com Bolsos",
      preco: 70,
      imagem: "product-1.jpg",
      feminino: false,
    },
    {
      id: "2",
      marca: "Zara",
      nome: "Casaco Reto com Lã",
      preco: 85,
      imagem: "product-2.jpg",
      feminino: true,
    },
    {
      id: "3",
      marca: "Zara",
      nome: "Jaqueta com Efeito Camurça",
      preco: 60,
      imagem: "product-3.jpg",
      feminino: false,
    },
    {
      id: "4",
      marca: "Zara",
      nome: "Sobretudo em Mescla de Lã",
      preco: 160,
      imagem: "product-4.jpg",
      feminino: false,
    },
    {
      id: "5",
      marca: "Zara",
      nome: "Camisa Larga Acolchoada de Veludo Cotelê",
      preco: 110,
      imagem: "product-5.jpg",
      feminino: false,
    },
    {
      id: "6",
      marca: "Zara",
      nome: "Casaco de Lã com Botões",
      preco: 170,
      imagem: "product-6.jpg",
      feminino: true,
    },
    {
      id: "7",
      marca: "Zara",
      nome: "Casaco com Botões",
      preco: 75,
      imagem: "product-7.jpg",
      feminino: true,
    },
    {
      id: "8",
      marca: "Zara",
      nome: "Colete Comprido com Cinto",
      preco: 88,
      imagem: "product-8.jpg",
      feminino: true,
    },
  ];

  //salvar os dados do carrinho
  export function salvarLocalStorage(chave,valor){
    localStorage.setItem(chave,JSON.stringify(valor)); //transforma o objeto em texto p/salvar
  }

   //recupera (le) os dados do carrinho
  export function lerLocalStorage(chave){
    return JSON.parse(localStorage.getItem(chave)); //Transforma o texto em objeto
  }

  //apaga os dados do pedido que ja foi finalizado
  export function apagarDoLocalStorage(chave) {
    localStorage.removeItem(chave);
  }

  //Funçao para apresentar no checkout- final da compra
  //Diferente da do carrinho onde podera ser alterado a quantidade e o valor
  //Além de informar os id dos produtos e a quantidade devera ser informado o local aonde sera desenhado (local thtml do checkoout)
  export function desenharCompra(idProduto, quantidadeProduto, idContainerHtml) {

    const produto = catalogo.find((p) => p.id === idProduto);//encontra o produto no dicionario
    const containerProdutosCompra= document.getElementById(idContainerHtml);//define o local aonsw sera apresentado o produto
    const elementoArticle = document.createElement("article"); // cria o elemento <article></article>
    const articleClasses = ["flex","bg-stone-200", "rounded-lg","p-1","relative","mb-2","w-96"];//cria array de classes
  
    for (const articleClass of articleClasses) { // atrribui as classes ao elemento criado
      elementoArticle.classList.add(articleClass);
    }
    //<article class="flex bg-slate-100 rounded-lg p-1 relative"></article>
  
    //cria o card do produto igualmente do carrinho
    const cartaoProdutoCompra = 
    `
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
        <p id="qtd-${produto.id}" class="ml-2 font-bold">${quantidadeProduto}</p>
      </div>
    `;
  
    elementoArticle.innerHTML = cartaoProdutoCompra;
    containerProdutosCompra.appendChild(elementoArticle);
  }