//Nama : Daffa Rafandy Tarigan
//NIM : 13224068
//Praktikum Modul 3 - Structure and Dynamic Arrays
// Modul 3 Soal Nomor Satu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Penjaga {
    char nama[100];
    int id;
    char shift[10];
    int skor;
} Penjaga;

// Buat nentuin siapa yang lebih baik
int lebihBaik(Penjaga a, Penjaga b) {
    if (a.skor != b.skor) return a.skor > b.skor;         
    if (a.id != b.id) return a.id < b.id;                  
    return strcmp(a.nama, b.nama) < 0;                      
}

int main() {
    int N;
    scanf("%d", &N);

    Penjaga *arr = (Penjaga*) malloc(N * sizeof(Penjaga));

    for (int i = 0; i < N; i++) {
        scanf("%s %d %s %d", arr[i].nama, &arr[i].id, arr[i].shift, &arr[i].skor);
    }

    Penjaga pagi, siang, malam;
    int yangPagi = 0, yangSiang = 0, yangMalam = 0;

    for (int i = 0; i < N; i++) {
        if (strcmp(arr[i].shift, "PAGI") == 0) {
            if (!yangPagi || lebihBaik(arr[i], pagi)) {
                pagi = arr[i];
                yangPagi = 1;
            }
        }
        else if (strcmp(arr[i].shift, "SIANG") == 0) {
            if (!yangSiang || lebihBaik(arr[i], siang)) {
                siang = arr[i];
                yangSiang = 1;
            }
        }
        else if (strcmp(arr[i].shift, "MALAM") == 0) {
            if (!yangMalam || lebihBaik(arr[i], malam)) {
                malam = arr[i];
                yangMalam = 1;
            }
        }
    }

    if (yangPagi)
        printf("PAGI %s %d %d\n", pagi.nama, pagi.id, pagi.skor);
    else
        printf("PAGI -\n");

    if (yangSiang)
        printf("SIANG %s %d %d\n", siang.nama, siang.id, siang.skor);
    else
        printf("SIANG -\n");
    if (yangMalam)
        printf("MALAM %s %d %d\n", malam.nama, malam.id, malam.skor);
    else
        printf("MALAM -\n");

    free(arr);
return 0;
}
