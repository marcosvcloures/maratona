import java.io.*;
import java.util.*;

public class setun {
	public static void main(String args[]) {
		int n, i, qtd, numero[];
		long valores[] = new long[30], soma[] = new long[30];
		Scanner leitor = new Scanner(System.in);
		
		valores[0] = soma[0] = 1;
		for(i = 1; i < 30; i++) {
			valores[i] = 3*valores[i-1];
			soma[i] = soma[i-1] + valores[i];
		}
		
		while(leitor.hasNext()) {
			n = leitor.nextInt();
			qtd = 0;
			numero = new int[30];
			
			for(i = 0; i < 30; i++)
				if(soma[i] >= Math.abs(n))
					break;
			
			qtd = i;
			
			while(n != 0)
				for(i = 0; i < 30; i++)
					if(soma[i] >= Math.abs(n)) {
						numero[i] = n < 0 ? -1 : n > 0 ? 1 : 0;
						n -= numero[i] * valores[i];
						break;
					}
			
			for(; qtd >= 0; qtd--)
				System.out.printf("%c", numero[qtd] == -1 ? '-' : numero[qtd] == 0 ? '0' : '+');
			
			System.out.print('\n');
		}
	}
}
