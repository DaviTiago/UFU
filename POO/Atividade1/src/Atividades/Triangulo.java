package Atividades;

public class Triangulo {
    int lado1;
    int lado2;
    int lado3;
    

    public void setLado1(int lado1) {
        this.lado1 = lado1;
    }

    public void setLado2(int lado2) {
        this.lado2 = lado2;
    }

    public void setLado3(int lado3) {
        this.lado3 = lado3;
    }

    public int getLado1() {
        return lado1;
    }

    public int getLado2() {
        return lado2;
    }

    public int getLado3(){
        return lado3;
    }

    public String tipoTriangulo() {
        if (lado1 == lado2 && lado2 == lado3){
            return "Equilatero";
        }
        else if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3){
            return "Isoceles";
        }
        else {
            return "Escaleno";} 
    }

    public int calcularPerimetro(){
        return lado1 + lado2 + lado3;
    }
}