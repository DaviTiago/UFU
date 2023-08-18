package Atividades;
import java.util.Scanner;


public class SomaDoisNumeros { 
    public static void main(String a []) {
        Scanner ler = new Scanner(System.in);
        System.out.println("Digite o primeiro número:");
        int n1 = ler.nextInt();
        System.out.println("Digite o segundo número:");
        int n2 = ler.nextInt();
        int soma = n1 + n2;
     System.out.println("A soma eh: " + soma);   
    
        ler.close();
    }
    
}
