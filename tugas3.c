// Nama: Elmo Ryaner Panggabean
// NIM : 13220012
// C program untuk mengetahui jenis file (JPEG/PDF)

#include <ctype.h>
#include <stdio.h>
#include <string.h>


// Algoritma

int main()
{
    // Judul
    printf("PDF/JPEG File Checker\n\n");

    FILE * fp;
    char fname[100] = "";

    // User menginput file path secara manual
    printf("Enter the file path: \n");
    scanf("%s",&fname);

    // File akan dibuka dan dibaca
    FILE* file = fopen(fname, "r");

    // Jika file adalah NULL akan menampilkan pesan
    if (file == NULL)
        {
            printf("No such file.");
            return 1;
        }

    // Array untuk menyimpan empat byte pertama
    unsigned char bytes[3];

    // Membaca empat byte pertama dalam file
    fread(bytes, 3, 1, file);

    // Jika file adalah JPEG
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
        {
            printf("This Image is in JPEG format!");
        }

    // Jika file adalah PDF
    else if (bytes[0] == 0x25 && bytes[1] == 0x50 && bytes[2] == 0x44)
        {
            printf("This file is in PDF format!");
        }

    // Jika file bukan JPEG ataupun PDF
    else
        {
            printf("Cannot identify file format.");
        }

    return 0;
}
