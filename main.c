#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 13220029 / Fariz Iftikhar Falakh
// Program pengecekan jenis file dengan melihat hex signature dari file tersebut
// Jenis File yang dapat dicek oleh program ini adalah : pdf, pptx/docx/xlsx, dan png.
// Catatan : Pada penampilan karakter pertama dari hex signature file png, terdapat sedikit error di mana tercetak beberapa huruf f sebelum
//           penampilan karakter. Hal ini disebabkan oleh kesalahan saat membaca nilai integer dri karakter hex 89, di mana program menampilkan angka
//           -119.


int main()
{
    char ch, file_name[25];
    int tipe_file[8];
    FILE *fp;

    printf("Jenis file yang dapat dicek jenisnya oleh program ini adalah\n");
    printf("1. docx, xlsx, pptx\n2. pdf\n3. png\n");
    printf("Silakan masukkan nama file yang ingin diketahui jenisnya : \n");
    fgets(file_name, sizeof(file_name), stdin);
    file_name[strlen(file_name)-1] = 0x00;
    fp = fopen(file_name,"rb");

    if( fp == NULL )
    {
        perror("Error saat membuka file.\n");
        exit(EXIT_FAILURE);
    }

    int i=0;
    while (i != 8)
    {
        ch = fgetc(fp);
        tipe_file[i] = ch;
        i++;
    }

    printf("\n8 karakter pertama hex signature file ini adalah : \n");
    int j = 0;
    while(j != 8)
    {
        printf("%02X ",tipe_file[j]);
        j++;
    }
    fclose(fp);

    if (tipe_file[0] == 80 && tipe_file[1] == 75 && tipe_file[2] == 3 && tipe_file[3] == 4)
    {
        printf("\nTipe file adalah : xlsx / pptx / docx\n");
    }
    else if (tipe_file[0] == 37 && tipe_file[1] == 80 && tipe_file[2] == 68 && tipe_file[3] == 70)
    {
        printf("\nTipe file adalah : pdf\n");
    }
    else if (tipe_file[1] == 80 && tipe_file[2] == 78 && tipe_file[3] == 71)
    {
        printf("\nTipe file adalah : png\n");
    }
    else
    {
        printf("\nTipe file tidak diketahui\n");
    }

    return 0;
}
