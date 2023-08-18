package Atividades;
import java.util.Scanner;

public class TrianguloPrincipal {
    public static void main(String a []){
        Scanner ler = new Scanner(System.in);
        Triangulo [] triangulos = new Triangulo[10];
        int contTri = 0;

        int opcao;

        do{
            System.out.println("Menu de opções");
            System.out.println("(1) - Inserir triângulo");
            System.out.println("(2) - Mostrar triaângulos cadastrados");
            System.out.println("(3) - Mostrar o número de triângulos equiláteros");
            System.out.println("(4) -  Mostra o triângulo com maior perímetro");
            System.out.println("(0) - Sair");
            opcao = ler.nextInt();
        
        switch (opcao) {
            case 1:
            if(contTri < 10){
                triangulos[contTri] = new Triangulo();
                System.out.println("Digite o valor do lado1");
                triangulos[contTri].setLado1(ler.nextInt());
                System.out.println("Digite o valor do lado2");
                triangulos[contTri].setLado2(ler.nextInt());
                System.out.println("Digite o valor do lado3");
                triangulos[contTri].setLado3(ler.nextInt());
                contTri++;
            }
            else{
                System.out.println("Nao eh possivel cadastrar mais triângulos");
            }                
                break;
            case 2:
            for(int i=0; i<contTri; i++){
                System.out.print("Triângulo " + (i + 1) + ": ");
                System.out.print("Lado1: " + triangulos[i].getLado1());
                System.out.print(" Lado2: " + triangulos[i].getLado2());
                System.out.println(" Lado3: " + triangulos[i].getLado3());
            }
                break;
            case 3:
            int eq = 0;
        
            for(int i=0; i<contTri; i++){
                if(triangulos[i].tipoTriangulo() == "Equilatero"){
                    eq++;
                }
            }
            System.out.println("A quantidade de triângulos equilateros eh: " + eq);
                break;

            case 4:                    
            int maxPerimetro = 0;
            int perimetro = 0;
            int indiceaux = -1;
            for(int i=0; i<contTri; i++){
                perimetro = triangulos[i].calcularPerimetro();
                if(perimetro > maxPerimetro){
                    maxPerimetro = perimetro;
                    indiceaux = i;
                }
            }

            if(indiceaux != -1){
                System.out.print("O maior Triangulo: " + (indiceaux + 1) + ": ");
                System.out.print("Lado1: " + triangulos[indiceaux].getLado1());
                System.out.print(" Lado2: " + triangulos[indiceaux].getLado2());
                System.out.print(" Lado3: " + triangulos[indiceaux].getLado3());
                System.out.println(" Perimetro:" + maxPerimetro);                
            }
            else{
                System.out.println("Nao ha triangulos cadastrados");
            break;
            }
            
        }        
        }while(opcao != 0);
        ler.close();
    }
}

