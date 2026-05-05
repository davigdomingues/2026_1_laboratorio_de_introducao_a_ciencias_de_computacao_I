#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int Nf = 0, Nm = 0, soma_idades_homens_exp = 0, qtd_homens_exp = 0, homens_maior_45 = 0, mulheres_menor_21_exp = 0, NL = 0, NP = 0, NE = 0;

    for (int k = 0; k < N; k++) {
        int idade;
        char sexo, area, exp;
        scanf("%d %c %c %c", &idade, &sexo, &area, &exp);

        if (sexo == 'F') { // se o sexo for feminino
            Nf++; // incrementa a quantidade de mulheres

            if (idade < 21 && exp == 'S') // se a idade for menor que 21 e o experiencia for sim
                mulheres_menor_21_exp++;
        } 
        
        else if (sexo == 'M') { // se o sexo for masculino
            Nm++; // incrementa a quantidade de homens

            if (idade > 45) // se a idade for maior que 45
                homens_maior_45++;

            if (exp == 'S') { // se o experiencia for sim
                soma_idades_homens_exp += idade;
                qtd_homens_exp++; // incrementa a quantidade de homens com experiencia sim 
            }
        }

        if (area == 'L') // se a area for livre
            NL++; // incrementa a quantidade de areas livres

        else if (area == 'P') // se a area for privada
            NP++; // incrementa a quantidade de areas privadas

        else if (area == 'E') // se a area for empresarial
            NE++; // incrementa a quantidade de areas empresariais
    }

    int Mm = 0; // media de idade dos homens com experiencia sim
    if (qtd_homens_exp > 0) // se a quantidade de homens com experiencia sim for maior que 0
        Mm = soma_idades_homens_exp / qtd_homens_exp;  // divisao inteira: arredonda para baixo

    double Pm = 0.0; // porcentagem de homens maior que 45 de forma decimal
    if (Nm > 0)
        Pm = (homens_maior_45 * 100.0) / Nm; // calcula a porcentagem de homens maior que 45

    printf("%d\n", Nf);
    printf("%d\n", Nm);
    printf("%d\n", Mm);
    printf("%.2lf%%\n", Pm);
    printf("%d\n", mulheres_menor_21_exp);
    printf("%d %d %d\n", NL, NP, NE);

    return 0;
}