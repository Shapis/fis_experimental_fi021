#include <stdio.h>
#include <math.h>

int main()
{
    int sequenciaLength;
    float media, incertezaMedida, incertezaMedia, incertezaInstrumental, incertezaTotalMedida, incertezaTotalMedia;

    printf("Digite a quantidade de medidas que voce tem:\n");
    scanf("%d", &sequenciaLength);

    float sequencia[sequenciaLength];

    printf("Digite as suas medidas uma por uma:\n");

    for (size_t i = 0; i < sequenciaLength; i++)
    {
        scanf("%f", &sequencia[i]);
    }

    for (size_t i = 0; i < sequenciaLength; i++)
    {
        media += sequencia[i] / sequenciaLength;
        incertezaMedida += pow(sequencia[i], 2) / sequenciaLength;
    }

    incertezaMedida -= pow(media, 2);

    incertezaMedia = incertezaMedida / sqrt(sequenciaLength);

    printf("A media das medidas: %f\nA incerteza da medida: %f\nA incerteza da media: %f\n", media, incertezaMedida, incertezaMedia);

    printf("Digite a incerteza instrumental. See nao tiver digite ela digite 0\n");

    scanf("%f", &incertezaInstrumental);

    incertezaTotalMedida = sqrt(pow(incertezaMedida, 2) + pow(incertezaInstrumental, 2));
    incertezaTotalMedia = sqrt(pow(incertezaMedia, 2) + pow(incertezaInstrumental, 2));
    printf("A incerteza instrumental eh: %f\nA incerteza total da medida: %f\nA incerteza total da media: %f\n", incertezaInstrumental, incertezaTotalMedida, incertezaTotalMedia);

    printf("Programa concluido com sucesso!\n");

    return 0;
}