package exercicio_1;

public class Calculadora {
    //atributos
    private int num1;
    private int num2;

    //metodos
    public Calculadora(int num1, int num2){
        this.num1 = num1;
        this.num2 = num2;
    }
    public int soma(){
        return num1 + num2;
    }
    public int subtracao(){
        return num1 - num2;
    }
    public int multiplicacao(){
        return num1 * num2;
    }
    public int divisao(){
        return num1 / num2;
    }

    //getters e setters
    public int getNum1(){
        return num1;
    }
    public void setNum1(int num1){
        this.num1 = num1;
    }
    public int getNum2(){
        return num2;
    }
    public void setNum2(int num2){
        this.num2 = num2;
    }

}
