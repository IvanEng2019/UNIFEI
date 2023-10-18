import { catalogo, apagarDoLocalStorage, salvarLocalStorage, desenharCompra, lerLocalStorage} from "./src/utilidades"; 

//*recalcula e mostra o valor total da compra
function atualizarPrecoCompra(idQtdProdutoCarrinho){
    const precoCarrinhoCompra=document.getElementById("preco-total-compra");
    let precoTotal = 0;
  
    //para cada produto do dicionario pega o valor do preço e multiplique pela qtd somando ao valor anterior de precoTotal
    for(const idProdutoCarrinho in idQtdProdutoCarrinho){
      precoTotal +=catalogo.find( (p)=> p.id === idProdutoCarrinho).preco * idQtdProdutoCarrinho[idProdutoCarrinho];
    }
    precoCarrinhoCompra.innerText = ` R$ ${precoTotal}`; //apresenta o valor da total da compra
  }

// apresenta os produtos comprados
function desenharProdutoCheckout(){
    const idQtdProdutoCarrinho = lerLocalStorage("carrinho") ?? {}; //le os produtos do carrinho
    atualizarPrecoCompra(idQtdProdutoCarrinho);
    for (const idProduto in idQtdProdutoCarrinho){
        desenharCompra(idProduto, idQtdProdutoCarrinho[idProduto], "container-produto-checkout");
    }
    
}

//finaliza a compra dos produtos
//limpa o carinho, mas antes coloca a compra no historico
function finalizarCompra(evento){
    evento.preventDefault();//elimina o comportamento de enviar o formulario(subimit) a algum lugar
    
    const idQtdProdutoCarrinho= lerLocalStorage("carrinho") ?? {}; //le os produtos do carrinho
    if(Object.keys(idQtdProdutoCarrinho).length ===0){
        return 0;
    }
    
    const dataAtual = new Date();
    const pedidoFeito ={
        dataPedido: dataAtual,
        pedido: idQtdProdutoCarrinho
    }

    //salva o historico do pedido do cliente
    const historicoDePedidos = lerLocalStorage('historico') ?? [];
    // ... indica operador de espalhamento -> tranforma as lista em elemento simples
    // pega o ultimo pedido e adiciona com os elementos da lista antiga
    const historicoDePedidosAtualizado = [pedidoFeito, ...historicoDePedidos];

    salvarLocalStorage('historico',historicoDePedidosAtualizado);
    apagarDoLocalStorage('carrinho'); //paga dados do carrinho

    window.location.href = window.location.origin + '/pedidos.html';
 
}


desenharProdutoCheckout();

//so há pagina a ser submetida que é a pag de checkout
//a propria pagina sera capaz de escutar um evento (submit) e responder a ele ( finalizando a compra)
document.addEventListener("submit", (evento) => finalizarCompra(evento));

