package Atividades;

public class Ponto {
    double x;
    double y;

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY(){
        return y;
    }

    public double calcularDistanciaEuclidiana(Ponto p){
        double distancia = Math.sqrt(Math.pow((p.getX() - this.x), 2) + Math.pow((p.getY() - this.y), 2));
        return distancia;
    }
    
}
