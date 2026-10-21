// // Trần Ngọc Thắng, Mã số sinh viên: 26119192


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "rapphim.h"

float HuyVe(int so_do[8][10]) {
    char toa_do[10];
    int r, c, hop_le = 0;
    char hang;
    int cot;

    printf("\n--- HUY VE XEM PHIM ---\n");

    do {
        printf("Nhap toa do ghe muon huy (VD: A5) hoac go '0' de thoat: ");
        scanf("%s", toa_do);

        if (toa_do[0] == '0') {
            printf("-> Da thoat chuc nang huy ve.\n");
            return 0; // Trả về 0 đồng
        }

        hang = toupper(toa_do[0]);
        cot = atoi(&toa_do[1]);
        r = hang - 'A';
        c = cot - 1;

        if (r < 0 || r > 7 || c < 0 || c > 9) {
            printf("Loi: Toa do khong ton tai!\n");
        } else if (so_do[r][c] == 0) {
            printf("Loi: Ghe %s hien dang TRONG, ban khong the huy!\n", toa_do);
        } else {
            hop_le = 1;
        }
    } while (hop_le == 0);

    so_do[r][c] = 0;

    // Tính số tiền bị hủy để trả lại cho khách
    float tien_hoan = (r == 6 || r == 7) ? 100000.0 : 70000.0;

    printf("-> Da huy thanh cong ghe %c%d.\n", hang, cot);
    printf("-> So tien duoc khau tru (hoan lai): %.0f d\n", tien_hoan);

    return tien_hoan; // Quăng cục tiền này về cho main.c xử lý
}
