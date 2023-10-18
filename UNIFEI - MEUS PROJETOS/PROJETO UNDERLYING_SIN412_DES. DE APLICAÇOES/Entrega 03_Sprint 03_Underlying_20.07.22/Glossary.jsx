class Glossary extends Component {
    render() {
      return (
        <React.Fragment>
          <div className="page-content">
            <MetaTags>
              <title>Glossário</title>
            </MetaTags>
            <Container fluid>

              <h2>Glossário</h2>

              <h4> A seguir são apresentados em ordem de complexidade os principais termos e expressões que contemplam o domínio do mercado de opções do sistema Underlying:</h4>
              
              <Row>
                <Col>
  
                  <Card id="cardBolsa">
                    <CardBody>
                      <h4>Bolsa</h4>
                      A bolsa de valores é o mercado organizado onde se negociam ações de sociedades de capital aberto e outros valores mobiliários, tais como as opções.
                    </CardBody>
                  </Card>
  
                  <Card id="cardB3">
                    <CardBody>
                      <h4>B3</h4>
                      B3 é a bolsa de valores oficial do Brasil, sediada na cidade de São Paulo.
                    </CardBody>
                  </Card>

                  <Card id="cardOpcoes">
                    <CardBody>
                      <h4>Opções</h4>
                      Representam um contrato que dá ao seu titular o direito de comprar ou de vender um determinado ativo por um valor determinado em uma data específica do futuro.
                    </CardBody>
                  </Card>

                  <Card id="cardAtivoObjeto">
                    <CardBody>
                      <h4>Ativo-Objeto</h4>
                      O ativo-objeto de uma opção é o bem, a mercadoria ou o ativo que está sendo negociado.
                    </CardBody>
                  </Card>

                  <Card id="cardTitular">
                    <CardBody>
                      <h4>Titular</h4>
                      É aqule que compra a opção e, por consequência, o direito de comprar ou vender o ativo-objeto
                    </CardBody>
                  </Card>

                 <Card id="cardLançador">
                    <CardBody>
                      <h4>Lançador</h4>
                      É aquele que vende a opção para o titular, assumindo a obrigação de comprar ou de vender o ativo-objeto
                    </CardBody>
                  </Card>

                  <Card id="cardCall">
                    <CardBody>
                      <h4>Calld</h4>
                      É o tipo de opção que dá ao titular o direito de comprar o ativo-objetivo pelo preço prefixado na data de vencimento
                    </CardBody>
                  </Card>

                  <Card id="cardPut">
                    <CardBody>
                      <h4>Put</h4>
                      É o tipo de opção que dá ao titular o direito de vender o ativo-objetivo pelo preço prefixado na data de vencimento
                    </CardBody>
                  </Card>

                  <Card id="cardTicker">
                    <CardBody>
                      <h4>Nomes das opções (Ticker)</h4>
                      Identificam a opção, as quatro primeiras letras descrevem o ativo-objeto, a quinta letra representa o tipo de opção e a data de vencimento: de A até L representam opção de Call, com vencimentos de janeiro a dezembro na ordem das letras; de M até X são as opções de Put, com vencimentos de janeiro a dezembro na ordem das letras.
                    </CardBody>
                  </Card>

                  <Card id=" cardStrike">
                    <CardBody>
                      <h4>Strike</h4>
                      É o preço de exercício, valor prefixado da opção no contrato e que não se altera com a mudança de valor do ativo-objeto
                    </CardBody>
                  </Card>

                  <Card id="cardCota">
                    <CardBody>
                      <h4>Cota</h4>
                      Refere-se ao prêmio da opção.
                    </CardBody>
                  </Card>

                  <Card id="cardGreeks">
                    <CardBody>
                      <h4>Variáveis de Estratégia (Greeks): </h4>
                      São métricas para a visualização dos valores das opções, representadas por letras gregas (por isso greeks).
                    </CardBody>
                  </Card>

                  <Card id="cardDelta">
                    <CardBody>
                      <h4>Delta</h4>
                      É a mudança no preço da Opção em relação à alteração no preço da ação-objeto.
                    </CardBody>
                  </Card>

                  <Card id="cardGama">
                    <CardBody>
                      <h4>Gama</h4>
                      É a taxa da variação do Delta em referência ao deslocamento do preço da ação
                    </CardBody>
                  </Card>

                  <Card id="cardTheta">
                    <CardBody>
                      <h4>Theta</h4>
                      É a taxa de desvalorização de uma Opção ao longo do tempo, à medida que ela se aproxima da data de exercício
                    </CardBody>
                  </Card>

                  <Card id=" cardVega">
                    <CardBody>
                      <h4>Vega</h4>
                      É a taxa da mudança do valor da Opção em relação a uma mudança na volatilidade
                    </CardBody>
                  </Card>

                  <Card id="cardRho">
                    <CardBody>
                      <h4>Rho</h4>
                      É a variação no preço da Opção se houver uma mudança na taxa de juros.
                    </CardBody>
                  </Card>

                  <Card id="cardRatio">
                    <CardBody>
                      <h4>Hedge Ratio</h4>
                      O Índice de hedge é resultante da quantidade do item protegido que a entidade efetivamente protege e a quantidade do instrumento de hedge que a entidade efetivamente utilizada para proteger essa quantidade do item protegido.
                    </CardBody>
                  </Card>

                  <Card id="cardOperacaoEstruturada">
                    <CardBody>
                      <h4>Operação estruturada</h4>
                      É a combinação de duas ou mais opções com um objetivo específico. Essa estrutura estabelece diferentes cenários de acordo com as combinações de opções, como pior cenário de perda, maior ganho ou menor risco.
                    </CardBody>
                  </Card>

                  <Card id="cardGrade">
                    <CardBody>
                      <h4>Grade de Opções</h4>
                      É o Relatório de diversas opções selecionadas por um filtro.
                    </CardBody>
                  </Card>

                  <Card id=" cardOpçõesFicticias">
                    <CardBody>
                      <h4>Opções Fictícias</h4>
                      São opções não reais, para fins de comparação e planejamento em uma estrutura de operação.
                    </CardBody>
                  </Card>

                  <Card id=" cardOpçõesExpiradas">
                    <CardBody>
                      <h4>Opções expiradas</h4>
                      São opções que já passaram da data de vencimento
                    </CardBody>
                  </Card>

                  <Card id="cardPayoff">
                    <CardBody>
                      <h4>Gráfico de Payoff</h4>
                      É um gráfico que representa a relação entre o valor da opção e o valor atual do ativo-objeto, usado para visualizar o lucro/perda na opção. O gráfico pode ser invertido entre o titular e o lançador da opção.
                    </CardBody>
                  </Card>

                  <Card id="cardTestes">
                    <CardBody>
                      <h4>Testes de composição de operação</h4>
                      Teste de cenário de uma operação estruturada de opções para validação de possível eficácia.
                    </CardBody>
                  </Card>

                  <Card id="cardDiarioTransacoes">
                    <CardBody>
                      <h4>Diário de transações</h4>
                      É o histórico de operações executadas em uma opção no dia, contendo valores de preço, volume financeiro e quantidade referentes a negociações de um determinado papel.
                    </CardBody>
                  </Card>

                  <Card id="cardIntriseco">
                    <CardBody>
                      <h4>Valor Intrínseco</h4>
                      É o valor imediato de uma opção em relação ao preço do ativo-objeto, independente de outros fatores como juros e tempo restante para o vencimento do contrato. O valor intrínseco está relacionado apenas a vantagem imediata que este contrato proporciona ao investidor titular da opção.
                    </CardBody>
                  </Card>

                </Col>
              </Row>
            </Container>
          </div>
        </React.Fragment>
      );
    }
  }
  
  export default Glossary;