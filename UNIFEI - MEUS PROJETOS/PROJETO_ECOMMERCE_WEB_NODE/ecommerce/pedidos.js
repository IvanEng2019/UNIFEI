import { lerLocalStorage, desenharCompra} from "./src/utilidades";

//cria o historico da compra de um pedido realizado
function criarHistoricoPedido(pedidoComData){
    const elementoPedido = 
    `
        <p class="text-xl text-bold my-4">
            ${new Date(pedidoComData.dataPedido).toLocaleDateString("pt-BR", 
                {
                    hour:"2-digit",
                    minute:"2-digit",
                })
            }
        </p> 
        <section id= 'container-pedidos-${pedidoComData.dataPedido}' class="bg-slate-300 p-3 rounded-md"> </section>
    `;
    const main = document.getElementsByTagName("main")[0];
    main.innerHTML += elementoPedido;

    for(const idProduto in pedidoComData.pedido){ // apresenta cada um dos produtos de um pedido
        desenharCompra(idProduto, pedidoComData.pedido[idProduto],`container-pedidos-${pedidoComData.dataPedido}`);
    }
    //function desenharCompra(idProduto, quantidadeProduto, idContainerHtml) {
}

//Apresenta  historico de todos os pedidos realizados (um a um)
function renderizarHistoricoPedidos(){
    const historico = lerLocalStorage("historico");
    for( const pedidoComData of historico){
        criarHistoricoPedido(pedidoComData);
    }
}

renderizarHistoricoPedidos();