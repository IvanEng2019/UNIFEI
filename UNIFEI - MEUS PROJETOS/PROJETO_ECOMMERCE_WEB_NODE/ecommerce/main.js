import { renderizarCatalogo } from "./src/cardProduto";
import { inicializarFiltros } from "./src/filtros";
import { atualizarPrecoCarrinho, inicializarCarrinho, renderizarProdutoCarrinho} from "./src/menuCarrinho";

renderizarCatalogo();
inicializarCarrinho();
renderizarProdutoCarrinho();
atualizarPrecoCarrinho();
inicializarFiltros();
