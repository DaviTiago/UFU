package Atividades;
import java.util.Scanner;

public class ClientePrincipal {
    public static void main(String a[]){
        Scanner ler = new Scanner(System.in);

        Cliente cliente = new Cliente();
        System.out.println("Digite o nome:");
        String nome = ler.nextLine();
        System.out.println("Digite o CPF:");
        String cpf = ler.nextLine();
        System.out.println("Digite a idade:");
        int idade = ler.nextInt();
        System.out.println("Digite o telefone:");
        ler.nextLine();
        String telefone = ler.nextLine();
        
        cliente.cadastrarCliente(nome, cpf, idade, telefone);

        System.out.println("\nDados do cliente: " );        
        System.out.println(cliente.mostrarDadosCliente());
        
        ler.close();
    
    }

    
}
