// Phan Quang Thành, Mã số sinh viên: 26119188


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "rapphim.h"

float DatVe(int so_do[8][10]) {
    int so_luong;
    float tong_tien = 0;
    int kiem_tra;

    printf("\n--- DAT VE XEM PHIM ---\n");

    // 1. Hỏi người dùng muốn đặt bao nhiêu ghế và bắt lỗi nhập liệu
    do {
        printf("Ban muon dat bao nhieu ghe? (Toi da 80, go '0' de thoat): ");
        kiem_tra = scanf("%d", &so_luong);

        if (kiem_tra == 0) {
            printf("Loi: Ban da nhap chu. Vui long nhap so!\n");
            while(getchar() != '\n'); // Hút rác bàn phím
        } else if (so_luong < 0 || so_luong > 80) {
            printf("Loi: So luong ghe khong hop le!\n");
        }
    } while (kiem_tra == 0 || so_luong < 0 || so_luong > 80);

    // Xử lý phím 0 để thoát ngay từ đầu
    if (so_luong == 0) {
        printf("-> Da thoat chuc nang dat ve.\n");
        return 0; // Trả về 0 đồng cho main.c
    }

    // 2. Vòng lặp cho phép chọn từng ghế
    for (int i = 0; i < so_luong; i++) {
        char toa_do[10]; // Mảng chuỗi A10 -> Chuỗi, số 10 đằng sau A nó cũng vẫn là chuỗi
        int r, c, hop_le = 0; // r = row, c = column

        do {
            printf("Nhap toa do ghe thu %d (VD: A5) hoac go '0' de dung: ", i + 1);
            scanf("%s", toa_do);

            // Xử lý phím 0 để dừng đặt vé giữa chừng
            if (toa_do[0] == '0') {
                printf("-> Da dung qua trinh dat ve. Cac ghe da chon se duoc giu lai.\n");
                goto KetThucDatVe; // Nhảy thẳng xuống phần tính tổng tiền ở cuối hàm
            }
            // Thuật toán dịch tọa độ
            char hang = toupper(toa_do[0]); // a10 -> A10
            int cot = atoi(&toa_do[1]);
            r = hang - 'A'; // bien thành số int, ASCII 65
    //  int r = 'B' - 'A' => Số int; 66 - 65 = 1 => 1 sẽ là số nguyên
            c = cot - 1;

            // Bắt lỗi tọa độ
            if (r < 0 || r > 7 || c < 0 || c > 9) {
                printf("Loi: Toa do khong ton tai! Hang phai tu A-H, Cot phai tu 1-10.\n");
            } else if (so_do[r][c] == 1) {
                printf("Loi: Ghe %s da co nguoi dat roi. Vui long chon ghe khac!\n", toa_do);
            } else {
                hop_le = 1; // Hợp lệ, cho qua
            }
        } while (hop_le == 0);

        // 3. Cập nhật mảng và Tính tiền
        so_do[r][c] = 1; // Đánh dấu là đã đặt
        float gia_ve = (r == 6 || r == 7) ? 100000.0 : 70000.0;
        tong_tien += gia_ve;

        printf("-> Dat thanh cong ghe %c%d (Gia: %.0f d)\n", toupper(toa_do[0]), atoi(&toa_do[1]), gia_ve);
    }

KetThucDatVe:
    printf("------------------------------------------\n");
    printf("Tong tien cho cac ghe vua dat: %.0f d\n", tong_tien);

    return tong_tien;
}
