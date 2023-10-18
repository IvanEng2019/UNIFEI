import { addCarrinho } from "./menuCarrinho"; //contem as funçoes do carrinho
import { catalogo } from "./utilidades"; //contem os dados do produto

//realiza a colocação dos produtos do catalogo em cards para o usuário
export function renderizarCatalogo(){
    for (const produtoCatalogo of catalogo) { //para cada produto do catalogo faça
        const cartaoProduto = 
        `
            <div class="w-48 m-2 shadow-xl shadow-slate-400 rounded-lg flex flex-col p-2 justify-between group ${produtoCatalogo.feminino ? 'feminino' : 'masculino'}" id="card-produto-${produtoCatalogo.id}">
                <img
                    src="./assets/img/${produtoCatalogo.imagem}"
                    alt="Produto "${produtoCatalogo.nome}" do ecommerce Underlyng."
                    class="group-hover:scale-110 duration-500 my-3 rounded-lg"
                />
                <div class="text-xs font-bold flex flex-col text-center text-slate-950">
                    <p class="my-2"> ${produtoCatalogo.nome} </p>
                    <div class="my-2">
                        <p class="text-slate-700"> Marca </p>
                        <p>${produtoCatalogo.marca}</p>
                    </div>
                    <div class="my-1">
                        <p class="text-slate-700 text-xs"> Preço Unitário </p>
                        <p> R$ ${produtoCatalogo.preco}</p>
                    </div>
                </div>
                <button id="adicionar-${produtoCatalogo.id}" class="bg-slate-950 hover:bg-slate-700 text-slate-200">
                    <i class="fa-solid fa-cart-plus"></i>
                </button>
            </div>
        `;
    
        document.getElementById("container-produto").innerHTML += cartaoProduto; //coloca em main->section->container-produto todos os produtos do catalago
    }

    //quando clicar no carrinho do produto ira adicionar o produto no carrinho
    for (const produtoCatalogo of catalogo){
        document.getElementById(`adicionar-${produtoCatalogo.id}`).addEventListener("click",() => addCarrinho(produtoCatalogo.id));
    }
}