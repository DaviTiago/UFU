package Atividades;
import java.util.Scanner;

public class PontoPrincipal {
    public static void main (String a[]){
        Scanner ler = new Scanner(System.in);
        
        Ponto ponto1 = new Ponto();
        Ponto ponto2 = new Ponto();
        
        System.out.println("Digite o valor de X1");
        ponto1.setX(ler.nextDouble());
        System.out.println("Digite o valor de Y1");
        ponto1.setY(ler.nextDouble());
        System.out.println("Digite o valor de X2");
        ponto2.setX(ler.nextDouble());
        System.out.println("Digite o valor de Y2");
        ponto2.setY(ler.nextDouble());
        
        System.out.println("Distância eh: " + ponto1.calcularDistanciaEuclidiana(ponto2));


        ler.close();        
    }
   
}
