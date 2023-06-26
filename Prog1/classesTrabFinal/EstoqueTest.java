public class EstoqueTest {
    public static void main(String[] args) {
        Estoque estoque = new Estoque();

        // Realize as operações de teste aqui
        // Inserir produtos, remover produtos, buscar produtos, etc.

        // Exemplo: inserir um produto
        Produto produto1 = new Produto();
        produto1.setNome("Produto 1");
        produto1.setQuantidade("10");
        estoque.inserirProduto(produto1);

        // Exemplo: buscar um produto
        Produto produtoEncontrado = estoque.buscarProduto("Produto 1");
        if (produtoEncontrado != null) {
            System.out.println("Produto encontrado: " + produtoEncontrado.getNome());
        } else {
            System.out.println("Produto não encontrado.");
        }
    }
}
