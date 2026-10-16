#include <stdio.h>
#include "rapphim.h"

int main() {
    // Khoi tao mang 2 chieu quan ly 80 ghe ngoi
    int so_do_rap[8][10];

    int chon;
    int kiem_tra;
    float tien_ve = 0; // Bien dung de chuyen tien tu ham DatVe sang ham InHoaDon

    // BUOC 1: Phuc hoi tri nho tu o cung vao RAM truoc khi lam viec
    DocFileSoDo(so_do_rap);

    do {
        printf("\n=========================================\n");
        printf("        PHAN MEM QUAN LY RAP PHIM        \n");
        printf("=========================================\n");
        printf("1. Hien thi so do ghe\n");
        printf("2. Dat ve xem phim (va In hoa don)\n");
        printf("3. Huy ve\n");
        printf("4. Thong ke doanh thu va ti le lap day\n");
        printf("5. Goi y day ghe trong lien nhau\n");
        printf("0. Thoat chuong trinh\n");
        printf("=========================================\n");
        printf("Moi ban chon chuc nang (0-5): ");

        // Bat loi nhap chu
        kiem_tra = scanf("%d", &chon);
        if(kiem_tra == 0) {
            while(getchar() != '\n');
            chon = -1; // Ep ve -1 de lot vao case default bao loi
        }

        switch(chon) {
            case 1:
                HienThiSoDo(so_do_rap);
                break;

            case 2:
                // Tinh tien -> In hoa don -> Luu ngam xuong o cung
                tien_ve = DatVe(so_do_rap);
                InHoaDon(tien_ve);
                LuuFileSoDo(so_do_rap);
                break;

            case 3:
                // Huy ve -> Luu ngam xuong o cung
                HuyVe(so_do_rap);
                LuuFileSoDo(so_do_rap);
                break;

            case 4:
                ThongKeRapPhim(so_do_rap);
                break;

            case 5:
                N_GheLienNhau(so_do_rap);
                break;

            case 0:
                printf("Tam biet \n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long nhap tu 0 den 5!\n");
        }
    } while(chon != 0);

    return 0;
}
