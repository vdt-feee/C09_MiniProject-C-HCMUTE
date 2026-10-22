// File: main.c
#include <stdio.h>
#include "rapphim.h"

int main() {
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
            printf("2. Dat mot hoac nhieu ghe\n");
            printf("3. Huy ve\n");
            printf("4. Tinh tien va in ve\n");
            printf("5. Thong ke doanh thu, ti le lap day\n");
            printf("6. Goi y day ghe trong lien nhau\n");
            printf("0. Thoat chuong trinh\n");
            printf("9. Reset lai So Do Rap \n");
            printf("=========================================\n");
            printf("Moi ban chon chuc nang (0-6 || 9): ");

            kiem_tra = scanf("%d", &chon);
            if (kiem_tra == 0) {
                while(getchar() != '\n');
                chon = -1;
            }

            switch(chon) {
                case 1:
                    HienThiSoDo(so_do_rap);
                    break;

                case 2:
                // Cộng dồn tiền vé nếu khách mua thêm
                tien_ve += DatVe(so_do_rap);
                LuuFileSoDo(so_do_rap);
                if (tien_ve > 0) {
                    printf("\n*** Hoa don hien tai cua ban la: %.0f d ***\n", tien_ve);
                    printf("-> Vui long chon muc 4 de in hoa don khi hoan tat \n");
                }
                break;

            case 3:
                // Trừ đi số tiền khách vừa hủy
                tien_ve -= HuyVe(so_do_rap);

                // Chốt chặn an toàn: Tránh trường hợp tiền vé bị âm
                // (VD: Khách hủy vé của người khác mua trước đó)
                if (tien_ve < 0) {
                    tien_ve = 0;
                }
                LuuFileSoDo(so_do_rap);
                break;

                case 4:
                    if (tien_ve > 0) {
                        InHoaDon(tien_ve);
                        tien_ve = 0; // Reset lại tien_ve sau khi in xong để tránh in lặp lại
                    } else {
                        printf("-> Ban chua dat ve moi hoac da in hoa don roi!\n");
                    }
                    break;

                case 5:
                    ThongKeRapPhim(so_do_rap);
                    break;

                case 6:
                    N_GheLienNhau(so_do_rap);
                    break;

                case 9:
                    // ResetRapPhim(so_do_rap);
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 10; j++) {
                            so_do_rap[i][j] = 0; // Ep toan bo mang ve 0
                        }
                    }
                    printf("-> Da don dep rap sach se. Toan bo ghe da tro ve trang thai TRONG!\n");
                    break;
                case 0:
                    printf("Tam biet! Chuong trinh dang duoc dong lai...\n");
                    break;

                default:
                    printf("Loi: Lua chon khong hop le. Vui long nhap tu 0 den 6!\n");
            }
        } while (chon != 0);

    return 0;
}
