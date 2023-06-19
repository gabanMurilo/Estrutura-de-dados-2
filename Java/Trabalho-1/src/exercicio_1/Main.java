package exercicio_1;

public class Main {
    public static void main(String[] args) {
        Calculadora calc = new Calculadora(10, 2);
        System.out.println("Soma: " + calc.soma());
        System.out.println("Subtração: " + calc.subtracao());
        System.out.println("Multiplicação: " + calc.multiplicacao());
        System.out.println("Divisão: " + calc.divisao());

        calc.setNum1(20);
        calc.setNum2(4);
        System.out.println("Soma: " + calc.soma());
        System.out.println("Subtração: " + calc.subtracao());
        System.out.println("Multiplicação: " + calc.multiplicacao());
        System.out.println("Divisão: " + calc.divisao());

        calc.setNum1(30);
        calc.setNum2(6);
        System.out.println("Soma: " + calc.soma());
        System.out.println("Subtração: " + calc.subtracao());
        System.out.println("Multiplicação: " + calc.multiplicacao());
        System.out.println("Divisão: " + calc.divisao());

    }
}
